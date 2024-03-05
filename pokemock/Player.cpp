#include "Player.h"
#include <iostream>

void Player::initTexture()
{
	// load texture from file; dimensions are 548 x 828
	if (!this->texture.loadFromFile("./assets/playerSheet.png", sf::IntRect(0, 0, 548, 828))) {
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << std::endl;
	}
}

void Player::initSprite()
{
	// get frame from texture
	sf::IntRect rectSourceSprite(20, 0, 130, 170);

	// set texture to sprite
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(rectSourceSprite);

	// resize the sprite
	this->sprite.scale(.75f, .75f);
}

Player::Player()
{
	this->movementSpeed = 1.f;
	this->direction = DOWN;
	this->isMoving = false;

	this->initTexture();
	this->initSprite();
}

Player::~Player()
{
}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

void Player::update()
{
	// Animation update
	if (this->isMoving) {
		this->updateAnimation();
	}

	this->isMoving = false;
	this->sprite.setTextureRect(animationMap[this->direction][0]);
}

void Player::updateAnimation()
{
	// Check if the animation timer exceeds the frame time
	if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f) {
		size_t currentFrame = 0; // Move to the next frame
		currentFrame++;
		currentFrame = currentFrame % 4;

		this->sprite.setTextureRect(
			animationMap[this->direction][currentFrame]
		);

		this->animationTimer.restart(); // Restart the timer for the next frame
	}
}


void Player::render(sf::RenderTarget& target)
{
	this->update();
	target.draw(this->sprite);
}

void Player::setDirection(Direction direction)
{
	this->direction = direction;
}

void Player::setMoving(bool moving)
{
	this->isMoving = moving;
}
