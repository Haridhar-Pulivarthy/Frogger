#include "Test.h"
#include "snake.hpp"
#include "otter.hpp"

void testOffOfScreen(Frog& frogger, sf::RenderWindow& window)
{
	// set the position of the frog outside of the window
	frogger.setPosition(window.getSize().x + 100, window.getSize().y + 100);

	// test is successful because the frog immediately loses one life
}

void testCarCollision(Frog& frogger, sf::RenderWindow& window)
{
	// set the position of the frog on top of a car
	frogger.setPosition(window.getSize().x - 60, window.getSize().y - 137.5);

	// test is successful because the frog immediately loses one life
}

void testWin(Frog& frogger, sf::RenderWindow& window)
{
	// set the position of the frog on top of the other frog, which should mean that the player has won
	frogger.setPosition(window.getSize().x - 666, window.getSize().y - 888);

	// test is successful because the "You Win" message appears
}

void testOutOfLives(Frog& frogger, sf::RenderWindow& window)
{
	// make the frog go in the water every event loop
	frogger.setPosition(0, window.getSize().y - 525);

	// test is successful because the frog loses all of its lives and the "You Lose" message appears
}

void snakeAndOtterCollision(Frog& frogger, Otter& o, Snake& s, sf::RenderWindow& window)
{
	// set the position of the frog on top of a snake and an otter simultaneously, because that can happen sometimes
	// in this case, the frog should lose a life
	frogger.setPosition(window.getSize().x - 50, window.getSize().y - 805);
	s.setPosition(window.getSize().x - 50, window.getSize().y - 805);

	// test is successful because the frog loses a life
}