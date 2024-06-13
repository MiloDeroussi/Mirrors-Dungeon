#pragma once
#include "SFML/Graphics.hpp"
#include "Ennemi.h"
#include "Balle.h"
#include <vector>
#include <string>

class Offensif : public Ennemi {
private:
	std::vector<Balle> ballePool;
	std::vector<Balle> activeBalleEnnemi;
	int mun_max = 100;

public:
	explicit Offensif(double health, double x, double y, const std::string& pattern, const std::string& text, double attack);
	void shoot() override;
	std::vector<Balle>& getActiveEnnemi();
};