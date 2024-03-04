#include "Game.h"

// Private Functions
void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	// window size
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	// Full Screen
	// this->videoMode.getDesktopMode;

	this->window = new sf::RenderWindow(this->videoMode, "Pokemock", sf::Style::Titlebar | sf::Style::Close);
}

// Constructors and Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

// Accessors

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev)) {
		switch (this->ev.type) {
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

// Functions
void Game::update()
{
	this->pollEvents();
}

void Game::render()
{
	/*
		@return void
		Renders game objects
		- clear old frame
		- render objects
		- display frame in window
	*/

	this->window->clear(sf::Color(255, 0, 0, 255));
	
	// Draw game objects
	
	this->window->display();
}
