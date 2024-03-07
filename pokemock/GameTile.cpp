#include "GameTile.h"

GameTile::GameTile(sf::Texture* texture, std::string textureName, float x, float y, bool passable, bool exit)
{
	this->texture = texture;
	this->textureName = textureName;
	if (!this->setUpSprite(texture)) {
		std::cout << "GAMETILE::ERROR: Failed to set up sprite" << std::endl;
		return;
	}
	this->pos = sf::Vector2f(x, y);
	this->sprite.setPosition(this->pos);
	this->isPassable = passable;
	this->isExit = exit;
}

bool GameTile::setUpSprite(sf::Texture* texture)
{
	this->sprite.setTexture(*this->texture);
	this->sprite.setTextureRect(tileMap[this->textureName]); // tweak this later
	this->sprite.scale(.5f, .5f);
	return true;
}
