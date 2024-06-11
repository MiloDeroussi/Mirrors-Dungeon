#include "BouclierMiroir.h"

using namespace std;

BouclierMiroir::BouclierMiroir(double x, double y, string text) : RoundTarget(40.0, sf::Color::White, x, y, 0, 0) {
	sf::Texture texture;
	texture.loadFromFile(text);
	TextureBouc = texture;
	this->mShape.setTexture(&TextureBouc);
}

void BouclierMiroir::render(sf::RenderWindow& window) {
	window.draw(mShape);
}

void BouclierMiroir::move(sf::Vector2f& mousePosition) {
	mousePosition.x -= this->mShape.getRadius();
	mousePosition.y -= this->mShape.getRadius();
	this->setPosition(mousePosition);
}