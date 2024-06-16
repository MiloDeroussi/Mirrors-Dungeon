#pragma once
#include "SFML/Graphics.hpp"
#include "RoundTarget.h"
#include "Offensif.h"

class BouclierMiroir : public RoundTarget {
private:
	sf::Texture TextureBouc;

public:
	explicit BouclierMiroir(double x, double y, const std::string& text);
	virtual ~BouclierMiroir();
	void move(sf::Vector2f& mousePosition) override;
	void reflect(std::vector<Offensif>& ennemis);
};