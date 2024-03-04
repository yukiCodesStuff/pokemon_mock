#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

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
	sf::VideoMode videoMode;
	sf::Event ev;

	// Private Functions
	void initVariables();
	void initWindow();

public:

	// Constructors and Destructors
	Game();
	virtual ~Game();

	// Accessors
	const bool running() const;

	// Functions
	void pollEvents();
	void update();
	void render();
};

#endif

