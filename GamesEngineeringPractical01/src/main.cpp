#include "stdafx.h"

#include "FactoryPattern/FactoryImpl.h"
using namespace app;

void FactoryPatternDemo()
{
	std::unique_ptr<Factory> pFactory = std::make_unique<FactoryImpl>();
	std::vector<std::unique_ptr<Drawable>> drawVector;
	drawVector.push_back(pFactory->CreateNpc());
	drawVector.push_back(pFactory->CreatePlayer());
	drawVector.push_back(pFactory->CreatePlayer());
	drawVector.push_back(pFactory->CreateNpc());
	drawVector.push_back(pFactory->CreateNpc());
	drawVector.push_back(pFactory->CreatePlayer());

	std::cout << std::endl << "Drawing all drawables" << std::endl << std::endl;
	for (auto const & pDrawable : drawVector)
	{
		pDrawable->draw();
	}
	std::cout << std::endl << "Finished drawing all drawables" << std::endl << std::endl;
}

void HandlePatternDemo()
{

}

void ProxyPatternDemo()
{

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