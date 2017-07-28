#include "hero_.h"



hero_::hero_()
{
	position_x = 32;
	position_y = 96;
	goal_x = 32;
	goal_y = 96;
	v = 50;
	pose = 0;

	if (!image.loadFromFile("images/hero/hero.png"))
		std::cout << "Can't Open image for hero" << std::endl;
	else
	{
		image.createMaskFromColor(sf::Color(255, 255, 255), 0);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
	}

}


hero_::~hero_()
{
}

void hero_::draw()
{
	sprite.setPosition(position_x - 32, position_y - 96);

	switch (pose)
	{
	case 0:
		sprite.setTextureRect(sf::IntRect(0, 0, 64, 96));
		break;
	case 1:
		sprite.setTextureRect(sf::IntRect(64, 0, 64, 96));
		break;
	case 2:
		sprite.setTextureRect(sf::IntRect(128, 0, 64, 96));
		break;
	case 3:
		sprite.setTextureRect(sf::IntRect(192, 0, 64, 96));
		break;
	case 4:
		sprite.setTextureRect(sf::IntRect(0, 96, 64, 96));
		break;
	case 5:
		sprite.setTextureRect(sf::IntRect(64, 96, 64, 96));
		break;
	case 6:
		sprite.setTextureRect(sf::IntRect(128, 96, 64, 96));
		break;
	}

	Window->draw(sprite);
}

void hero_::control()
{
	if (event_.type == sf::Event::MouseButtonPressed)
	{
		if (event_.mouseButton.button == sf::Mouse::Left)
		{
			goal_x = event_.mouseButton.x;
			goal_y = event_.mouseButton.y;
		}
	}
	else if (event_.type == sf::Event::KeyPressed)
	{
		switch (event_.key.code)
		{
		case sf::Keyboard::Right:
			goal_x += 10;
			break;
		case sf::Keyboard::Left:
			goal_x -= 10;
			break;
		case sf::Keyboard::Up:
			goal_y -= 10;
			break;
		case sf::Keyboard::Down:
			goal_y += 10;
			break;
		}
	}

	if (MovePosition(&position_x, &position_y, (float)goal_x, (float)goal_y, v) == 0)
		pose = 0;
	else
	{
		switch (pose)
		{
		case 0:
			if (goal_x >= position_x)
				pose = 1;
			else
				pose = 4;
			break;
		case 1:
		case 2:
		case 3:
			if (goal_x >= position_x)
				pose = 1 + pose % 3;
			else
				pose = 4;
			break;
		case 4:
		case 5:
		case 6:
			if (goal_x < position_x)
				pose = 4 + pose % 3;
			else
				pose = 1;
			break;
		}
	}

}