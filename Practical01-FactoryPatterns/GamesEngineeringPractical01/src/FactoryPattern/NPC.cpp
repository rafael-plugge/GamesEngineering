#include "stdafx.h"
#include "NPC.h"

app::FactoryPattern::Npc::Npc()
{
	std::cout << "Creating Npc" << std::endl;
}

void app::FactoryPattern::Npc::draw()
{
	std::cout << "Non-player character" << std::endl;
}
