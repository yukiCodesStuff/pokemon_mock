#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Utils.h"
#include <windows.h>

class Player
{
private:
	sf::Clock animationTimer; // Timer for animation updates

	sf::Sprite sprite;
	sf::Texture texture;

	float movementSpeed;
	bool isMoving;
	size_t currentFrame;
	Direction direction;

	// Private Functions
	void initTexture();
	void initSprite();
public:
	Player();
	virtual ~Player();

	void move(const float dirX, const float dirY);

	void update();
	void updateAnimation();
	void render(sf::RenderTarget& target);
	void setDirection(Direction direction);
	void setMoving(bool moving);
};

#endif
