#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	// Private Functions
	void initTexture();
	void initSprite();
public:
	Player();
	~Player();

	void update();
	void render(sf::RenderTarget& target);
};

#endif
