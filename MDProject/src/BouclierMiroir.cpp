#include "BouclierMiroir.h"

using namespace std;

BouclierMiroir::BouclierMiroir(double x, double y, const string& text) : RoundTarget(sf::Color::White, x, y) {
	TextureBouc.loadFromFile(text);
	getSprite().setTexture(TextureBouc);
	getSprite().setScale(float(0.3), float(0.3));
}

void BouclierMiroir::move(sf::Vector2f& mousePosition) {
	mousePosition.x -= getSprite().getGlobalBounds().width/2;
	mousePosition.y -= getSprite().getGlobalBounds().height/2;
	this->setPosition(mousePosition);
}