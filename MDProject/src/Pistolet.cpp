#include "Pistolet.h"
#include <iostream>
using namespace std;

Pistolet::Pistolet(bool IsAlly, double x, double y, std::string text) : RoundTarget(40.0, sf::Color::White, x, y, 0, 0) {
	vector<Balle> munitions;
	for (int i = 0; i < mun_max; i++) {
		Balle balle(true, 0, 0, 1, "resources/Boule.png");
		munitions.push_back(balle);
	}
	this->ballePool = munitions;
	sf::Texture texture;
	texture.loadFromFile(text);
	TexturePist = texture;
	this->mShape.setTexture(&TexturePist);
}

void Pistolet::render(sf::RenderWindow& window) {
	window.draw(mShape);
}

void Pistolet::shoot(sf::RenderWindow& window) {
	if (reload < sf::seconds(1.0)) {
		std::cout << "Rechargement !" << endl;
	}
	else if (!ballePool.empty()) {
		reload = sf::Time::Zero;
		Balle& cur = ballePool.front();
		cur.getSpriteBullet().setScale(0.5, 0.5);
		cur.getSpriteBullet().setPosition(mShape.getPosition().x, mShape.getPosition().y);
		cur.getSpriteBullet().setTexture(cur.getTexture());
		cur.getSpriteBullet().setScale(0.1, 0.1);
		cur.getSpriteBullet().setColor(sf::Color::Blue);
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
	mousePosition.x -= this->mShape.getRadius()*3/2;
	mousePosition.y -= this->mShape.getRadius()*3/2;
	this->setPosition(mousePosition);
}

sf::Time& Pistolet::getReloadTime() {
	return reload;
}