#include <iostream>
#include <SFML/Graphics.hpp>

class Player : public sf::RectangleShape {
public:
	Player(const sf::Vector2f& pos, const sf::Vector2f& size) :
		sf::RectangleShape(size) {
		this->setPosition(pos);
	}
};
