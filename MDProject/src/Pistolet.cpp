#include "Pistolet.h"

using namespace std;

Pistolet::Pistolet(bool IsAlly, double x, double y, double size) : RoundTarget(40.0, sf::Color::Green, 300, 100, 0, 0) {
	vector<Balle> munitions;
	for (int i = 0; i < mun_max; i++) {
		Balle balle(IsAlly, x, y, size);
		munitions.push_back(balle);
	}
	this->ballePool = munitions;
}

void Pistolet::shoot() {

}