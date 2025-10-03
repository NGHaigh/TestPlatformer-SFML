#pragma once
#include <SFML/Graphics.hpp>

class Player : public sf::Drawable
{
public:
	bool init();
	void update(float dt);
	void move();
	float speed = 100.0f;
	sf::Vector2f dir;
	sf::RectangleShape player;
	float gravity = 0.98f;
	bool is_grounded = false;

private:
	
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
		target.draw(player);
    }

	void normalise(sf::Vector2f& move)
	{
		float mag = sqrtf(move.x * move.x + move.y * move.y);
		if (mag > 1.0f)
		{
			move.x /= mag;
			move.y /= mag;
		}
	}
};


