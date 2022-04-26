#pragma once

#include <SFML/Graphics.hpp>
#include "obstacle.hpp"

class Turtle : public Obstacle {
public:
	Turtle(const sf::Vector2f& pos, const sf::Vector2f& size, const int speed, bool col) :
		Obstacle(pos, size, speed, col) {

	}
private:
	int mSpeed;
	bool mCol;
};