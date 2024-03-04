#include "Player.h"
#include <iostream>

void Player::initTexture()
{
	// load texture from file
	if (!this->texture.loadFromFile("./assets/playerSheet.png")) {
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << std::endl;
	}
}

void Player::initSprite()
{
	// set texture to sprite
	this->sprite.setTexture(this->texture);
}

Player::Player()
{
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{
}

void Player::update()
{
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
