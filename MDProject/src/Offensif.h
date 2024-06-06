#pragma once
#include "SFML/Graphics.hpp"
#include "Ennemi.h"
#include "Balle.h"
#include <vector>
#include <string>

class Offensif : public Ennemi {
private:
	double attack;
	std::vector<Balle> ballePool;
	int mun_max = 99;

public:
	explicit Offensif(double health, double x, double y, std::string pattern, double attack);
	void shoot();
};