#include "Gunther.h"

using namespace std;

Gunther::Gunther(double health) : Blessable(health) {}

BouclierMiroir& Gunther::getBouclier() {
	return bouclier;
}

Pistolet& Gunther::getPistolet() {
	return pistolet;
}