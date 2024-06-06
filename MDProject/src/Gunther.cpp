#include "Gunther.h"

using namespace std;

Gunther::Gunther(double health, double damage) : Blessable(health) {
	this->damage = damage;
}