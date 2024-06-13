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

void Pistolet::shoot(std::vector<Ennemi>& activeEnnemi, std::vector<Offensif>& activeOffEnnemi) {
	if (reload < sf::seconds(2.0)) {
		std::cout << "Rechargement !" << endl;
	}
	else if (!ballePool.empty()) {
		reload = sf::Time::Zero;
		Balle& cur = ballePool.front();
		cur.getSprite().setPosition(getSprite().getPosition().x - getSprite().getGlobalBounds().width / 4, getSprite().getPosition().y - getSprite().getGlobalBounds().width / 4);
		cur.getSprite().setTexture(cur.getTexture());
		cur.getSprite().setScale(float(0.1), float(0.1));
		cur.getSprite().setColor(sf::Color::Blue);
		activeBalle.push_back(cur);
		ballePool.erase(ballePool.begin());
		dealDamage(activeEnnemi, activeOffEnnemi);
		std::cout << "Balles restantes : " << ballePool.size() << endl;
	}
	else {
		std::cout << "Balles restantes : 0" << endl;
	}
}

std::vector<Balle>& Pistolet::getActive() {
	return activeBalle;
}

void Pistolet::move(sf::Vector2f& mousePosition) {
	mousePosition.x -= getSprite().getGlobalBounds().width*3/4;
	mousePosition.y -= getSprite().getGlobalBounds().height*3/4;
	this->setPosition(mousePosition);
}

sf::Time& Pistolet::getReloadTime() {
	return reload;
}

void Pistolet::dealDamage(std::vector<Ennemi>& activeEnnemi, std::vector<Offensif>& activeOffEnnemi) {
	for (Balle& bullet : activeBalle) {
		int i = 0;
		for (Ennemi& ennemi : activeEnnemi) {
			if (ennemi.getEnnemiSprite().getGlobalBounds().contains(bullet.getSprite().getPosition())) {
				ennemi.doDamage(bullet.getDamage());
				if (!ennemi.getAlive()) {
					activeEnnemi.erase(activeEnnemi.begin() + i);
				}
			}
			i++;
		}
		i = 0;
		for (Offensif& ennemi : activeOffEnnemi) {
			if (ennemi.getEnnemiSprite().getGlobalBounds().contains(bullet.getSprite().getPosition())) {
				ennemi.doDamage(bullet.getDamage());
				if (!ennemi.getAlive()) {
					activeOffEnnemi.erase(activeOffEnnemi.begin() + i);
				}
			}
			i++;
		}
	}
}