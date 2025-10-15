#include "Game.h"
#include <iostream>
#include "Tilemap/Tilemap.h"

Game::Game(sf::RenderWindow& game_window)
	: window(game_window)
{

}

Game::~Game()
{

}

bool Game::init()
{
	//std::println("Init");
	constexpr std::array level = {
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
	};


	std::vector<sf::Vector2f> block_coords{};
	for (int i = 0; i < level.size(); i++)
	{
		if (isSpawnTile(level[i]))
		{
			block_coords.emplace_back(i % 16, i / 16);
			std::cout << block_coords.back().x << " ";
			std::cout << block_coords.back().y << std::endl;
			tangles.emplace_back();
			tangles.back().setOrigin(tangles.back().getSize() / 2.0f);
			tangles.back().setSize({ 200 , 20 });
			tangles.back().setScale({ 0.5, 0.5 });
			tangles.back().setPosition({block_coords.back().x * 48 , block_coords.back().y * 62.5f});				
		}
	}

	rectangle.setSize({ 1600,50});
	rectangle.setScale({1,1});
	rectangle.setOrigin(rectangle.getSize() / 2.0f);
	rectangle.setPosition((sf::Vector2f)window.getSize());
	rectangle.setFillColor(sf::Color::White);

	rectangle2.setSize({ 500,50 });
	rectangle2.setScale({ 1,1 });
	rectangle2.setOrigin(rectangle2.getSize() / 2.0f);
	rectangle2.setPosition({ 400, 250 });
	rectangle2.setFillColor(sf::Color::White);



	player.init();

	TileMap map;
	if (!map.load("tileset.png", { 50, 62 }, level.data(), 16, 8))
		return -1;

	return false;
}

void Game::update(float dt)
{
	keyPressed(dt);
	player.update(dt);
	player.is_grounded = false;
	std::vector<sf::RectangleShape> colliders = tangles;
	colliders.push_back(rectangle);
	colliders.push_back(rectangle2);
	for (auto& collider : colliders)
	{
		checkCollision(player.player, collider);
	}
}

void Game::render()
{
	window.draw(rectangle);
	window.draw(rectangle2);
	for (auto& tangles : tangles)
	{ 
		window.draw(tangles);
	}
	window.draw(player);

}

void Game::keyPressed(float dt)
{
	player.dir.x = 0;
	player.dir.y = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		player.dir.x += 1;
	}
	else
	{
		player.dir.x += 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		player.dir.x -= 1;
	}
	else
	{
		player.dir.x += 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && player.is_grounded)
	{
		player.velocity_y = player.jump_strength;
		player.is_grounded = false;
	}
	else
	{
		player.dir.y += 0;
	}

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	//{
	//	player.dir.y += 1;ddd
	//}
	//else
	//{
	//	player.dir.y += 0;
	//}

}

bool Game::checkCollision(sf::RectangleShape target, sf::RectangleShape collider)
{
	if (auto temp = target.getGlobalBounds().findIntersection(collider.getGlobalBounds()))
	{
		//std::println("Colliding");
		//std::cout << "Colliding\n";
		sf::Vector2f player_center = { target.getPosition().x + target.getSize().x / 2.0f, target.getPosition().y + target.getSize().y / 2.0f };
		sf::Vector2f direction = { 1, 1 };

		if (player_center.x < collider.getPosition().x + collider.getSize().x / 2.0f)
		{
			direction.x = -1;
		}
		if (player_center.y < collider.getPosition().y + collider.getSize().y / 2.0f)
		{
			direction.y = -1;
		}

		if(temp->size.x < temp->size.y)
		{
			player.player.setPosition({ player.player.getPosition().x + temp->size.x * direction.x, player.player.getPosition().y });
			std::cout << "Colliding on Right/Left" << std::endl;
		}
		else
		{
			float playerBottom = target.getPosition().y + target.getSize().y;
			float colliderTop = collider.getPosition().y;
			if (direction.y == -1 && target.getPosition().y < colliderTop && player.dir.y >= 0)
			{
				player.player.setPosition({ player.player.getPosition().x , player.player.getPosition().y + temp->size.y * direction.y });
				//std::cout << "Colliding on Top" << std::endl;
				player.is_grounded = true;
			}
			else
			{
				// If not landing on top, just resolve the collision without setting grounded
				player.player.setPosition({ player.player.getPosition().x , player.player.getPosition().y + temp->size.y * direction.y });
				//std::cout << "Colliding on Bottom" << std::endl;
				if (player.velocity_y < 0)
					player.velocity_y = 0; 
				// Stop upward velocity when hitting the bottom
			}
			if(direction.y == -1)
				player.is_grounded = true;
		}
		return true;
	}
	
	return false;
}
