#include "stdafx.h"
#include "PlayerRunningStateFactory.h"

std::shared_ptr<app::fsm::State> app::fact::PlayerRunningStateFactory::create() const
{
	return std::shared_ptr<app::fsm::State>();
}
