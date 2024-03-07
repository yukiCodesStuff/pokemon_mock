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

void Game::initGameWorld()
{
	this->gameWorld = new GameWorld(20);
}

void Game::initWindow()
{
	// window size
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	// Full Screen
	// this->videoMode.getDesktopMode();

	this->window = new sf::RenderWindow(this->videoMode, "Pokemock", sf::Style::Titlebar | sf::Style::Close);
	// this->window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Pokemock", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

// Constructors and Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initGameWorld();
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

	// move player; only allow player to move in one direction at a time
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->player->setDirection(LEFT);
		this->player->move(-1.0f, 0.f);
		this->player->setMoving(true);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->player->setDirection(RIGHT);
		this->player->move(1.0f, 0.f);
		this->player->setMoving(true);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		this->player->setDirection(UP);
		this->player->move(0.f, -1.f);
		this->player->setMoving(true);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		this->player->setDirection(DOWN);
		this->player->move(0.f, 1.f);
		this->player->setMoving(true);
	}
	else {
		this->player->setMoving(false);
	}
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

	this->window->clear(sf::Color::Red); // clear to black window

	// Draw map
	this->gameWorld->render(*this->window);
	
	// Draw game objects
	this->player->render(*this->window);
	
	this->window->display();
}
