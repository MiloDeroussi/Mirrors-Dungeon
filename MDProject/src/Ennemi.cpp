#include "Ennemi.h"

using namespace std;

Ennemi::Ennemi(double health, double x, double y, const std::string& pattern, const std::string& text, double attack) : Blessable(health), MovePattern(pattern), attack(attack) {
	TextureEnnemi.loadFromFile(text);
	EnnemiSprite.setTexture(TextureEnnemi);
	EnnemiSprite.setColor(sf::Color::White);
	EnnemiSprite.setPosition(float(x), float(y));
	EnnemiSprite.setScale(2.5, 2.5);
}

void Ennemi::render(sf::RenderWindow& window) const {
	window.draw(EnnemiSprite);
}

void Ennemi::move(string pattern) {

}

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