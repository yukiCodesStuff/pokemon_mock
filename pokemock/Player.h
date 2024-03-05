#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <windows.h>
#define sleep(x) Sleep(1000 * (x))

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
	sf::Clock animationTimer; // Timer for animation updates
	size_t currentFrame; // Index of the current frame to display

	sf::Sprite sprite;
	sf::Texture texture;
	sf::Texture frames[16];

	float movementSpeed;

	// Private Functions
	void initTexture();
	void initSprite();
public:
	Player();
	virtual ~Player();

	void move(const float dirX, const float dirY);

	void update();
	void render(sf::RenderTarget& target);
};

#endif
