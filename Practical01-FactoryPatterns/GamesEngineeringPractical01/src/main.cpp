#include "stdafx.h"

#include "FactoryPattern/PCharacterFactory.h"
#include "FactoryPattern/NPCFactory.h"

#include "HandlePattern/PlayerCharacter.h"
#include "HandlePattern/Win32Window.h"
#include "HandlePattern/LinuxWindow.h"

#include "ProxyPattern/ITexture.h"
#include "ProxyPattern/TextureLoader.h"

void FactoryPatternDemo()
{
	using namespace app::FactoryPattern;
	std::vector<std::unique_ptr<Drawable>> drawVector;
	
	// Player Character Factory
	std::unique_ptr<Factory> pFactory = std::make_unique<PCharacterFactory>();
	drawVector.push_back(pFactory->Create());
	drawVector.push_back(pFactory->Create());

	// Npc Character Factory
	pFactory = std::make_unique<NpcFactory>();
	drawVector.push_back(pFactory->Create());
	drawVector.push_back(pFactory->Create());
	drawVector.push_back(pFactory->Create());
	drawVector.push_back(pFactory->Create());
	drawVector.push_back(pFactory->Create());

	std::cout << std::endl << "Drawing all drawables" << std::endl << std::endl;
	for (auto const & pDrawable : drawVector)
	{
		pDrawable->draw();
	}
	std::cout << std::endl << "Finished drawing all drawables" << std::endl << std::endl;
}

void HandlePatternDemo()
{
	using namespace app::HandlePattern;

	std::shared_ptr<Window> sptrWindow = std::make_shared<Win32Window>();
	std::unique_ptr<Character> uptrCharacter = std::make_unique<PlayerCharacter>(sptrWindow);
	uptrCharacter->Draw();
	
	sptrWindow = std::make_shared<LinuxWindow>();
	uptrCharacter = std::make_unique<PlayerCharacter>(sptrWindow);
	uptrCharacter->Draw();
}

void ProxyPatternDemo()
{
	using namespace app::ProxyPattern;

	std::unique_ptr<TextureLoader> uptrTextureLoader = std::make_unique<TextureLoader>();
	std::unique_ptr<ITexture> uptrTexture = uptrTextureLoader->create();

	uptrTexture->load();
}

int main()
{
	std::cout << "Starting Application" << std::endl;

	std::cout << std::endl << "////////////////////////////" << std::endl;
	std::cout << "Factory Pattern" << std::endl << std::endl;
	FactoryPatternDemo();

	std::cout << std::endl << "////////////////////////////" << std::endl << std::endl;

	std::cout << "Handle Pattern" << std::endl << std::endl;
	HandlePatternDemo();

	std::cout << std::endl << "////////////////////////////" << std::endl << std::endl;

	std::cout << "Proxy Pattern" << std::endl << std::endl;
	ProxyPatternDemo();

	std::cout << std::endl << "////////////////////////////" << std::endl << std::endl;

	std::cout << "Ending Application" << std::endl;
	std::cin.get();
	return EXIT_SUCCESS;
}