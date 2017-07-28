#include "Map.h"



Map::Map()
{
	map_height = Window->getSize().y / 32;
	map_width = Window->getSize().x / 32;
}


Map::~Map()
{
}

int Map::LoadTiles(const std::string &filename)
{
	if (map_image.loadFromFile(filename))
	{
		map_texture.loadFromImage(map_image);
		map_sprite.setTexture(map_texture);

		return 0;
	}
	else
		return -1;
}

int Map::MapWindow(const char* tilesfile)
{
	std::ifstream fp(tilesfile);

	if (!fp.is_open())
		return -1;

	char a;

	for (auto i = 0; i < map_height; i++)
	{
		for (auto j = 0; j < map_width; j++)
		{
			if (fp.eof())
				return -2;
			fp >> a;
			map_sprite.setTextureRect(sf::IntRect((a - 49) * 32, 0, 32, 32));
			map_sprite.setPosition((float)j * 32, (float)i * 32);
			Window->draw(map_sprite);
		}
	}
	if (!fp.eof())
		return 1;
	else
		return 0;
}