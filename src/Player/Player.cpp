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
	player.move({dir.x * speed * dt, 0 });

	if (is_grounded == false)
	{
		velocity_y += gravity * 2 * dt;
	}
	else
	{
		velocity_y = 0;
	}
	player.move({ 0, velocity_y * dt });
	//std::cout << is_grounded << std::endl;
}

void Player::move()
{

}