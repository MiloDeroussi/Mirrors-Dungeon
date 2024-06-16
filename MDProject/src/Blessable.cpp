#include "Blessable.h"
#include <iostream>

using namespace std;

Blessable::Blessable(double max_h) : health(max_h), max_health(max_h) {}

void Blessable::death() {
	alive = false;
}

void Blessable::doDamage(double damage) {
	health -= damage;
	if (health <= 0) {
		health = 0;
		death();
	}
}

double Blessable::getHealth() const {
	return health;
}

double Blessable::getMaxHealth() const {
	return max_health;
}

bool Blessable::getAlive() const {
	return alive;
}