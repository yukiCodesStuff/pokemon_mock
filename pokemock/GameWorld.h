#pragma once

#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "GameTile.h"

#define vvg std::vector<std::vector<GameTile*>>
#define v2i std::vector<sf::Vector2i>

class GameWorld
{
private:
	sf::Texture worldTexture;
	sf::Vector2i exitPos;
	sf::Vector2i playerPos;
	v2i enemyPositions;
	void initState();
	void initEnemyPositions();
	void initWorldTexture();
	void setUpTiles();
public:
	vvg tiles;
	int gridLength;
	GameWorld();
	~GameWorld();
	void render(sf::RenderTarget &target);
};

#endif
