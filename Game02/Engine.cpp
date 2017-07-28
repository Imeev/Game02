#include "Engine.h"



Engine::Engine()
{
	N = 1;
	data = static_cast<object_ **>(malloc(N * sizeof(object_ *)));
}


Engine::~Engine()
{
	free(engine);
}

int Engine::add(object_ *obj)
{
	data = static_cast<object_ **>(realloc(data, ++N * sizeof(object_ *)));
	data[N - 1] = obj;
	
	return 1;
}

int Engine::remove(object_ *obj)
{
	int j = -1;

	for (auto i = 0; i < N; i++)
		if (data[i] == obj)
		{
			j = i;
			break;
		}

	if (j == -1)
		return -1;

	for (auto i = j; j < N - 1; j++)
		data[j] = data[j + 1];

	data = static_cast<object_ **>(realloc(data, --N * sizeof(object_ *)));

	return 0;
}