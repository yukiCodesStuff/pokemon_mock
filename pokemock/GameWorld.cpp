#include "GameWorld.h"

#define vgt std::vector<GameTile*>

void GameWorld::initState()
{
	this->exitPos = sf::Vector2i(1, 0);
	this->playerPos = sf::Vector2i(300, 200);
	this->initEnemyPositions();
	// this->setUpTiles();
	// this->setUpEntities();
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
	this->tiles.resize(this->worldSizey);
	float offsetY = 0;
	for (int i = 0; i < this->worldSizey; ++i) {
		vgt row(this->worldSizex);
		float offsetX = 0;
		for (int j = 0; j < this->worldSizex; ++j) {
			row[j] = new GameTile(&this->worldTexture, "GRASS", offsetX, offsetY, true, false);
			offsetX += 64;
		}
		tiles[i] = row;
		offsetY += 64;
	}
}

void GameWorld::loadLevel(std::string filename)
{
	std::ifstream LevelFile(filename);
	std::string rowString;

	this->tiles.clear();
	this->entities.clear();
	float offsetY = 0;

	while (getline(LevelFile, rowString)) {
		if (!this->worldSizex) this->worldSizex = rowString.size();
		this->worldSizey++;

		std::cout << rowString << std::endl;

		vgt row(this->worldSizex);
		float offsetX = 0;
		for (int i = 0; i < this->worldSizex; ++i) {
			if (charTileMap.find(rowString[i]) != charTileMap.end()) {
				row[i] = new GameTile(&this->worldTexture, charTileMap[rowString[i]], offsetX, offsetY, true, false);
			}
			else {
				row[i] = new GameTile(&this->worldTexture, "GRASS", offsetX, offsetY, true, false);
				this->entities.push_back(new Entity(&this->worldTexture, charEntityMap[rowString[i]], offsetX, offsetY));
			}
			offsetX += 64;
		}
		this->tiles.push_back(row);
		offsetY += 64;
	}
	LevelFile.close();
}

GameWorld::GameWorld(std::string filename)
{
	this->worldSizex = 0;
	this->worldSizey = 0;
	this->loadLevel(filename);
	this->initWorldTexture();
	this->initState();
}

GameWorld::~GameWorld()
{
}

void GameWorld::render(sf::RenderTarget &target)
{
	for (int i = 0; i < this->worldSizey; ++i) {
		for (int j = 0; j < this->worldSizex; ++j) {
			target.draw(this->tiles[i][j]->sprite);
		}
	}

	for (Entity* entity : this->entities) {
		// std::cout << entity->pos.x << "," << entity->pos.y << std::endl;
		target.draw(entity->sprite);
	}
}
