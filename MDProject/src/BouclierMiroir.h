#pragma once
#include "SFML/Graphics.hpp"
#include "RoundTarget.h"

class BouclierMiroir : public RoundTarget {
public:
	explicit BouclierMiroir(std::string text);
	void render(sf::RenderWindow& window);

private:
	sf::Texture TextureBouc;
};