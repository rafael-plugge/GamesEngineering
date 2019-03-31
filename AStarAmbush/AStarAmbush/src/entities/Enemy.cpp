#include "stdafx.hpp"
#include "Enemy.hpp"
#include "singletons/KeyHandlerSingleton.hpp"
#include "singletons/ProcessQueueSingleton.hpp"

std::optional<app::ent::Player const * const> app::ent::Enemy::s_target = std::nullopt;

app::ent::Enemy::Enemy()
	: m_keyHandler(app::sin::KeyHandler::get())
	, m_processQueue(app::sin::ProcessQueue::get())
	, m_seekTarget(false)
	, m_searchTask(std::bind(&app::ent::Enemy::searchPlayer, this))
{
}

app::ent::Enemy::Enemy(Enemy const & other)
	: m_keyHandler(app::sin::KeyHandler::get())
	, m_processQueue(app::sin::ProcessQueue::get())
	, m_seekTarget(other.m_seekTarget.load())
	, m_searchTask(std::bind(&app::ent::Enemy::searchPlayer, this))
{
}

app::ent::Enemy & app::ent::Enemy::operator=(Enemy const & other)
{
	m_seekTarget = other.m_seekTarget.load();
	base::Cell::operator=(other);
	return *this;
}

app::ent::Enemy::Enemy(Enemy && other)
	: m_keyHandler(app::sin::KeyHandler::get())
	, m_processQueue(app::sin::ProcessQueue::get())
	, m_seekTarget(other.m_seekTarget.load())
	, m_searchTask(std::bind(&app::ent::Enemy::searchPlayer, this))
{
}

app::ent::Enemy & app::ent::Enemy::operator=(Enemy && other)
{
	m_seekTarget = std::move(other.m_seekTarget.load());
	base::Cell::operator=(std::move(other));
	return *this;
}

void app::ent::Enemy::setTarget(app::ent::Player const & target)
{
	if (!s_target.has_value()) { s_target.emplace(&target); }
}

void app::ent::Enemy::init()
{
	Cell::init();
	this->setColor(gra::Color{ 255u, 0u, 0u });
	this->moveTo({ 50, 0 });
	m_seekTarget = false;
}

void app::ent::Enemy::init(math::Vector2u const & startingPosition)
{
	this->init();
	this->moveTo(startingPosition);
}

void app::ent::Enemy::update(app::time::seconds const & dt)
{
	assert(s_target.has_value() && m_keyHandler != nullptr);
	if (m_keyHandler->isKeyPressed(SDLK_SPACE))
	{
		m_processQueue->push(std::packaged_task<void()>(m_searchTask));
	}
}

app::ent::Player const & app::ent::Enemy::getTarget()
{
	if (!s_target.has_value()) { throw std::exception("Enemy must have target set when 'getTarget()' is called"); }
	return **s_target;
}

void app::ent::Enemy::searchPlayer()
{
	Player const & player = this->getTarget();
	auto const & seekPosition = player.getGridPosition();
	if (seekPosition.y > getGridPosition().y)
	{
		this->move(0, 1);
	}
}
