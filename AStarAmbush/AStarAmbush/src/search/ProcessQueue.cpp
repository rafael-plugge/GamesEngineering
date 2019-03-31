#include "stdafx.hpp"
#include "ProcessQueue.hpp"

app::sea::ProcessQueue::ProcessQueue()
	: m_start(true)
	, m_mainTaskThread()
	, m_workerThreads()
	, m_tasks()
	, m_taskInsertionMutex()
	, m_newTaskMutex()
	, m_newTaskSignal()
	, m_searchingMutex()
{
}

app::sea::ProcessQueue::~ProcessQueue()
{
	m_start = false;
	while (!m_tasks.empty()) { m_tasks.pop(); }
	for (auto & workerThread : m_workerThreads)
	{
		workerThread.terminate = true;
		if (workerThread.thread.has_value())
		{
			workerThread.processSignal.notify_all();
			if (workerThread.thread->joinable()) { workerThread.thread->join(); }
			workerThread.thread.reset();
		}
	}
	m_newTaskSignal.notify_all();
	if (m_mainTaskThread.has_value())
		if (m_mainTaskThread->joinable())
			m_mainTaskThread->join();
}

void app::sea::ProcessQueue::init()
{
	for (auto & workerThread : m_workerThreads)
		workerThread.thread.emplace(this->constructWorkerThread(workerThread));
	m_mainTaskThread.emplace(&app::sea::ProcessQueue::mainTaskThread, this);
	app::cout::wl({ "Created main task thread[", m_mainTaskThread->get_id(), "]" });
}

void app::sea::ProcessQueue::push(std::packaged_task<void()> task)
{
	auto const lockGuard = std::lock_guard<std::mutex>(m_taskInsertionMutex);
	m_tasks.push(std::move(task));
	m_newTaskSignal.notify_all();
}

void app::sea::ProcessQueue::mainTaskThread()
{
	while (m_start)
	{
		auto newTaskLock = std::unique_lock<std::mutex>(m_newTaskMutex);
		m_newTaskSignal.wait(newTaskLock, [this]() { return !m_tasks.empty() || !m_start; });
		while (!m_tasks.empty())
		{
			auto const workerCheckPredicate = [&](WorkerThread & worker)
			{
				if (!worker.processing)
				{
					worker.processing = true;
					return true;
				}
				return false;
			};
			auto lockGuard = std::lock_guard<std::mutex>(m_searchingMutex);
			if (auto const & result = std::find_if(m_workerThreads.begin(), m_workerThreads.end(), workerCheckPredicate); result != m_workerThreads.end())
			{
				// found non-processing thread.

				auto taskContainer = std::optional<std::packaged_task<void()>>();
				{
					auto const lockGuard = std::lock_guard<std::mutex>(m_taskInsertionMutex);
					taskContainer = std::move(m_tasks.front());
					m_tasks.pop();
				}
				auto & workerThread = *result;

				workerThread.task.reset();
				workerThread.task.swap(taskContainer);
				workerThread.processSignal.notify_one();
			}
		}
	}
}

void app::sea::ProcessQueue::workerThreadFunction(app::sea::ProcessQueue::WorkerThread & workerData)
{
	auto workerMutex = std::mutex();
	auto workerLock = std::unique_lock<decltype(workerMutex)>(workerMutex);
	while (true)
	{
		workerData.processSignal.wait(workerLock);
		if (workerData.terminate) { break; }
		workerData.task.value()();
		workerData.processing = false;
	}
	if (workerData.task.has_value()) { workerData.task.reset(); }
	workerData.processing = false;
}

std::thread app::sea::ProcessQueue::constructWorkerThread(app::sea::ProcessQueue::WorkerThread & workerData)
{
	return std::move(std::thread(&app::sea::ProcessQueue::workerThreadFunction, this, std::ref(workerData)));
}
