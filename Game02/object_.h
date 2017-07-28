#pragma once

#include <SFML/graphics.hpp>
#include <iostream>

//#include "Engine.h"

class object_
{
public:

	float position_x, position_y;
	float v;

	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

	object_();
	~object_();

	virtual void draw();
	virtual void control();
};

