#include "Utils.h"

std::unordered_map<Direction, std::vector<sf::IntRect>, DirectionHash> animationMap = {
	{UP,    {sf::IntRect(0, 240, 130, 170), sf::IntRect(123, 240, 130, 170), sf::IntRect(255, 240, 130, 170), sf::IntRect(386, 240, 130, 170)}},
	{DOWN,  {sf::IntRect(20, 0, 130, 170), sf::IntRect(150, 0, 130, 170), sf::IntRect(280, 0, 130, 170), sf::IntRect(410, 0, 130, 170)}},
	{LEFT,  {sf::IntRect(20, 445, 130, 170), sf::IntRect(150, 445, 130, 170), sf::IntRect(280, 445, 130, 170), sf::IntRect(410, 445, 130, 170)}},
	{RIGHT, {sf::IntRect(0, 655, 130, 170), sf::IntRect(123, 655, 130, 170), sf::IntRect(255, 655, 130, 170), sf::IntRect(386, 655, 130, 170)}}
};

std::unordered_map<std::string, sf::IntRect> tileMap = {
		{"GRASS", sf::IntRect(0, 416, 128, 128)},
		{"BRICK", sf::IntRect(0, 2944, 128, 128)}
};

std::unordered_map<std::string, sf::IntRect> entityMap = {
	{"TREE", sf::IntRect(0, 9604, 128, 200)}
};