#include "Balle.h"

using namespace std;

Balle::Balle(bool IsAlly, double x, double y, double damage, const string& text) : RoundTarget(sf::Color::White, x, y), IsAlly(IsAlly), damage(damage) {
	TextureBalle.loadFromFile(text);
	getSprite().setTexture(TextureBalle);
}

sf::Texture& Balle::getTexture() {
	return TextureBalle;
}

sf::Time& Balle::getTime() {
	return timetolive;
}

double Balle::getDamage() const {
	return damage;
}

Balle::~Balle() = default;

void Balle::move(sf::Vector2f& mousePosition) {/*Non n�cessaire car les balles ne bougent pas*/}