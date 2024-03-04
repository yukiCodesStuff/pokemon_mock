#pragma once

#include "Player.h"

#ifndef GAME_H
#define GAME_H

/*
*	Game Engine Wrapper Class
*/
class Game
{
private:

	// Variables

	// Window
	sf::RenderWindow* window;
	Player* player;
	sf::VideoMode videoMode;
	sf::Event ev;

	// Private Functions
	void initVariables();
	void initPlayer();
	void initWindow();

public:

	// Constructors and Destructors
	Game();
	virtual ~Game();

	// Accessors
	const bool running() const;

	// Functions
	void update();
	void render();
};

#endif

