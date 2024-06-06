#include "Offensif.h"
#include <string>

using namespace std;

Offensif::Offensif(double health, double x, double y, string pattern, double attack) : Ennemi(health, x, y, pattern) {
	this->attack = attack;
	vector<Balle> munitions;
	for (int i = 0; i < mun_max; i++) {
		Balle balle(false, x, y, 20);
		munitions.push_back(balle);
	}
	this->ballePool = munitions;
}

void Offensif::shoot() {

}