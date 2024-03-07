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

	int worldSizex;
	int worldSizey;

	void initState();
	void initEnemyPositions();
	void initWorldTexture();
	void setUpEntities();
	void setUpTiles();

	void loadLevel(std::string);
public:
	vvg tiles;
	ve entities;
	GameWorld(std::string);
	~GameWorld();
	void render(sf::RenderTarget &target);
};

#endif
