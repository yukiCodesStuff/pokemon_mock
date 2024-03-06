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

void GameWorld::initWorldTexture()
{
	if (!this->worldTexture.loadFromFile("./assets/tileset.png", sf::IntRect(0, 0, 256, 3828))) {
		std::cout << "ERROR::GAMEWORLD::INITWORLDTEXTURE::Could not load texture file." << std::endl;
		return;
	}
}

void GameWorld::setUpTiles()
{
	this->tiles.clear();
	this->tiles.resize(gridLength);
	float offsetY = 0;
	for (int i = 0; i < this->gridLength; ++i) {
		vgt row(gridLength);
		float offsetX = 0;
		for (int j = 0; j < gridLength; ++j) {
			row[j] = new GameTile(&this->worldTexture, offsetX, offsetY, true, false);
			offsetX += 128;
		}
		tiles[i] = row;
		offsetY += 128;
	}
}

GameWorld::GameWorld()
{
	this->gridLength = 8;
	this->initWorldTexture();
	this->initState();
}

GameWorld::~GameWorld()
{
}

void GameWorld::render(sf::RenderTarget &target)
{
	for (int i = 0; i < this->gridLength; ++i) {
		for (int j = 0; j < gridLength; ++j) {
			target.draw(this->tiles[i][j]->sprite);
		}
	}
}
