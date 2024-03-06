#include "GameTile.h"

GameTile::GameTile(std::string textureName, float x, float y, bool passable, bool exit)
{
	if (!setUpSprite(textureName)) {
		return;
	}
	this->pos = sf::Vector2f(x, y);
	this->sprite.setPosition(this->pos);
	this->isPassable = passable;
	this->isExit = exit;
}

bool GameTile::setUpSprite(std::string textureName)
{
	if (!this->texture.loadFromFile(textureName)) {
		return false;
	}
	this->texture.setSmooth(true); // make sure edges are not blurry
	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(sf::IntRect(0, 0, 50, 50)); // tweak this later
	return true;
}
