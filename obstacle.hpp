#pragma once

#include <SFML/Graphics.hpp>

class Obstacle : public sf::RectangleShape {
public:
	Obstacle(const sf::Vector2f& pos, const sf::Vector2f& size, const int speed, bool col) :
		sf::RectangleShape(size) {
		this->setPosition(pos);
		this->mSpeed = speed;
		this->mCol = col;
	}

	virtual int getSpeed() {
		return this->mSpeed;
	}
	virtual bool getCol() {
		return this->mCol;
	}
private:
	int mSpeed;
	bool mCol;
};
