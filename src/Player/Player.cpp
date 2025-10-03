#include "Player.h"
//#include <print>
#include <iostream>

bool Player::init()
{
	player.setSize({ 10, 10 });
	player.setScale({ 1, 1 });
	player.setFillColor(sf::Color::Blue);
	player.setPosition({ 100, 100 });
	return false;
}

void Player::update(float dt)
{
	normalise(dir);
	player.move(dir * speed * dt);

	if (is_grounded == false)
	{
		dir.y += gravity;
		player.move(dir * speed * dt);
	}
	std::cout << is_grounded << std::endl;
}

void Player::move()
{

}