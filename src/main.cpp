// TestPlatformer.cpp : Defines the entry point for the application.
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Test Window");
	window.setTitle("Platformer");
	window.setVerticalSyncEnabled(true);

	Game game(window);

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();

			else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
			{
				if (keyPressed-> scancode == sf::Keyboard::Scancode::Escape)
					window.close();
			}
		}
	}
}
