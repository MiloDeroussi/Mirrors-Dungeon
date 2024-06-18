#pragma once
#include "SFML/Graphics.hpp"
#include "BouclierMiroir.h"
#include "Pistolet.h"
#include "Blessable.h"

class Gunther : public Blessable {
private:
	Pistolet pistolet = Pistolet(200, 400, "resources/Pistolet.png");
	BouclierMiroir bouclier = BouclierMiroir(500, 400, "resources/BouclierMiroir.png");

public:
	explicit Gunther(double health);
	BouclierMiroir& getBouclier();
	Pistolet& getPistolet();
};