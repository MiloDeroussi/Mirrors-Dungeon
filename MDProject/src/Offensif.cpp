#include "Offensif.h"
#include <iostream>
#include <string>
#include <random>

using namespace std;

Offensif::Offensif(double health, double x, double y, const std::string& pattern, const std::string& text, double attack) : Ennemi(health, x, y, pattern, text, attack) {
	vector<Balle> munitions;
	for (int i = 0; i < mun_max; i++) {
		Balle balle(false, 0, 0, attack, "resources/Boule.png");
		munitions.push_back(balle);
	}
	this->ballePool = munitions;
}

Offensif::~Offensif() = default;

void Offensif::shoot() {
	if (!ballePool.empty()) {
		Balle& cur = ballePool.front();

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> disX(-100, 100);
		std::uniform_real_distribution<> disY(-100, 100);

		double offsetX = disX(gen);
		double offsetY = disY(gen);

		cur.getSprite().setPosition(getEnnemiSprite().getPosition().x + getEnnemiSprite().getGlobalBounds().width/2 + float(offsetX), getEnnemiSprite().getPosition().y + getEnnemiSprite().getGlobalBounds().height / 2 + float(offsetY));
		cur.getSprite().setTexture(cur.getTexture());
		cur.getSprite().setScale(float(0.1), float(0.1));
		cur.getSprite().setColor(sf::Color::Red);
		activeBalleEnnemi.push_back(cur);
		ballePool.erase(ballePool.begin());
	}
	else {
		std::cout << "Plus de balles !" << endl;
	}
}

std::vector<Balle>& Offensif::getActiveBalleEnnemi() {
	return activeBalleEnnemi;
}