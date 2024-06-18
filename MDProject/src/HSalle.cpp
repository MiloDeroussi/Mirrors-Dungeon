#include "HSalle.h"

HSalle::HSalle(std::string id, int nsalle, int heal_percent): Salle(id,nsalle)
{
	this->heal_percent = heal_percent;
	TextureHeal = std::make_shared<sf::Texture>();
	std::string text;
	if (heal_percent == 25) {
		text = std::string("resources/Health_25.png");
	}
	else if (heal_percent == 50) {
		text = std::string("resources/Health_50.png");
	}
	else if (heal_percent == 75) {
		text = std::string("resources/Health_75.png");
	}
	else {
		text = std::string("resources/Health_100.png");
	}

	TextureHeal->loadFromFile(text);
	HealSprite.setTexture(*TextureHeal);
	HealSprite.setColor(sf::Color::White);
	HealSprite.setPosition(350, 400);
	HealSprite.setScale(0.5, 0.5);
}

double HSalle::Heal(double pv_max) const{
	return pv_max * heal_percent / 100;
}

void HSalle::render(sf::RenderWindow& window) const {
	window.draw(HealSprite);
}