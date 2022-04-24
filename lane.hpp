#pragma once

#include <SFML/Graphics.hpp>

class Lane : public sf::RectangleShape {
public:
	Lane(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Color& color, bool col) :
		sf::RectangleShape(size) {
		this->setFillColor(color);
		this->setPosition(pos);
		bool mCol = false;
	}
private:
	bool mCol;
};
