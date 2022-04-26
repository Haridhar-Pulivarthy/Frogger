#pragma once

#include <SFML/Graphics.hpp>
#include "obstacle.hpp"

class Snake : public Obstacle {
public:
	Snake(const sf::Vector2f& pos, const sf::Vector2f& size, const int speed, bool col) :
		Obstacle(pos, size, speed, col) {

	}
private:
	int mSpeed;
	bool mCol;
};