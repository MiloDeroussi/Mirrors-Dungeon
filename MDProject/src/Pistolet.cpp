#include "Pistolet.h"
#include <iostream>
using namespace std;

Pistolet::Pistolet(double x, double y, const std::string& text) : RoundTarget(sf::Color::White, x, y) {
	vector<Balle> munitions;
	for (int i = 0; i < mun_max; i++) {
		Balle balle(true, 0, 0, 1, "resources/Boule.png");
		munitions.push_back(balle);
	}
	this->ballePool = munitions;
	TexturePist.loadFromFile(text);
	getSprite().setTexture(TexturePist);
	getSprite().setScale(float(0.35), float(0.35));
}

Pistolet::~Pistolet() = default;

void Pistolet::shoot(std::vector<Ennemi>& activeEnnemi, std::vector<Offensif>& activeOffEnnemi) {
	if (reload < sf::seconds(2.0)) {
		std::cout << "Rechargement !" << endl;
	}
	else if (!ballePool.empty()) {
		reload = sf::Time::Zero;
		Balle& cur = ballePool.front();
		cur.getSprite().setPosition(getSprite().getPosition().x + getSprite().getGlobalBounds().width / 2 + 5, getSprite().getPosition().y - getSprite().getGlobalBounds().height / 4 + 5);
		cur.getSprite().setTexture(cur.getTexture());
		cur.getSprite().setScale(float(0.1), float(0.1));
		cur.getSprite().setColor(sf::Color::Blue);
		activeBalle.push_back(cur);
		ballePool.erase(ballePool.begin());
		dealDamage(activeEnnemi, activeOffEnnemi);
	}
	else {
		std::cout << "Plus de balles !" << endl;
	}
}

std::vector<Balle>& Pistolet::getActiveBalle() {
	return activeBalle;
}

std::vector<Balle>& Pistolet::getBallePool() {
	return ballePool;
}

void Pistolet::move(sf::Vector2f& mousePosition) {
	mousePosition.x -= getSprite().getGlobalBounds().width * 1 / 4;
	mousePosition.y -= getSprite().getGlobalBounds().height * 3 / 4;
	this->setPosition(mousePosition);
}

sf::Time& Pistolet::getReloadTime() {
	return reload;
}

void Pistolet::dealDamage(std::vector<Ennemi>& activeEnnemi, std::vector<Offensif>& activeOffEnnemi) {
	for (Balle& bullet : activeBalle) {
		for (int i = activeEnnemi.size() - 1; i >= 0; --i) {
			Ennemi& ennemi = activeEnnemi[i];
			if (ennemi.getEnnemiSprite().getGlobalBounds().contains(bullet.getSprite().getPosition())) {
				ennemi.doDamage(bullet.getDamage());
				killEnnemi(activeEnnemi[i], activeEnnemi, i);
			}
		}
		for (int i = activeOffEnnemi.size() - 1; i >= 0; --i) {
			Offensif& ennemi = activeOffEnnemi[i];
			if (ennemi.getEnnemiSprite().getGlobalBounds().contains(bullet.getSprite().getPosition())) {
				ennemi.doDamage(bullet.getDamage());
				killOffEnnemi(activeOffEnnemi[i], activeOffEnnemi, i);
			}
		}
	}
}


void Pistolet::killEnnemi(const Ennemi& ennemi, std::vector<Ennemi>& activeEnnemi, int i) const {
	if (!activeEnnemi[i].getAlive()) {
		activeEnnemi.erase(activeEnnemi.begin() + i);
	}
}

void Pistolet::killOffEnnemi(const Ennemi& ennemi, std::vector<Offensif>& activeOffEnnemi, int i) const {
	if (!activeOffEnnemi[i].getAlive()) {
		activeOffEnnemi.erase(activeOffEnnemi.begin() + i);
	}
}