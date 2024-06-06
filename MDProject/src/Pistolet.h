#pragma once
#include "SFML/Graphics.hpp"
#include "Balle.h"
#include "RoundTarget.h"

class Pistolet : public RoundTarget {
private:
	std::vector<Balle> ballePool;
	int mun_max;
public:
	explicit Pistolet(bool IsAlly, double x, double y, double size);
	void shoot();
};