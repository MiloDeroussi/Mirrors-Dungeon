#pragma once
#include "SFML/Graphics.hpp"
#include "RoundTarget.h"

class BouclierMiroir : public RoundTarget {
private:
	sf::Texture TextureBouc;

public:
	explicit BouclierMiroir(double x, double y, const std::string& text);
	void move(sf::Vector2f& mousePosition) override;
};