#include "Balle.h"

using namespace std;

Balle::Balle(bool IsAlly, double x, double y, double damage, const string& text) : RoundTarget(sf::Color::White, x, y), IsAlly(IsAlly), damage(damage) {
	TextureBalle.loadFromFile(text);
	getSprite().setTexture(TextureBalle);
}

void Balle::doDamage() const {/*En cours*/}

sf::Texture& Balle::getTexture() {
	return TextureBalle;
}

sf::Time& Balle::getTime() {
	return timetolive;
}

void Balle::move(sf::Vector2f& mousePosition) {/*Non nécessaire car les balles ne bougent pas*/}