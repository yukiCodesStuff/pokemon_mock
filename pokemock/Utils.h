#ifndef UTILS_H
#define UTILS_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

enum Direction { UP, DOWN, LEFT, RIGHT };

// Custom hash function for the Direction enum
struct DirectionHash {
    std::size_t operator()(const Direction& direction) const noexcept {
        return std::hash<int>()(static_cast<int>(direction));
    }
};

extern std::unordered_map<Direction, std::vector<sf::IntRect>, DirectionHash> animationMap;
extern std::unordered_map<std::string, sf::IntRect> tileMap;
extern std::unordered_map<std::string, sf::IntRect> entityMap;

#endif
