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

void Game::update()
{
	player.update();
}

void Game::render()
{
	window.draw(rectangle);
	window.draw(player);
}

void Game::keyPressed(const sf::Event event)
{
	player.dir.x = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		std::println("Right");
		player.dir.x += 1;
	}
	else
	{
		player.dir.x += 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		std::println("Left");
		player.dir.x -= 1;
	}
	else
	{
		player.dir.x += 0;
	}
}
