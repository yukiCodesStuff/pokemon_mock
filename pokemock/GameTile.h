#pragma once

#ifndef GAMETILE_H
#define GAMETILE_H

#include "Utils.h"

class GameTile
{
public:
	bool isPassable; // handling free ground and walls
	bool isExit;
	sf::Vector2f pos; 
	sf::Texture* texture; // use a single texture sheet
	sf::Sprite sprite; // 414 from top, 128 x 128

	GameTile(sf::Texture*, float, float, bool, bool);
	bool setUpSprite(sf::Texture*);
};

#endif
