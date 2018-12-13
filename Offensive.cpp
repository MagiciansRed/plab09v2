#include "stdafx.h"
#include "Offensive.h"
#include <iostream>
#include <time.h>


Offensive::Offensive()
{
}

Offensive::Offensive(int c_healthpoints, std::string c_description, int c_dmg, std::string c_battle_cry)
{
	health_points = c_healthpoints;
	description = c_description;
	dmg = c_dmg;
	battle_cry = c_battle_cry;
}
 
int Offensive::get_dmg()
{
	return dmg;
}

std::string Offensive::get_battle_cry()
{
	return battle_cry;
}

int roll_dX(int sides)
{
	int num = (0 + (rand() % (int)(sides + 1)));
	return num;
}

int Offensive::battle(std::shared_ptr<Base_class> hero)
{
	int number_of_rounds = 1;

	std::cout << this->get_battle_cry() << std::endl;
	std::cout << hero->get_battle_cry() << std::endl;
	while (this->health_points>0 && this->health_points>0)
	{
		std::cout << "Round " << number_of_rounds << std::endl;
		int hero_dmg = roll_dX(10) + hero->get_dmg();
		std::cout << "Hero strikes for " << hero_dmg << std::endl;
		this->health_points -= hero_dmg;
		if (this->health_points <= 0)
			break;
		int enemy_dmg = roll_dX(10) + this->get_dmg();
		std::cout << this->description << " hits for " << enemy_dmg << std::endl;
		hero->health_points -= enemy_dmg;
		if (hero->health_points <= 0)
			break;
		std::cout << "Hero is left with " << hero->health_points << " hp" << std::endl;
		std::cout << this->description << " has " << this->health_points << " hp" << std::endl;
		number_of_rounds++;

	}
	if (hero->health_points>0)
	{
		std::cout << "Hero is victorius!" << std::endl;
	}
	else
	{
		std::cout << "Hero has been slain" << std::endl;
	}
	std::cout << "########################" << std::endl;

	return number_of_rounds;
}

Offensive::~Offensive()
{
}
