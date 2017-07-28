#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

#include "Global_variables.h"

class Map
{
public:

	int map_height;
	int map_width;

	sf::Image map_image;
	sf::Texture map_texture;
	sf::Sprite map_sprite;

	Map();
	~Map();

	int LoadTiles(const std::string &filename);

	int MapWindow(const char* tilesfile);

};

