#pragma once
#include <SFML/Graphics.hpp>
#include "Player/Player.h"

class Game
{
	public:
		Game(sf::RenderWindow& window);
		~Game();
		bool init();
		void update(float dt);
		void render();
		void keyPressed();
		bool checkCollision(sf::RectangleShape target, sf::RectangleShape collider);
		

	
	private:
		sf::RenderWindow& window;
		sf::RectangleShape rectangle;
		Player player;
};
