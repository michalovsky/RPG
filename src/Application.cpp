#include "Application.h"



Application::Application() : app(nullptr), menu(nullptr), game(nullptr)
{
}

Application::~Application()
{
	delete app;
}

void Application::run()
{
	createMenuWindow();
	int choice = menu->chooseMode();

	while (choice != (int)Mode::EXIT)
	{
		switch (choice)
		{
		case (int)Mode::MENU:
			createMenuWindow();
			choice = menu->chooseMode();
			break;
		case (int)Mode::GAME:
			createGameWindow();
			choice = game->run();
			break;
		}
	}
}

void Application::createMenuWindow()
{
	if (menu != nullptr)
	{
		delete menu;
		menu = nullptr;
	}

	if (app != nullptr)
	{
		delete app;
		app = nullptr;
	}

	app = new sf::RenderWindow(sf::VideoMode(800, 600), "RPG game");
	app->setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - app->getSize().x / 2, sf::VideoMode::getDesktopMode().height / 2 - app->getSize().y / 2));
	app->setFramerateLimit(60);

	menu = new Menu(*app);

}

void Application::createGameWindow()
{
	if (game != nullptr)
	{
		delete game;
		game = nullptr;
	}

	if (app != nullptr)
	{
		delete app;
		app = nullptr;
	}


	app = new sf::RenderWindow(sf::VideoMode(1280, 800), "RPG game");
	app->setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - app->getSize().x / 2, sf::VideoMode::getDesktopMode().height / 2 - app->getSize().y / 2));
	app->setFramerateLimit(60);

	game = new Game(*app);
}
