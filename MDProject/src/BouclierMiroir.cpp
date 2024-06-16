#include "BouclierMiroir.h"
#include <iostream>

using namespace std;

BouclierMiroir::BouclierMiroir(double x, double y, const string& text) : RoundTarget(sf::Color::White, x, y) {
	TextureBouc.loadFromFile(text);
	getSprite().setTexture(TextureBouc);
	getSprite().setScale(float(0.3), float(0.3));
}

BouclierMiroir::~BouclierMiroir() = default;

void BouclierMiroir::move(sf::Vector2f& mousePosition) {
	mousePosition.x -= getSprite().getGlobalBounds().width/2;
	mousePosition.y -= getSprite().getGlobalBounds().height/2;
	this->setPosition(mousePosition);
}

void BouclierMiroir::reflect(std::vector<Offensif>& ennemis) {
	for (Offensif& ennemi : ennemis) {
		int i = 0;
		for (Balle& bullet : ennemi.getActiveBalleEnnemi()) {
			if (getSprite().getGlobalBounds().contains(bullet.getSprite().getPosition())) {
				ennemi.getActiveBalleEnnemi().erase(ennemi.getActiveBalleEnnemi().begin());
			}
			i++;
		}
	}
}