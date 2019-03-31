#pragma once

namespace app::sea
{
	class ProcessQueue
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
		struct WorkerThread
		{
			std::atomic_bool terminate = false;
			std::atomic_bool processing = false;
			std::optional<std::thread> thread;
			std::condition_variable processSignal;
			std::optional<std::packaged_task<void()>> task;
		};
	public: // Constructors/Destructor/Assignments
		ProcessQueue();
		~ProcessQueue();

		ProcessQueue(ProcessQueue const &) = default;
		ProcessQueue & operator=(ProcessQueue const &) = default;

		ProcessQueue(ProcessQueue &&) = default;
		ProcessQueue & operator=(ProcessQueue &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		void init();
		void push(std::packaged_task<void()> task);
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
		void mainTaskThread();
		void workerThreadFunction(app::sea::ProcessQueue::WorkerThread & workerData);
		std::thread constructWorkerThread(app::sea::ProcessQueue::WorkerThread & workerData);
	private: // Private Static Variables
		constexpr static auto NUMBER_WORKER_THREADS = 40;
	private: // Private Member Variables
		std::atomic_bool m_start;
		std::optional<std::thread> m_mainTaskThread;
		std::array<WorkerThread, NUMBER_WORKER_THREADS> m_workerThreads;
		std::queue<std::packaged_task<void()>> m_tasks;
		std::mutex m_taskInsertionMutex;
		
		std::mutex m_newTaskMutex;
		std::condition_variable m_newTaskSignal;

		std::mutex m_searchingMutex;
	};

	static_assert(std::is_default_constructible<ProcessQueue>::value, "ProcessQueue must be default constructible");
	static_assert(std::is_destructible<ProcessQueue>::value, "ProcessQueue must be destructible");
}

