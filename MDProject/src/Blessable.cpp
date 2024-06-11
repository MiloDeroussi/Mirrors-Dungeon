#include "Blessable.h"
#include <iostream>

using namespace std;

Blessable::Blessable(double max_h) {
	this->health = max_h;
	this->max_health = max_h;
}

void Blessable::getDamage(double damage) {
	health -= damage;
	if (health <= 0) {
		health = 0;
		death();
	}
}

void Blessable::death() {
	alive = false;
}

double Blessable::getHealth() {
	return health;
}

double Blessable::getMaxHealth() {
	return max_health;
}