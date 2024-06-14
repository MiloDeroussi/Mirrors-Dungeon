#pragma once
#include "SFML/Graphics.hpp"
#include "Balle.h"
#include "Blessable.h"
#include <string>
#include <vector>

class Ennemi : public Blessable {
private:
	sf::Texture TextureEnnemi;
	sf::Sprite EnnemiSprite;
	std::string MovePattern;
	double attack;

public:
	explicit Ennemi(double health, double x, double y, const std::string& pattern, const std::string& text, double attack);
	virtual ~Ennemi();
	sf::Sprite& getEnnemiSprite();
	std::string getPattern() const;
	double getAttack() const;
	bool isOffensive() const;
	virtual void shoot();
	void render(sf::RenderWindow& window) const;
	void move() const;
};
