#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>

using namespace std::this_thread;
using namespace std::chrono;

#include "player.h"
#include "lane.h"
#include "car.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 900), "Frogger i guess");
	
	// PLAYER CHARACTER: FROG
	// initializing character: object, texture, origin

	Player frog(sf::Vector2f(window.getSize().x / 2, window.getSize().y - 38.5), sf::Vector2f(50, 50));

	sf::Texture frogtr;
	if (!frogtr.loadFromFile("frogger.png")) {
		return EXIT_FAILURE;
	}

	frog.setTexture(&frogtr, true);
	frog.setOrigin(25, 25);

	// TERRAIN OBJECTS
	// initializing roads: position, size, color, texture

	Lane r1(sf::Vector2f(0, window.getSize().y - 150), sf::Vector2f(window.getSize().x, 75), sf::Color::Color(100, 100, 100, 110), false);
	Lane r2(sf::Vector2f(0, window.getSize().y - 225), sf::Vector2f(window.getSize().x, 75), sf::Color::Color(100, 100, 100, 110), false);
	Lane r3(sf::Vector2f(0, window.getSize().y - 300), sf::Vector2f(window.getSize().x, 75), sf::Color::Color(100, 100, 100, 110), false);
	Lane r4(sf::Vector2f(0, window.getSize().y - 375), sf::Vector2f(window.getSize().x, 75), sf::Color::Color(100, 100, 100, 110), false);

	sf::Texture roadtr;
	if (!roadtr.loadFromFile("roadtxtr.png")) {
		return EXIT_FAILURE;
	}

	r1.setTexture(&roadtr, true);
	r2.setTexture(&roadtr, true);
	r3.setTexture(&roadtr, true);
	r4.setTexture(&roadtr, true);

	// initializing grass: position, size, color, texture

	Lane g1(sf::Vector2f(0, window.getSize().y - 75), sf::Vector2f(window.getSize().x, 75), sf::Color::Color(100, 100, 100, 190), false);
	Lane g2(sf::Vector2f(0, window.getSize().y - 450), sf::Vector2f(window.getSize().x, 75), sf::Color::Color(100, 100, 100, 190), false);

	// grass texture: from frogger game
	sf::Texture grasstr;
	if (!grasstr.loadFromFile("froggergrass.png")) {
		return EXIT_FAILURE;
	}

	g1.setTexture(&grasstr, true);
	g2.setTexture(&grasstr, true);

	// initializing water: position, size, color, texture

	Lane w1(sf::Vector2f(0, window.getSize().y - 525), sf::Vector2f(window.getSize().x, 75), sf::Color::Color(10, 10, 180, 110), true);
	Lane w2(sf::Vector2f(0, window.getSize().y - 600), sf::Vector2f(window.getSize().x, 75), sf::Color::Color(10, 10, 180, 110), true);
	Lane w3(sf::Vector2f(0, window.getSize().y - 675), sf::Vector2f(window.getSize().x, 75), sf::Color::Color(10, 10, 180, 110), true);
	Lane w4(sf::Vector2f(0, window.getSize().y - 750), sf::Vector2f(window.getSize().x, 75), sf::Color::Color(10, 10, 180, 110), true);
	Lane w5(sf::Vector2f(0, window.getSize().y - 825), sf::Vector2f(window.getSize().x, 75), sf::Color::Color(10, 10, 180, 110), true);

	// water texture: https://www.pinterest.com/pin/432556739181875716/
	sf::Texture watertr;
	if (!watertr.loadFromFile("watertxtr.png")) {
		return EXIT_FAILURE;
	}

	w1.setTexture(&watertr, true);
	w2.setTexture(&watertr, true);
	w3.setTexture(&watertr, true);
	w4.setTexture(&watertr, true);
	w5.setTexture(&watertr, true);

	// initializing end: position, size, color, texture

	Lane e1(sf::Vector2f(0, window.getSize().y - 900), sf::Vector2f(window.getSize().x, 75), sf::Color::Color(10, 180, 10, 110), false);

	// end texture:  https://www.spoonflower.com/en/wallpaper/4646979-8-bit-grass-block-by-wilsongraphics
	sf::Texture endtr;
	if (!endtr.loadFromFile("endtxtr.png")) {
		return EXIT_FAILURE;
	}

	e1.setTexture(&endtr, true);

	// OBSTACLES: car, river terrain
	// initializing cars: position, size, speed, texture, col
	// red cars

	Car rc1(sf::Vector2f(window.getSize().x - 60, window.getSize().y - 137.5), sf::Vector2f(60, 50), 10, true);
	Car rc2(sf::Vector2f(window.getSize().x - 310, window.getSize().y - 137.5), sf::Vector2f(60, 50), 10, true);
	Car rc3(sf::Vector2f(window.getSize().x - 560, window.getSize().y - 137.5), sf::Vector2f(60, 50), 10, true);
	Car rc4(sf::Vector2f(window.getSize().x - 810, window.getSize().y - 137.5), sf::Vector2f(60, 50), 10, true);
	Car rc5(sf::Vector2f(window.getSize().x - 1060, window.getSize().y - 137.5), sf::Vector2f(60, 50), 10, true);
	Car rc6(sf::Vector2f(window.getSize().x - 1310, window.getSize().y - 137.5), sf::Vector2f(60, 50), 10, true);

	// car textures: https://strategywiki.org/wiki/Frogger/Gameplay
	sf::Texture rctr;
	if (!rctr.loadFromFile("frogger car1.png")) {
		return EXIT_FAILURE;
	}

	rc1.setTexture(&rctr, true);
	rc2.setTexture(&rctr, true);
	rc3.setTexture(&rctr, true);
	rc4.setTexture(&rctr, true);
	rc5.setTexture(&rctr, true);
	rc6.setTexture(&rctr, true);

	// green cars

	Car gc1(sf::Vector2f(window.getSize().x - 60, window.getSize().y - 213.5), sf::Vector2f(60, 50), 7, true);
	Car gc2(sf::Vector2f(window.getSize().x - 300, window.getSize().y - 213.5), sf::Vector2f(60, 50), 7, true);
	Car gc3(sf::Vector2f(window.getSize().x - 540, window.getSize().y - 213.5), sf::Vector2f(60, 50), 7, true);
	Car gc4(sf::Vector2f(window.getSize().x - 780, window.getSize().y - 213.5), sf::Vector2f(60, 50), 7, true);
	Car gc5(sf::Vector2f(window.getSize().x - 1020, window.getSize().y - 213.5), sf::Vector2f(60, 50), 7, true);
	Car gc6(sf::Vector2f(window.getSize().x - 1260, window.getSize().y - 213.5), sf::Vector2f(60, 50), 7, true);

	// car textures: https://strategywiki.org/wiki/Frogger/Gameplay
	sf::Texture gctr;
	if (!gctr.loadFromFile("frogger car3.png")) {
		return EXIT_FAILURE;
	}

	gc1.setTexture(&gctr, true);
	gc2.setTexture(&gctr, true);
	gc3.setTexture(&gctr, true);
	gc4.setTexture(&gctr, true);
	gc5.setTexture(&gctr, true);
	gc6.setTexture(&gctr, true);

	// blue cars

	Car bc1(sf::Vector2f(window.getSize().x - 60, window.getSize().y - 288.5), sf::Vector2f(60, 50), 13, true);
	Car bc2(sf::Vector2f(window.getSize().x - 340, window.getSize().y - 288.5), sf::Vector2f(60, 50), 13, true);
	Car bc3(sf::Vector2f(window.getSize().x - 620, window.getSize().y - 288.5), sf::Vector2f(60, 50), 13, true);
	Car bc4(sf::Vector2f(window.getSize().x - 900, window.getSize().y - 288.5), sf::Vector2f(60, 50), 13, true);
	Car bc5(sf::Vector2f(window.getSize().x - 1180, window.getSize().y - 288.5), sf::Vector2f(60, 50), 13, true);

	// car textures: https://strategywiki.org/wiki/Frogger/Gameplay
	sf::Texture bctr;
	if (!bctr.loadFromFile("frogger car2.png")) {
		return EXIT_FAILURE;
	}

	bc1.setTexture(&bctr, true);
	bc2.setTexture(&bctr, true);
	bc3.setTexture(&bctr, true);
	bc4.setTexture(&bctr, true);
	bc5.setTexture(&bctr, true);

	// trucks

	Car tc1(sf::Vector2f(window.getSize().x - 120, window.getSize().y - 363.5), sf::Vector2f(120, 50), 5, true);
	Car tc2(sf::Vector2f(window.getSize().x - 460, window.getSize().y - 363.5), sf::Vector2f(120, 50), 5, true);
	Car tc3(sf::Vector2f(window.getSize().x - 800, window.getSize().y - 363.5), sf::Vector2f(120, 50), 5, true);
	Car tc4(sf::Vector2f(window.getSize().x - 1140, window.getSize().y - 363.5), sf::Vector2f(120, 50), 5, true);


	// car textures: https://strategywiki.org/wiki/Frogger/Gameplay
	sf::Texture tctr;
	if (!tctr.loadFromFile("frogger car4.png")) {
		return EXIT_FAILURE;
	}

	tc1.setTexture(&tctr, true);
	tc2.setTexture(&tctr, true);
	tc3.setTexture(&tctr, true);
	tc4.setTexture(&tctr, true);

	// EVENT LOOP

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				frog.setRotation(0);
				frog.move(0, -37.5);
				
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				frog.setRotation(180);
				frog.move(0, 37.5);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				frog.setRotation(270);
				frog.move(-37.5, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				frog.setRotation(90);
				frog.move(37.5, 0);
			}
		}

		// first row of cars

		rc1.move(rc1.getSpeed() / -100.0, 0);
		if (rc1.getPosition().x <= -50) {
			rc1.setPosition(window.getSize().x, window.getSize().y - 137.5);
		}
		rc2.move(rc2.getSpeed() / -100.0, 0);
		if (rc2.getPosition().x <= -50) {
			rc2.setPosition(window.getSize().x, window.getSize().y - 137.5);
		}
		rc3.move(rc3.getSpeed() / -100.0, 0);
		if (rc3.getPosition().x <= -50) {
			rc3.setPosition(window.getSize().x, window.getSize().y - 137.5);
		}
		rc4.move(rc4.getSpeed() / -100.0, 0);
		if (rc4.getPosition().x <= -50) {
			rc4.setPosition(window.getSize().x, window.getSize().y - 137.5);
		}
		rc5.move(rc5.getSpeed() / -100.0, 0);
		if (rc5.getPosition().x <= -50) {
			rc5.setPosition(window.getSize().x, window.getSize().y - 137.5);
		}
		rc6.move(rc6.getSpeed() / -100.0, 0);
		if (rc6.getPosition().x <= -50) {
			rc6.setPosition(window.getSize().x, window.getSize().y - 137.5);
		}

		// second row of cars

		gc1.move(gc1.getSpeed() / 100.0, 0);
		if (gc1.getPosition().x >= window.getSize().x + 50) {
			gc1.setPosition(-50, window.getSize().y - 213.5);
		}
		gc2.move(gc2.getSpeed() / 100.0, 0);
		if (gc2.getPosition().x >= window.getSize().x + 50) {
			gc2.setPosition(-50, window.getSize().y - 213.5);
		}
		gc3.move(gc3.getSpeed() / 100.0, 0);
		if (gc3.getPosition().x >= window.getSize().x + 50) {
			gc3.setPosition(-50, window.getSize().y - 213.5);
		}
		gc4.move(gc4.getSpeed() / 100.0, 0);
		if (gc4.getPosition().x >= window.getSize().x + 50) {
			gc4.setPosition(-50, window.getSize().y - 213.5);
		}
		gc5.move(gc5.getSpeed() / 100.0, 0);
		if (gc5.getPosition().x >= window.getSize().x + 50) {
			gc5.setPosition(-50, window.getSize().y - 213.5);
		}
		gc6.move(gc6.getSpeed() / 100.0, 0);
		if (gc6.getPosition().x >= window.getSize().x + 50) {
			gc6.setPosition(-50, window.getSize().y - 213.5);
		}

		// third row of cars

		bc1.move(bc1.getSpeed() / -100.0, 0);
		if (bc1.getPosition().x <= -50) {
			bc1.setPosition(window.getSize().x, window.getSize().y - 288.5);
		}
		bc2.move(bc2.getSpeed() / -100.0, 0);
		if (bc2.getPosition().x <= -50) {
			bc2.setPosition(window.getSize().x, window.getSize().y - 288.5);
		}
		bc3.move(bc3.getSpeed() / -100.0, 0);
		if (bc3.getPosition().x <= -50) {
			bc3.setPosition(window.getSize().x, window.getSize().y - 288.5);
		}
		bc4.move(bc4.getSpeed() / -100.0, 0);
		if (bc4.getPosition().x <= -50) {
			bc4.setPosition(window.getSize().x, window.getSize().y - 288.5);
		}
		bc5.move(bc5.getSpeed() / -100.0, 0);
		if (bc5.getPosition().x <= -50) {
			bc5.setPosition(window.getSize().x, window.getSize().y - 288.5);
		}

		// fourth row of cars

		tc1.move(tc1.getSpeed() / 100.0, 0);
		if (tc1.getPosition().x >= window.getSize().x + 50) {
			tc1.setPosition(-100, window.getSize().y - 363.5);
		}
		tc2.move(tc2.getSpeed() / 100.0, 0);
		if (tc2.getPosition().x >= window.getSize().x + 50) {
			tc2.setPosition(-100, window.getSize().y - 363.5);
		}
		tc3.move(tc3.getSpeed() / 100.0, 0);
		if (tc3.getPosition().x >= window.getSize().x + 50) {
			tc3.setPosition(-100, window.getSize().y - 363.5);
		}
		tc4.move(tc4.getSpeed() / 100.0, 0);
		if (tc4.getPosition().x >= window.getSize().x + 50) {
			tc4.setPosition(-100, window.getSize().y - 363.5);
		}

		// DRAWING OBJECTS AND DISPLAYING

		window.clear();
		window.draw(r1);
		window.draw(r2);
		window.draw(r3);
		window.draw(r4);
		window.draw(g1);
		window.draw(g2);
		window.draw(w1);
		window.draw(w2);
		window.draw(w3);
		window.draw(w4);
		window.draw(w5);
		window.draw(e1);
		window.draw(rc1);
		window.draw(rc2);
		window.draw(rc3);
		window.draw(rc4);
		window.draw(rc5);
		window.draw(rc6);
		window.draw(gc1);
		window.draw(gc2);
		window.draw(gc3);
		window.draw(gc4);
		window.draw(gc5);
		window.draw(gc6);
		window.draw(bc1);
		window.draw(bc2);
		window.draw(bc3);
		window.draw(bc4);
		window.draw(bc5);
		window.draw(tc1);
		window.draw(tc2);
		window.draw(tc3);
		window.draw(tc4);
		window.draw(frog);
		window.display();
	}

	return 0;
}
