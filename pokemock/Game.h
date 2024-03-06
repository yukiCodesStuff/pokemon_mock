#pragma once

#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "GameWorld.h"
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
	GameWorld* gameWorld;
	sf::VideoMode videoMode;
	sf::Event ev;

	// Private Functions
	void initVariables();
	void initPlayer();
	void initGameWorld();
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

