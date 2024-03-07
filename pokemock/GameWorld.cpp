#include "GameWorld.h"

#define vgt std::vector<GameTile*>

void GameWorld::initState()
{
	this->exitPos = sf::Vector2i(1, 0);
	this->playerPos = sf::Vector2i(gridLength - 1, gridLength - 1);
	this->initEnemyPositions();
	this->setUpTiles();
	this->setUpEntities();
}

void GameWorld::initEnemyPositions()
{
	this->enemyPositions.clear();
	// consider adding "enemies" later
}

void GameWorld::initWorldTexture()
{
	if (!this->worldTexture.loadFromFile("./assets/tileset.png", sf::IntRect(0, 0, 256, 13000))) {
		std::cout << "ERROR::GAMEWORLD::INITWORLDTEXTURE::Could not load texture file." << std::endl;
		return;
	}
}

void GameWorld::setUpEntities()
{
	this->entities.clear();
	// hard coding this in
	this->entities.resize(6);
	this->entities[0] = new Entity(&this->worldTexture, "TREE", 0, 0);
	this->entities[1] = new Entity(&this->worldTexture, "TREE", 128, 0);
	this->entities[2] = new Entity(&this->worldTexture, "TREE", 256, 0);
	this->entities[3] = new Entity(&this->worldTexture, "TREE", 0, 128);
	this->entities[4] = new Entity(&this->worldTexture, "TREE", 128, 128);
	this->entities[5] = new Entity(&this->worldTexture, "TREE", 256, 128);
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
			if ((i == this->gridLength / 2 || i == this->gridLength / 2 + 1) || 
				(j == this->gridLength / 2 || j == this->gridLength / 2 + 1)) {
				row[j] = new GameTile(&this->worldTexture, "BRICK", offsetX, offsetY, true, false);
			}
			else {
				row[j] = new GameTile(&this->worldTexture, "GRASS", offsetX, offsetY, true, false);
			}
			offsetX += 64;
		}
		tiles[i] = row;
		offsetY += 64;
	}
}

GameWorld::GameWorld(int worldSize)
{
	this->gridLength = worldSize;
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

	for (Entity* entity : this->entities) {
		// std::cout << entity->pos.x << "," << entity->pos.y << std::endl;
		target.draw(entity->sprite);
	}
}
