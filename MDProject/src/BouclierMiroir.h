#pragma once
#include "SFML/Graphics.hpp"
#include "RoundTarget.h"

class BouclierMiroir : public RoundTarget {
public:
	explicit BouclierMiroir();
	void reflect(const sf::Vector2i& mousePosition);
	void render(sf::RenderWindow& window) const;
};