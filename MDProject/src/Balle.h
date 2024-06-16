#pragma once
#include "SFML/Graphics.hpp"
#include "RoundTarget.h"
#include "Blessable.h"

class Balle : public RoundTarget {
private:
	bool IsAlly;
	sf::Texture TextureBalle;
	sf::Time timetolive = sf::Time::Zero;
	double damage;

public:
	explicit Balle(bool IsAlly, double x, double y, double damage, const std::string& text);
	~Balle() override;
	sf::Texture& getTexture();
	sf::Time& getTime();
	double getDamage() const;
	void move(sf::Vector2f& mousePosition) override;
};