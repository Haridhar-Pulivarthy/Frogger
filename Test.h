#pragma once

#include "Frog.hpp"
#include "otter.hpp"
#include "snake.hpp"

void testOffOfScreen(Frog& frogger, sf::RenderWindow& window);

void testCarCollision(Frog& frogger, sf::RenderWindow& window);

void testWin(Frog& frogger, sf::RenderWindow& window);

void testOutOfLives(Frog& frogger, sf::RenderWindow& window);

void snakeAndOtterCollision(Frog& frogger, Otter& o, Snake& s, sf::RenderWindow& window);