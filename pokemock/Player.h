#pragma once

#include "Utils.h"
#include <windows.h>
#define sleep(x) Sleep(1000 * (x))

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
	sf::Clock animationTimer; // Timer for animation updates

	sf::Sprite sprite;
	sf::Texture texture;
	std::unordered_map<Direction, std::vector<sf::IntRect>, DirectionHash> animationMap = {
	{UP,    {sf::IntRect(0, 240, 130, 170), sf::IntRect(123, 240, 130, 170), sf::IntRect(255, 240, 130, 170), sf::IntRect(386, 240, 130, 170)}},
	{DOWN,  {sf::IntRect(20, 0, 130, 170), sf::IntRect(150, 0, 130, 170), sf::IntRect(280, 0, 130, 170), sf::IntRect(410, 0, 130, 170)}},
	{LEFT,  {sf::IntRect(20, 445, 130, 170), sf::IntRect(150, 445, 130, 170), sf::IntRect(280, 445, 130, 170), sf::IntRect(410, 445, 130, 170)}},
	{RIGHT, {sf::IntRect(0, 655, 130, 170), sf::IntRect(123, 655, 130, 170), sf::IntRect(255, 655, 130, 170), sf::IntRect(386, 655, 130, 170)}}
	};

	float movementSpeed;
	bool isMoving;
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
