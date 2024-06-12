#pragma once
#include "SFML/Graphics.hpp"

class Blessable {
private:
	double health;
	double max_health;
	bool alive = true;
public:
	explicit Blessable(double max_h);
	void getDamage(double damage);
	void death();
	double getHealth();
	double getMaxHealth();
};