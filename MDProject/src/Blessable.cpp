#include "Blessable.h"

using namespace std;

Blessable::Blessable(double max_h) {
	this->health = max_h;
	this->max_health = max_h;
}

void Blessable::getDamage(double damage) {

}

void Blessable::death() {

}