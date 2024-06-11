#include "Balle.h"

using namespace std;

Balle::Balle(bool IsAlly, double x, double y, double damage, string text) {
	this->damage = damage;
	this->IsAlly = IsAlly;
	bullet.setPosition(x, y);
	if (!TextureBalle.loadFromFile(text)) {
		throw std::runtime_error("Impossible de charger la texture de la balle");
	}
	bullet.setTexture(TextureBalle);
}

void Balle::grow(double speed) {

}

void Balle::doDamage() {

}

void Balle::render(sf::RenderWindow& window) {
	window.draw(bullet);
}

sf::Sprite& Balle::getSpriteBullet() {
	return bullet;
}

sf::Texture& Balle::getTexture() {
	return TextureBalle;
}

sf::Time& Balle::getTime() {
	return timetolive;
}