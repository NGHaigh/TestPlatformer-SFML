// TestPlatformer.cpp : Defines the entry point for the application.
#include <SFML/Graphics.hpp>
#include <iostream>
#include <print>
#include "Game.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Test Window");
	window.setTitle("Platformer");
	window.setVerticalSyncEnabled(true);

	Game game(window);

	game.init();
	sf::Clock clock;
	Player player;

	while (window.isOpen())
	{
		sf::Time time = clock.restart();
		float dt = time.asSeconds();

		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();

			//else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
			//{
			//	game.keyPressed(*keyPressed);
			//	if (keyPressed-> scancode == sf::Keyboard::Scancode::Escape)
			//		window.close();
			//}
		}

		

		game.update(dt);

		window.clear();
		game.render();
		window.display();

	}
}
