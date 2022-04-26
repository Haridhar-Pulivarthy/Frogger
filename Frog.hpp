#include <iostream>
#include <SFML/Graphics.hpp>

class Frog : public sf::RectangleShape {
public:
	Frog(const sf::Vector2f& pos, const sf::Vector2f& size) :
		sf::RectangleShape(size) {
		this->setPosition(pos);
	}
};