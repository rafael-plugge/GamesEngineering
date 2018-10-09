#include "stdafx.h"
#include "State.h"

std::shared_ptr<app::fsm::State> app::fsm::State::s_singlePtr = nullptr;
