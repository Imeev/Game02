#pragma once

#include "object_.h"
#include "Global_variables.h"


class Engine
{
public:

	object_ **data;

	int N;

	Engine();
	~Engine();

	int add(object_ *obj);
	int remove(object_ *obj);
};

