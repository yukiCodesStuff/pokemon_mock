#include "Entity.h"

Entity::Entity(sf::Texture* texture, std::string textureName, float x, float y)
{
	this->texture = texture;
	this->textureName = textureName;
	if (!this->setUpSprite(texture)) {
		std::cout << "ENTITY::ERROR: Failed to set up sprite" << std::endl;
		return;
	}
	this->pos = sf::Vector2f(x, y);
	this->sprite.setPosition(this->pos);
}

Entity::~Entity()
{
}

bool Entity::setUpSprite(sf::Texture*)
{
	this->sprite.setTexture(*this->texture);
	this->sprite.setTextureRect(entityMap[this->textureName]); // tweak this later
	// this->sprite.scale(.5f, .5f);
	return true;
}
