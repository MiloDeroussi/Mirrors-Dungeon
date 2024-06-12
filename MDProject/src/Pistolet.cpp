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

void Pistolet::shoot() {
	if (reload < sf::seconds(1.0)) {
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