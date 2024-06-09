#include "Pistolet.h"
#include <iostream>
using namespace std;

Pistolet::Pistolet(bool IsAlly, double x, double y, double size, std::string text) : RoundTarget(40.0, sf::Color::White, 300, 100, 0, 0) {
	vector<Balle> munitions;
	for (int i = 0; i < mun_max; i++) {
		Balle balle(true, 0, 0, 20);
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

void Pistolet::shoot() {
	if (!ballePool.empty()) {
		ballePool.erase(ballePool.begin());
		std::cout << "Balles restantes : " << ballePool.size() << endl;
	}
	else {
		std::cout << "Balles restantes : 0" << endl;
	}
}