#include "Game.h"
#include <print>
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
	std::println("Init");

	rectangle.setSize({ 1000,100 });
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
	if (target.getGlobalBounds().findIntersection(collider.getGlobalBounds()))
	{
		std::println("Colliding");
	}
	return false;
}
