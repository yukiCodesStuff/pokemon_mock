#pragma once

#include "Utils.h"

#ifndef GAMETILE_H
#define GAMETILE_H

class GameTile
{
public:
	bool isPassable; // handling free ground and walls
	bool isExit;
	sf::Vector2f pos;
	sf::Texture texture;
	sf::Sprite sprite;

	GameTile(std::string, float, float, bool, bool);
	bool setUpSprite(std::string);
};

#endif
