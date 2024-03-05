#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <unordered_map>
#include <vector>

enum Direction { UP, DOWN, LEFT, RIGHT };

// Custom hash function for the Direction enum
struct DirectionHash {
    std::size_t operator()(const Direction& direction) const noexcept {
        return std::hash<int>()(static_cast<int>(direction));
    }
};