#pragma once
#include "SFML/Graphics.hpp"
#include "BouclierMiroir.h"
#include "Pistolet.h"
#include "Blessable.h"

class Gunther : public Blessable {
private:
	Pistolet pistolet = Pistolet(true, 0, 0, 20);
	BouclierMiroir bouclier = BouclierMiroir();
	double damage = 1;
	double health = 10;

public:
	explicit Gunther(double health);
};