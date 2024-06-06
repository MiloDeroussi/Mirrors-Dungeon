#include "Ennemi.h"

using namespace std;

Ennemi::Ennemi(double health, double x, double y, string pattern) : Blessable(health) {
	this->x = x;
	this->y = y;
	this->MovePattern = pattern;
}

void Ennemi::draw() {

}

void Ennemi::move(string pattern) {

}
