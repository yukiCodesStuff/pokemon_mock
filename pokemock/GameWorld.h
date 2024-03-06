#pragma once

#include "Utils.h"
#include "GameTile.h"

#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#define vvg std::vector<std::vector<GameTile*>>
#define v2i std::vector<sf::Vector2i>

class GameWorld
{
private:
	sf::Vector2i exitPos;
	sf::Vector2i playerPos;
	v2i enemyPositions;
	void initState();
	void initEnemyPositions();
	void setUpTiles();
public:
	vvg tiles;
	int gridLength;
	GameWorld();
};

#endif
