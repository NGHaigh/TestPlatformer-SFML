#include "Game.h"
#include <iostream>

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

	rectangle.setSize({ 500,100 });
	rectangle.setScale({1,1});
	rectangle.setOrigin(rectangle.getSize() / 2.0f);
	rectangle.setPosition((sf::Vector2f)window.getSize() /2.0f);
	rectangle.setFillColor(sf::Color::White);

	player.init();
	return false;
}

void Game::update(float dt)
{
	keyPressed();
	player.update(dt);
	checkCollision(player.player, rectangle);
}

void Game::render()
{
	window.draw(rectangle);
	window.draw(player);
}

void Game::keyPressed()
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		player.dir.y -= 1;
	}
	else
	{
		player.dir.y += 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		player.dir.y += 1;
	}
	else
	{
		player.dir.y += 0;
	}

}

bool Game::checkCollision(sf::RectangleShape target, sf::RectangleShape collider)
{
	if (auto temp = target.getGlobalBounds().findIntersection(collider.getGlobalBounds()))
	{
		//std::println("Colliding");
		std::cout << "Colliding\n";
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
		}
		else
		{
			player.player.setPosition({ player.player.getPosition().x, player.player.getPosition().y + temp->size.y * direction.y });
		}



		//if(target.getPosition().y + target.getSize().y / 2.0f < collider.getPosition().y)
		//{
		//	player.player.setPosition({ target.getPosition().x, collider.getPosition().y - collider.getSize().y / 2.0f - player.player.getSize().y });
		//}
		//
		//else if (target.getPosition().x + target.getSize().x / 2.0f < collider.getPosition().x)
		//{
		//	player.player.setPosition({ collider.getPosition().x - collider.getSize().x / 2.0f - player.player.getSize().x , target.getPosition().y });
		//}
	}
	return false;
}
