#pragma once

#include "SFML/Graphics.hpp"
#include "Salle.h"
#include <pugixml.hpp>
#include <vector>
#include <pugixml.hpp>


class HSalle : public Salle {
private:
	int heal_percent;
	std::shared_ptr<sf::Texture> TextureHeal;
	sf::Sprite HealSprite;

public:
	explicit HSalle(const std::string& id, int nsalle, int heal_percent);
	double Heal(double pv_max) const;
	void render(sf::RenderWindow& window) const;
};