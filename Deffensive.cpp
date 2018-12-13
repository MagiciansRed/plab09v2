#include "stdafx.h"
#include "Deffensive.h"
#include <iostream>


Deffensive::Deffensive(int c_health_points, std::string c_description, int c_resistance, int c_size)
{
	health_points = c_health_points;
	description = c_description;
	resistance = c_resistance;
	size = c_size;
}

int Deffensive::get_resistance()
{
	return resistance;
}

int Deffensive::get_size()
{
	return size;
}

int roll_dXx(int sides)
{
	int num = (0 + (rand() % (int)(sides + 1)));
	return num;
}

int Deffensive::battle(std::shared_ptr<Base_class> hero)
{
	int number_of_rounds = 1;
	std::cout << "Hero encounters an obstacle!" << std::endl;
	while (this->health_points>0)
	{
		std::cout << "Round " << number_of_rounds << std::endl;
		int hero_roll = roll_dXx(10);
		int hero_dmg = hero_roll + this->get_dmg() - this->get_resistance();
		if (hero_dmg <= 0)
			hero_dmg = 0;
		std::cout << "Hero strikes for " << hero_dmg << std::endl;
		this->health_points -= hero_dmg;
		if (this->health_points <= 0)
		{
			std::cout << "Hero managed to destory the obstacle" << std::endl;
			break;
		}
		number_of_rounds++;
		if (number_of_rounds % 4 == 0)
		{
			std::cout << "Hero is trying to force his way through the obstacle" << std::endl;
			if (hero_dmg >= this->get_size() * 2)
			{
				std::cout << "And he succeeded" << std::endl;
				break;
			}
			else
			{
				std::cout << "But he was unsuccessful" << std::endl;
			}

		}
	}
	std::cout << "########################" << std::endl;
	return number_of_rounds;
}



Deffensive::Deffensive()
{
}

Deffensive::~Deffensive()
{
}
