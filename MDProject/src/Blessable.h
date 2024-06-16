#pragma once
#include "SFML/Graphics.hpp"

class Blessable {
private:
	double health;
	double max_health;
	bool alive = true;

public:
	explicit Blessable(double max_h);
	void doDamage(double damage);
	void death();
	double getHealth() const;
	double getMaxHealth() const;
	bool getAlive() const;
};