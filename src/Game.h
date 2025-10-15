#pragma once
#include <SFML/Graphics.hpp>
#include "Player/Player.h"
#include "Tilemap/Tilemap.h"

class Game
{
	public:
		Game(sf::RenderWindow& window);
		~Game();
		bool init();
		void update(float dt);
		void render();
		void keyPressed(float dt);
		bool checkCollision(sf::RectangleShape target, sf::RectangleShape collider);
		bool scanTilemapandSpawn();
		
	private:
		sf::RenderWindow& window;
		sf::RectangleShape rectangle;
		sf::RectangleShape rectangle2;
		sf::RectangleShape tangles;
		Player player;

		std::vector<int> spawn_tiles{ 1 };

		bool isSpawnTile(int test_value)
		{
			for (int value : spawn_tiles)
			{
				if (value == test_value)
				{
					printf("Spawn Tile\n");
					return true;
				}
				
			}
			return false;
		}
};
