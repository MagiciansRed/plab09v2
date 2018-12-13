#pragma once
#include <string>
#include <memory>

class Base_class
{
public:
	int health_points;
	std::string description;
	Base_class();
	~Base_class();
	virtual std::string get_battle_cry();
	virtual int get_dmg();
	virtual int get_resistance();
	virtual int get_size();
	virtual int battle(std::shared_ptr<Base_class>);
};

