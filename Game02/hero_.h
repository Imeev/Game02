#pragma once
#include "object_.h"
#include "Global_functions.h"
#include "Global_variables.h"

class hero_ :
	public object_
{
public:

	int health;
	int pose;

	int goal_x, goal_y;

	hero_();
	~hero_();

	void draw() override;
	void control() override;

};

