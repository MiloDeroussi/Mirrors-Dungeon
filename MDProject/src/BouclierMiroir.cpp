#include "BouclierMiroir.h"

using namespace std;

BouclierMiroir::BouclierMiroir() : RoundTarget(40.0, sf::Color::Blue, 300, 100, 0, 0) {}

void BouclierMiroir::reflect(const sf::Vector2i& mousePosition) {
	if (this->isHitByMouse(mousePosition)) {
		this->setColor(sf::Color::Red);
	}
}

void BouclierMiroir::render(sf::RenderWindow& window) const {
	window.draw(mShape);
}