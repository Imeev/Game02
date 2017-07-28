#include <SFML/Graphics.hpp>

#include "Global_variables.h"
#include "Map.h"

//#include "Engine.h"
#include "hero_.h"

void Rungame()
{
	Map map;

	map.LoadTiles("images/map_tiles.png");

	sf::Clock clock;

	double start_time, end_time;

	hero_ *hero = new hero_;

	//engine->data[0] = hero;

	for (;;)
	{
		start_time = clock.restart().asMilliseconds();

		map.MapWindow("tiles_for_map.txt");

		Window->pollEvent(event_);

		if ((event_.type == sf::Event::Closed) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) || (!Window->isOpen())) break;

		//engine->data[0]->control();
		//engine->data[0]->draw();
		hero->control();
		hero->draw();

		Window->display();

		end_time = clock.getElapsedTime().asMilliseconds();

		while (end_time < start_time + 10)
		{
			sf::sleep(sf::milliseconds(1));
			end_time = clock.getElapsedTime().asMilliseconds();
		}
	}

}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 800), __FILE__, sf::Style::Default);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(25);

	Window = &window;

	Rungame();

	//engine->~Engine();
}