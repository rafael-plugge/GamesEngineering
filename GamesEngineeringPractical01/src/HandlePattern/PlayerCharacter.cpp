#include "stdafx.h"
#include "PlayerCharacter.h"

app::HandlePattern::PlayerCharacter::PlayerCharacter(std::shared_ptr<app::HandlePattern::Window> sptrWindow)
	: Character()
	, _sptrWindow(sptrWindow)
{
}

void app::HandlePattern::PlayerCharacter::Draw()
{
	_sptrWindow->Draw();
}