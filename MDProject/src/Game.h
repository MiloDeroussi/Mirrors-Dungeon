#pragma once
#include "SFML/Graphics.hpp"
#include "RoundTarget.h"
#include <vector>
#include "Gunther.h"
#include "BouclierMiroir.h"
#include "Pistolet.h"

class Game : private sf::NonCopyable {
public:
	explicit Game();
	void run();
	void processEvents(sf::Time elapsedTime);
	void updateStatistics(sf::Time elapsedTime);
	void updateBullets(sf::Time elapsedTime);
	void render();
	void draganddrop(sf::Event event);
	Gunther getGunther();

private:
	Gunther gunt = Gunther(10);
	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	bool isDraggingBouclier = false;
	bool isDraggingPistolet = false;

	sf::RenderWindow mWindow{ sf::VideoMode{800, 600}, "Mirrors Dungeon", sf::Style::Close };
	sf::Text mStatisticsText;
	sf::Time mStatisticsUpdateTime = sf::Time::Zero;
	sf::Time mBulletsUpdateTime = sf::Time::Zero;
	std::size_t mStatisticsNumFrames{ 0 };
	sf::Font mFont;
};