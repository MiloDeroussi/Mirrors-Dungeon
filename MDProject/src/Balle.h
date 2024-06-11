#pragma once
#include "SFML/Graphics.hpp"

class Balle {
private:
	bool IsAlly;
	sf::Texture TextureBalle;
	sf::Sprite bullet;
	sf::Time timetolive = sf::Time::Zero;
	double damage;

public:
	explicit Balle(bool IsAlly, double x, double y, double damage, std::string text);
	void grow(double speed);
	void doDamage();
	void render(sf::RenderWindow& window);
	sf::Sprite& getSpriteBullet();
	sf::Texture& getTexture();
	sf::Time& getTime();
};