#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>

using namespace std::this_thread;
using namespace std::chrono;

#include "Frog.hpp"
#include "lane.hpp"
#include "car.hpp"
#include "log.hpp"
#include "croc.hpp"
#include "turtle.hpp"
#include "otter.hpp"
#include "snake.hpp"
#include "croc_mouth.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 900), "Frogger i guess");

	// PLAYER CHARACTER: FROG
	// initializing character: object, texture, origin

	Frog frog(sf::Vector2f(window.getSize().x / 2, window.getSize().y - 38.5), sf::Vector2f(50, 50));
	Frog frog_wifey(sf::Vector2f(window.getSize().x - 666, window.getSize().y - 888), sf::Vector2f(50, 50));

	sf::Texture frogtr;
	if (!frogtr.loadFromFile("frogger.png")) {
		return EXIT_FAILURE;
	}

	frog.setTexture(&frogtr, true);
	frog.setOrigin(25, 25);

	sf::Texture frogWifeytr;
	if (!frogWifeytr.loadFromFile("frog gf (1).png")) {
		return EXIT_FAILURE;
	}
	frog_wifey.setTexture(&frogWifeytr, true);

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

	Croc_Mouth cm1(sf::Vector2f(window.getSize().x - 1280, window.getSize().y - 900), sf::Vector2f(80, 80), 0, true);
	Croc_Mouth cm2(sf::Vector2f(window.getSize().x - 1120, window.getSize().y - 900), sf::Vector2f(80, 80), 0, true);
	Croc_Mouth cm3(sf::Vector2f(window.getSize().x - 960, window.getSize().y - 900), sf::Vector2f(80, 80), 0, true);
	Croc_Mouth cm4(sf::Vector2f(window.getSize().x - 800, window.getSize().y - 900), sf::Vector2f(80, 80), 0, true);

	// croc mouth textures:  https://strategywiki.org/wiki/Frogger/Gameplay
	sf::Texture croc_mouth;
	if (!croc_mouth.loadFromFile("croc mouth.png")) {
		return EXIT_FAILURE;
	}
	cm1.setTexture(&croc_mouth, true);
	cm2.setTexture(&croc_mouth, true);
	cm3.setTexture(&croc_mouth, true);
	cm4.setTexture(&croc_mouth, true);

	Croc_Mouth cm5(sf::Vector2f(window.getSize().x - 560, window.getSize().y - 900), sf::Vector2f(80, 80), 0, true);
	Croc_Mouth cm6(sf::Vector2f(window.getSize().x - 400, window.getSize().y - 900), sf::Vector2f(80, 80), 0, true);
	Croc_Mouth cm7(sf::Vector2f(window.getSize().x - 240, window.getSize().y - 900), sf::Vector2f(80, 80), 0, true);
	Croc_Mouth cm8(sf::Vector2f(window.getSize().x - 80, window.getSize().y - 900), sf::Vector2f(80, 80), 0, true);

	// mirrored croc mouth textures:  https://strategywiki.org/wiki/Frogger/Gameplay
	sf::Texture croc_mouth1;
	if (!croc_mouth1.loadFromFile("croc mouth1.png")) {
		return EXIT_FAILURE;
	}
	cm5.setTexture(&croc_mouth1, true);
	cm6.setTexture(&croc_mouth1, true);
	cm7.setTexture(&croc_mouth1, true);
	cm8.setTexture(&croc_mouth1, true);


	// logs and crocs
	Log l1(sf::Vector2f(window.getSize().x - 50, window.getSize().y - 511), sf::Vector2f(140, 40), 10, true);
	Croc c1(sf::Vector2f(window.getSize().x - 300, window.getSize().y - 511), sf::Vector2f(140, 40), 10, true);
	Log l2(sf::Vector2f(window.getSize().x - 550, window.getSize().y - 511), sf::Vector2f(140, 40), 10, true);
	Croc c2(sf::Vector2f(window.getSize().x - 800, window.getSize().y - 511), sf::Vector2f(140, 40), 10, true);
	Log l3(sf::Vector2f(window.getSize().x - 1050, window.getSize().y - 511), sf::Vector2f(140, 40), 10, true);
	Croc c3(sf::Vector2f(window.getSize().x - 1300, window.getSize().y - 511), sf::Vector2f(140, 40), 10, true);

	// log textures:  https://strategywiki.org/wiki/Frogger/Gameplay
	sf::Texture log;
	if (!log.loadFromFile("log1.png")) {
		return EXIT_FAILURE;
	}

	// croc textures:  https://strategywiki.org/wiki/Frogger/Gameplay
	sf::Texture croc;
	if (!croc.loadFromFile("croc1.png")) {
		return EXIT_FAILURE;
	}

	l1.setTexture(&log, true);
	c1.setTexture(&croc, true);
	l2.setTexture(&log, true);
	c2.setTexture(&croc, true);
	l3.setTexture(&log, true);
	c3.setTexture(&croc, true);

	// turtles

	Turtle t1(sf::Vector2f(window.getSize().x - 60, window.getSize().y - 586), sf::Vector2f(80, 50), 7, true);
	Turtle t2(sf::Vector2f(window.getSize().x - 300, window.getSize().y - 586), sf::Vector2f(80, 50), 7, true);
	Turtle t3(sf::Vector2f(window.getSize().x - 540, window.getSize().y - 586), sf::Vector2f(80, 50), 7, true);
	Turtle t4(sf::Vector2f(window.getSize().x - 780, window.getSize().y - 586), sf::Vector2f(80, 50), 7, true);
	Turtle t5(sf::Vector2f(window.getSize().x - 1020, window.getSize().y - 586), sf::Vector2f(80, 50), 7, true);
	Turtle t6(sf::Vector2f(window.getSize().x - 1260, window.getSize().y - 586), sf::Vector2f(80, 50), 7, true);

	// turtle textures: https://strategywiki.org/wiki/Frogger/Gameplay
	sf::Texture turtle;
	if (!turtle.loadFromFile("turtle2.png")) {
		return EXIT_FAILURE;
	}

	t1.setTexture(&turtle, true);
	t2.setTexture(&turtle, true);
	t3.setTexture(&turtle, true);
	t4.setTexture(&turtle, true);
	t5.setTexture(&turtle, true);
	t6.setTexture(&turtle, true);

	// more logs
	Log l4(sf::Vector2f(window.getSize().x - 50, window.getSize().y - 655), sf::Vector2f(180, 40), 10, true);
	Log l5(sf::Vector2f(window.getSize().x - 550, window.getSize().y - 655), sf::Vector2f(180, 40), 10, true);
	l4.setTexture(&log, true);
	l5.setTexture(&log, true);

	// more logs and crocs and turtles
	Log l6(sf::Vector2f(window.getSize().x - 50, window.getSize().y - 730), sf::Vector2f(100, 40), 10, true);
	Croc c4(sf::Vector2f(window.getSize().x - 300, window.getSize().y - 730), sf::Vector2f(140, 40), 10, true);
	Turtle t7(sf::Vector2f(window.getSize().x - 550, window.getSize().y - 730), sf::Vector2f(80, 50), 10, true);
	Log l7(sf::Vector2f(window.getSize().x - 800, window.getSize().y - 730), sf::Vector2f(100, 40), 10, true);
	Croc c5(sf::Vector2f(window.getSize().x - 1050, window.getSize().y - 730), sf::Vector2f(140, 40), 10, true);
	Turtle t8(sf::Vector2f(window.getSize().x - 1250, window.getSize().y - 730), sf::Vector2f(80, 50), 10, true);

	// mirrored croc textures: https://strategywiki.org/wiki/Frogger/Gameplay
	sf::Texture croc1;
	if (!croc1.loadFromFile("croc.png")) {
		return EXIT_FAILURE;
	}

	l6.setTexture(&log, true);
	c4.setTexture(&croc1, true);
	t7.setTexture(&turtle, true);
	l7.setTexture(&log, true);
	c5.setTexture(&croc1, true);
	t8.setTexture(&turtle, true);

	// the otter
	Otter o(sf::Vector2f(window.getSize().x - 50, window.getSize().y - 805), sf::Vector2f(80, 50), 25, true);
	Otter o2(sf::Vector2f(window.getSize().x - 900, window.getSize().y - 805), sf::Vector2f(80, 50), 25, true);
	// mirrored otter textures: https://strategywiki.org/wiki/Frogger/Gameplay
	sf::Texture otter;
	if (!otter.loadFromFile("otter.png")) {
		return EXIT_FAILURE;
	}
	o.setTexture(&otter, true);
	o2.setTexture(&otter, true);

	// the snake
	Snake s(sf::Vector2f(window.getSize().x - 600, window.getSize().y - 805), sf::Vector2f(80, 50), 27, true);
	Snake s2(sf::Vector2f(window.getSize().x - 1200, window.getSize().y - 805), sf::Vector2f(80, 50), 27, true);
	// mirrored snake textures: https://strategywiki.org/wiki/Frogger/Gameplay
	sf::Texture snake;
	if (!snake.loadFromFile("snake1.png")) {
		return EXIT_FAILURE;
	}
	s.setTexture(&snake, true);
	s2.setTexture(&snake, true);

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

	int lives = 5;
	std::string live = std::to_string(lives);

	//loads font for lives counter
	sf::Font font;
	if (!font.loadFromFile("ariblk.ttf"))
	{
		return EXIT_FAILURE;
	}

	//sets up counter
	sf::Text text;
	text.setFont(font);
	text.setString("Lives: ");
	text.setCharacterSize(25);
	text.setFillColor(sf::Color::Green);
	text.setPosition(15, 1250);

	sf::Text livesT;
	livesT.setFont(font);
	livesT.setString(live);
	livesT.setCharacterSize(25);
	livesT.setFillColor(sf::Color::Green);
	livesT.setPosition(100, 1250);

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

		// logs and crocs

		l1 .move(l1.getSpeed() / -100.0, 0);
		if (l1.getPosition().x <= -50) {
			l1.setPosition(window.getSize().x, window.getSize().y - 511);
		}
		c1 .move(c1.getSpeed() / -100.0, 0);
		 if (c1.getPosition().x <= -50) {
		 	c1.setPosition(window.getSize().x, window.getSize().y - 511);
		}
		l2.move(l2.getSpeed() / -100.0, 0);
		if (l2.getPosition().x <= -50) {
			l2.setPosition(window.getSize().x, window.getSize().y - 511);
		}
		c2.move(c2.getSpeed() / -100.0, 0);
		if (c2.getPosition().x <= -50) {
			c2.setPosition(window.getSize().x, window.getSize().y - 511);
		}
		l3.move(l3.getSpeed() / -100.0, 0);
		if (l3.getPosition().x <= -50) {
			l3.setPosition(window.getSize().x, window.getSize().y - 511);
		}
		c3.move(c3.getSpeed() / -100.0, 0);
		if (c3.getPosition().x <= -50) {
			c3.setPosition(window.getSize().x, window.getSize().y - 511);
		}

		// turtles

		t1.move(t1.getSpeed() / 100.0, 0);
		if (t1.getPosition().x >= window.getSize().x + 50) {
			t1.setPosition(-50, window.getSize().y - 586);
		}
		t2.move(t2.getSpeed() / 100.0, 0);
		if (t2.getPosition().x >= window.getSize().x + 50) {
			t2.setPosition(-50, window.getSize().y - 586);
		}
		t3.move(t3.getSpeed() / 100.0, 0);
		if (t3.getPosition().x >= window.getSize().x + 50) {
			t3.setPosition(-50, window.getSize().y - 586);
		}
		t4.move(t4.getSpeed() / 100.0, 0);
		if (t4.getPosition().x >= window.getSize().x + 50) {
			t4.setPosition(-50, window.getSize().y - 586);
		}
		t5.move(t5.getSpeed() / 100.0, 0);
		if (t5.getPosition().x >= window.getSize().x + 50) {
			t5.setPosition(-50, window.getSize().y - 586);
		}
		t6.move(t6.getSpeed() / 100.0, 0);
		if (t6.getPosition().x >= window.getSize().x + 50) {
			t6.setPosition(-50, window.getSize().y - 586);
		}

		// more logs

		l4.move(l4.getSpeed() / -100.0, 0);
		if (l4.getPosition().x <= -50) {
			l4.setPosition(window.getSize().x, window.getSize().y - 655);
		}
		l5.move(l5.getSpeed() / -100.0, 0);
		if (l5.getPosition().x <= -50) {
			l5.setPosition(window.getSize().x, window.getSize().y - 655);
		}

		// more logs and crocs and turtles

		l6.move(l6.getSpeed() / 100.0, 0);
		if (l6.getPosition().x >= window.getSize().x + 50) {
			l6.setPosition(-100, window.getSize().y - 730);
		}
		c4.move(c4.getSpeed() / 100.0, 0);
		if (c4.getPosition().x >= window.getSize().x + 50) {
			c4.setPosition(-100, window.getSize().y - 730);
		}
		t7.move(t7.getSpeed() / 100.0, 0);
		if (t7.getPosition().x >= window.getSize().x + 50) {
			t7.setPosition(-100, window.getSize().y - 730);
		}
		l7 .move(l7.getSpeed() / 100.0, 0);
		if (l7.getPosition().x >= window.getSize().x + 50) {
			l7.setPosition(-100, window.getSize().y - 730);
		}
		c5.move(c5.getSpeed() / 100.0, 0);
		if (c5.getPosition().x >= window.getSize().x + 50) {
			c5.setPosition(-100, window.getSize().y - 730);
		}
		t8.move(t8.getSpeed() / 100.0, 0);
		if (t8.getPosition().x >= window.getSize().x + 50) {
			t8.setPosition(-100, window.getSize().y - 730);
		}

		// otters
		o.move(o.getSpeed() / 100.0, 0);
		if (o.getPosition().x >= window.getSize().x + 50) {
			o.setPosition(-100, window.getSize().y - 805);
		}
		o2.move(o2.getSpeed() / 100.0, 0);
		if (o2.getPosition().x >= window.getSize().x + 50) {
			o2.setPosition(-100, window.getSize().y - 805);
		}


		// snakes
		s.move(s.getSpeed() / 100.0, 0);
		if (s.getPosition().x >= window.getSize().x + 50) {
			s.setPosition(-100, window.getSize().y - 805);
		}
		s2.move(s2.getSpeed() / 100.0, 0);
		if (s2.getPosition().x >= window.getSize().x + 50) {
			s2.setPosition(-100, window.getSize().y - 805);
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

		// if the frog is on the water
		if (frog.getGlobalBounds().intersects(w1.getGlobalBounds()) || frog.getGlobalBounds().intersects(w2.getGlobalBounds())
			|| frog.getGlobalBounds().intersects(w3.getGlobalBounds()) || frog.getGlobalBounds().intersects(w4.getGlobalBounds())
			|| frog.getGlobalBounds().intersects(w5.getGlobalBounds()))
		{
			// and the frog is not on a log, turtle, or otter, it dies
			if (!frog.getGlobalBounds().intersects(l1.getGlobalBounds()) && !frog.getGlobalBounds().intersects(l2.getGlobalBounds())
				&& !frog.getGlobalBounds().intersects(l3.getGlobalBounds()) && !frog.getGlobalBounds().intersects(l4.getGlobalBounds())
				&& !frog.getGlobalBounds().intersects(l5.getGlobalBounds()) && !frog.getGlobalBounds().intersects(l6.getGlobalBounds())
				&& !frog.getGlobalBounds().intersects(l7.getGlobalBounds()) && !frog.getGlobalBounds().intersects(t1.getGlobalBounds())
				&& !frog.getGlobalBounds().intersects(t2.getGlobalBounds()) && !frog.getGlobalBounds().intersects(t3.getGlobalBounds())
				&& !frog.getGlobalBounds().intersects(t4.getGlobalBounds()) && !frog.getGlobalBounds().intersects(t5.getGlobalBounds())
				&& !frog.getGlobalBounds().intersects(t6.getGlobalBounds()) && !frog.getGlobalBounds().intersects(t7.getGlobalBounds())
				&& !frog.getGlobalBounds().intersects(t8.getGlobalBounds()) && !frog.getGlobalBounds().intersects(o.getGlobalBounds())
				&& !frog.getGlobalBounds().intersects(o2.getGlobalBounds()))
			{
				frog.setPosition(window.getSize().x / 2, window.getSize().y - 38.5);
				frog.setRotation(0);
				lives = lives - 1;
				live = std::to_string(lives);
				livesT.setString(live);
			}
		}

		// frog on log
		if (frog.getGlobalBounds().intersects(l1.getGlobalBounds()) || frog.getGlobalBounds().intersects(l2.getGlobalBounds())
			|| frog.getGlobalBounds().intersects(l3.getGlobalBounds()))
			frog.move(l1.getSpeed() / -100.0, 0);

		// frog on turtle
		if (frog.getGlobalBounds().intersects(t1.getGlobalBounds()) || frog.getGlobalBounds().intersects(t2.getGlobalBounds())
			|| frog.getGlobalBounds().intersects(t3.getGlobalBounds()) || frog.getGlobalBounds().intersects(t4.getGlobalBounds()) || frog.getGlobalBounds().intersects(t5.getGlobalBounds())
			|| frog.getGlobalBounds().intersects(t6.getGlobalBounds()))
			frog.move(t1.getSpeed() / 100.0, 0);

		// frog on more logs
		if (frog.getGlobalBounds().intersects(l4.getGlobalBounds()) || frog.getGlobalBounds().intersects(l5.getGlobalBounds()))
			frog.move(l4.getSpeed() / -100.0, 0);

		// frog on even more logs
		if (frog.getGlobalBounds().intersects(l6.getGlobalBounds()) || frog.getGlobalBounds().intersects(l7.getGlobalBounds()))
			frog.move(l6.getSpeed() / 100.0, 0);

		// frog on more turtles
		if (frog.getGlobalBounds().intersects(t7.getGlobalBounds()) || frog.getGlobalBounds().intersects(t8.getGlobalBounds()))
			frog.move(t7.getSpeed() / 100.0, 0);

		// frog on otters
		if (frog.getGlobalBounds().intersects(o.getGlobalBounds()) || frog.getGlobalBounds().intersects(o2.getGlobalBounds()))
			frog.move(o.getSpeed() / 100.0, 0);

		// collision with snake
		// this needs its own code because the snake and otter may overlap, in which case the frog dies
		if (frog.getGlobalBounds().intersects(s.getGlobalBounds()) || frog.getGlobalBounds().intersects(s2.getGlobalBounds()))
		{
			frog.setPosition(window.getSize().x / 2, window.getSize().y - 38.5);
			frog.setRotation(0);
			lives = lives - 1;
			live = std::to_string(lives);
			livesT.setString(live);
		}

		
		//collison in 1st row
		if (frog.getGlobalBounds().intersects(rc1.getGlobalBounds()) || frog.getGlobalBounds().intersects(rc2.getGlobalBounds())
			|| frog.getGlobalBounds().intersects(rc3.getGlobalBounds()) || frog.getGlobalBounds().intersects(rc4.getGlobalBounds())
			|| frog.getGlobalBounds().intersects(rc5.getGlobalBounds()) || frog.getGlobalBounds().intersects(rc6.getGlobalBounds()))
		{
			frog.setPosition(window.getSize().x / 2, window.getSize().y - 38.5);
			frog.setRotation(0);
			lives = lives - 1;
			live = std::to_string(lives);
			livesT.setString(live);
		}

		//collison in 2nd row
		if (frog.getGlobalBounds().intersects(gc1.getGlobalBounds()) || frog.getGlobalBounds().intersects(gc2.getGlobalBounds())
			|| frog.getGlobalBounds().intersects(gc3.getGlobalBounds()) || frog.getGlobalBounds().intersects(gc4.getGlobalBounds())
			|| frog.getGlobalBounds().intersects(gc5.getGlobalBounds()) || frog.getGlobalBounds().intersects(gc6.getGlobalBounds()))
		{
			frog.setPosition(window.getSize().x / 2, window.getSize().y - 38.5);
			frog.setRotation(0);
			lives = lives - 1;
			live = std::to_string(lives);
			livesT.setString(live);

		}

		//collison in 3rd row
		if (frog.getGlobalBounds().intersects(bc1.getGlobalBounds()) || frog.getGlobalBounds().intersects(bc2.getGlobalBounds())
			|| frog.getGlobalBounds().intersects(bc3.getGlobalBounds()) || frog.getGlobalBounds().intersects(bc4.getGlobalBounds())
			|| frog.getGlobalBounds().intersects(bc5.getGlobalBounds()))
		{
			frog.setPosition(window.getSize().x / 2, window.getSize().y - 38.5);
			frog.setRotation(0);
			lives = lives - 1;
			live = std::to_string(lives);
			livesT.setString(live);

		}

		//collison in 4th row 
		if (frog.getGlobalBounds().intersects(tc1.getGlobalBounds()) || frog.getGlobalBounds().intersects(tc2.getGlobalBounds())
			|| frog.getGlobalBounds().intersects(tc3.getGlobalBounds()) || frog.getGlobalBounds().intersects(tc4.getGlobalBounds()))
		{
			frog.setPosition(window.getSize().x / 2, window.getSize().y - 38.5);
			frog.setRotation(0);
			lives = lives - 1;
			live = std::to_string(lives);
			livesT.setString(live);
		}

		// frog ventures into the unknown
		if (frog.getPosition().x < 0 || frog.getPosition().x > 1280 || frog.getPosition().y < 0 || frog.getPosition().y > 900)
		{
			frog.setPosition(window.getSize().x / 2, window.getSize().y - 38.5);
			frog.setRotation(0);
			lives = lives - 1;
			live = std::to_string(lives);
			livesT.setString(live);
		}

		// collision with croc mouth
		if (frog.getGlobalBounds().intersects(cm1.getGlobalBounds()) || frog.getGlobalBounds().intersects(cm2.getGlobalBounds())
			|| frog.getGlobalBounds().intersects(cm3.getGlobalBounds()) || frog.getGlobalBounds().intersects(cm4.getGlobalBounds())
			|| frog.getGlobalBounds().intersects(cm5.getGlobalBounds()) || frog.getGlobalBounds().intersects(cm6.getGlobalBounds())
			|| frog.getGlobalBounds().intersects(cm7.getGlobalBounds()) || frog.getGlobalBounds().intersects(cm8.getGlobalBounds()))
		{
			frog.setPosition(window.getSize().x / 2, window.getSize().y - 38.5);
			frog.setRotation(0);
			lives = lives - 1;
			live = std::to_string(lives);
			livesT.setString(live);
		}

		// DRAWING OBJECTS AND DISPLAYING

		window.clear();
		window.draw(r4);
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
		window.draw(l1);
		window.draw(l2);
		window.draw(l3);
		window.draw(l6);
		window.draw(l7);
 		window.draw(c1);
		window.draw(c2);
		window.draw(c3);
		window.draw(c4);
		window.draw(c5);
		window.draw(t1);
		window.draw(t2);
		window.draw(t3);
		window.draw(t4);
		window.draw(t5);
		window.draw(t6);
		window.draw(t7);
		window.draw(t8);
		window.draw(l4);
		window.draw(l5);
		window.draw(l6);
		window.draw(l7);
		window.draw(r4);
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
		window.draw(o);
		window.draw(o2);
		window.draw(s);
		window.draw(s2);
		window.draw(frog);
		window.draw(frog_wifey);
		window.draw(cm1);
		window.draw(cm2);
		window.draw(cm3);
		window.draw(cm4);
		window.draw(cm5);
		window.draw(cm6);
		window.draw(cm7);
		window.draw(cm8);
		window.draw(text);
		window.draw(livesT);
		window.display();
	}

	return 0;
}
