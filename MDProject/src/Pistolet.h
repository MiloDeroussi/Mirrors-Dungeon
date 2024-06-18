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
	~Pistolet() override;
	sf::Time& getReloadTime();
	std::vector<Balle>& getActiveBalle();
	std::vector<Balle>& getBallePool();
	void move(sf::Vector2f& mousePosition) override;
	void shoot(std::vector<Ennemi>& activeEnnemi, std::vector<Offensif>& activeOffEnnemi);
	void dealDamage(std::vector<Ennemi>& activeEnnemi, std::vector<Offensif>& activeOffEnnemi);
	void killEnnemi(const Ennemi& ennemi, std::vector<Ennemi>& activeEnnemi, int i) const;
	void killOffEnnemi(const Ennemi& ennemi, std::vector<Offensif>& activeEnnemi, int i) const;
};
