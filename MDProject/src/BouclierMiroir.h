#pragma once
#include "SFML/Graphics.hpp"
#include "RoundTarget.h"

class BouclierMiroir : public RoundTarget {
public:
	explicit BouclierMiroir(double x, double y, std::string text);
	void render(sf::RenderWindow& window);
	void move(sf::Vector2f& mousePosition) override;

private:
	sf::Texture TextureBouc;
};