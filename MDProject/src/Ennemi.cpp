#include "Ennemi.h"

using namespace std;

Ennemi::Ennemi(double health, double x, double y, const std::string& pattern, const std::string& text, double attack) : Blessable(health), MovePattern(pattern), attack(attack) {
	TextureEnnemi.loadFromFile(text);
	EnnemiSprite.setTexture(TextureEnnemi);
	EnnemiSprite.setColor(sf::Color::White);
	EnnemiSprite.setPosition(float(x), float(y));
	EnnemiSprite.setScale(0.5, 0.5);
}

void Ennemi::render(sf::RenderWindow& window) const {
	window.draw(EnnemiSprite);
}

std::string Ennemi::getPattern() const {
	return MovePattern;
}

void Ennemi::move() const {/*En cours*/}

Ennemi::~Ennemi() = default;

sf::Sprite& Ennemi::getEnnemiSprite() {
	return EnnemiSprite;
}

double Ennemi::getAttack() const {
	return attack;
}

bool Ennemi::isOffensive() const {
	return (getAttack() > 0);
}

void Ennemi::shoot() {/*Un ennemi basique ne peut pas tirer*/ }