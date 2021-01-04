#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

constexpr auto W_WIDTH = 1216.f;
constexpr auto W_HEIGHT = 640.f;
constexpr auto FLOOR_H = 50.f;

struct Level {
	sf::Vector2f location;  //position of entity
	int orientation;  //orientagion 0 = vertical
} level_1[15];






