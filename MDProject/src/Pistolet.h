#pragma once
#include "SFML/Graphics.hpp"
#include "Balle.h"
#include "RoundTarget.h"
#include "Ennemi.h"
#include "Offensif.h"

class Pistolet : public RoundTarget {
private:
	sf::Texture TexturePist;
	std::vector<Balle> ballePool;
	std::vector<Balle> activeBalle;
	int mun_max = 50;
	sf::Time reload = sf::seconds(2.0);

public:
	explicit Pistolet(double x, double y, const std::string& text);
	void shoot(std::vector<Ennemi>& activeEnnemi, std::vector<Offensif>& activeOffEnnemi);
	std::vector<Balle>& getActive();
	void move(sf::Vector2f& mousePosition) override;
	sf::Time& getReloadTime();
	void dealDamage(std::vector<Ennemi>& activeEnnemi, std::vector<Offensif>& activeOffEnnemi);
};