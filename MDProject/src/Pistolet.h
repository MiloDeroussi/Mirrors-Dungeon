#pragma once
#include "SFML/Graphics.hpp"
#include "Balle.h"
#include "RoundTarget.h"

class Pistolet : public RoundTarget {
private:
	std::vector<Balle> ballePool;
	std::vector<Balle> activeBalle;
	int mun_max = 50;
	sf::Texture TexturePist;
	sf::Time reload = sf::seconds(2.0);

public:
	explicit Pistolet(bool IsAlly, double x, double y, std::string text);
	void render(sf::RenderWindow& window);
	void shoot(sf::RenderWindow& window);
	std::vector<Balle>& getActive();
	void move(sf::Vector2f& mousePosition) override;
	sf::Time& getReloadTime();
};