#include "BouclierMiroir.h"

using namespace std;

BouclierMiroir::BouclierMiroir(string text) : RoundTarget(40.0, sf::Color::White, 300, 200, 0, 0) {
	sf::Texture texture;
	texture.loadFromFile(text);
	TextureBouc = texture;
	this->mShape.setTexture(&TextureBouc);
}

void BouclierMiroir::render(sf::RenderWindow& window) {
	window.draw(mShape);
}