#include "Game.h"

// Private Functions
void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initPlayer()
{
	this->player = new Player();
}

void Game::initWindow()
{
	// window size
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	// Full Screen
	// this->videoMode.getDesktopMode;

	this->window = new sf::RenderWindow(this->videoMode, "Pokemock", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

// Constructors and Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initPlayer();
}

Game::~Game()
{
	delete this->window;
	delete this->player;
}

// Accessors

const bool Game::running() const
{
	return this->window->isOpen();
}

// Functions
void Game::update()
{
	sf::Event e;
	while (this->window->pollEvent(e)) {
		if (e.type == sf::Event::Closed) {
			this->window->close();
		}
		if (e.KeyPressed && e.key.code == sf::Keyboard::Escape) {
			this->window->close();
		}
	}

	// move player
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

	this->window->clear(); // clear to black window
	
	// Draw game objects
	this->player->render(*this->window);
	
	this->window->display();
}
