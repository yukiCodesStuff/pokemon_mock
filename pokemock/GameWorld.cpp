#include "GameWorld.h"

#define vgt std::vector<GameTile*>

void GameWorld::initState()
{
	this->exitPos = sf::Vector2i(1, 0);
	this->playerPos = sf::Vector2i(gridLength - 1, gridLength - 1);
	this->initEnemyPositions();
	this->setUpTiles();
}

void GameWorld::initEnemyPositions()
{
	this->enemyPositions.clear();
	// consider adding "enemies" later
}

void GameWorld::setUpTiles()
{
	this->tiles.clear();
	vgt firstRow;
	//firstRow.push_back(new GameTile(""));
}

GameWorld::GameWorld()
{
	this->gridLength = 8;
	this->initState();
}
