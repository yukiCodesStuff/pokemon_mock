#pragma once

#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "GameTile.h"
#include "Entity.h"

#define vvg std::vector<std::vector<GameTile*>>
#define ve std::vector<Entity*>
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
	void setUpEntities();
	void setUpTiles();
public:
	vvg tiles;
	ve entities;
	int gridLength;
	GameWorld(int);
	~GameWorld();
	void render(sf::RenderTarget &target);
};

#endif
