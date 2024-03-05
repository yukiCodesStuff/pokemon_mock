#include "Player.h"
#include <iostream>

void Player::initTexture()
{
	// load texture from file
	if (!this->texture.loadFromFile("./assets/playerSheet.png", sf::IntRect(420, 0, 125, 200))) {
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << std::endl;
	}

	// populate sprite animation array
	this->frames[0].loadFromFile("./assets/playerSheet.png", sf::IntRect(10, 0, 125, 200));
	this->frames[1].loadFromFile("./assets/playerSheet.png", sf::IntRect(150, 0, 125, 200));
	this->frames[2].loadFromFile("./assets/playerSheet.png", sf::IntRect(290, 0, 125, 200));
	this->frames[3].loadFromFile("./assets/playerSheet.png", sf::IntRect(420, 0, 125, 200));
	this->frames[4].loadFromFile("./assets/playerSheet.png", sf::IntRect(0, 200, 120, 200));
	this->frames[5].loadFromFile("./assets/playerSheet.png", sf::IntRect(140, 200, 125, 200));
	this->frames[6].loadFromFile("./assets/playerSheet.png", sf::IntRect(280, 200, 125, 200));
	this->frames[7].loadFromFile("./assets/playerSheet.png", sf::IntRect(410, 200, 125, 200));
	this->frames[8].loadFromFile("./assets/playerSheet.png", sf::IntRect(10, 400, 125, 200));
	this->frames[9].loadFromFile("./assets/playerSheet.png", sf::IntRect(150, 400, 125, 200));
	this->frames[10].loadFromFile("./assets/playerSheet.png", sf::IntRect(290, 400, 125, 200));
	this->frames[11].loadFromFile("./assets/playerSheet.png", sf::IntRect(420, 400, 125, 200));
	this->frames[12].loadFromFile("./assets/playerSheet.png", sf::IntRect(0, 650, 125, 200));
	this->frames[13].loadFromFile("./assets/playerSheet.png", sf::IntRect(140, 650, 125, 200));
	this->frames[14].loadFromFile("./assets/playerSheet.png", sf::IntRect(280, 650, 125, 200));
	this->frames[15].loadFromFile("./assets/playerSheet.png", sf::IntRect(410, 650, 125, 200));
}

void Player::initSprite()
{
	// set texture to sprite
	this->sprite.setTexture(this->texture);

	// resize the sprite
	this->sprite.scale(1.f, 1.f);
}

Player::Player()
{
	this->movementSpeed = 1.f;

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
	if (this->animationTimer.getElapsedTime().asSeconds() >= 0.5f) // If one second has passed
	{
		this->animationTimer.restart(); // Restart the animation timer

		// Move to the next frame
		this->currentFrame++;
		if (this->currentFrame >= 4) // If we've exceeded the number of frames
			this->currentFrame = 0; // Loop back to the first frame

		// Update the sprite's texture to the current frame
		this->sprite.setTexture(this->frames[currentFrame]);
	}
}


void Player::render(sf::RenderTarget& target)
{
	this->update();
	target.draw(this->sprite);
}
