#pragma once
#include <SFML/Graphics.hpp>

class Player : public sf::Drawable
{
public:
	bool init();
	void update();
	void move();
	float speed = 5.0f;
	sf::Vector2f dir;
	float velocity;

private:
	sf::RectangleShape player;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
		target.draw(player);
    }
};


