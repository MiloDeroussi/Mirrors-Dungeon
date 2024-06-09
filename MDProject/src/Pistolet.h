#pragma once
#include "SFML/Graphics.hpp"
#include "Balle.h"
#include "RoundTarget.h"

class Pistolet : public RoundTarget {
private:
	std::vector<Balle> ballePool;
	int mun_max = 50;
	sf::Texture TexturePist;
public:
	explicit Pistolet(bool IsAlly, double x, double y, double size, std::string text);
	void render(sf::RenderWindow& window);
	void shoot();
};