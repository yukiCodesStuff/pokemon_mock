#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include "Utils.h"

class Entity
{
private:
public:
	Entity(sf::Texture*, std::string, float, float);
	~Entity();

	sf::Texture* texture; // use a single texture sheet
	sf::Sprite sprite;
	std::string textureName;
	sf::Vector2f pos;
	bool setUpSprite(sf::Texture*);
};

#endif
