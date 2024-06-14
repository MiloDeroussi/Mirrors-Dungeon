#pragma once
#include "SFML/Graphics.hpp"
#include "RoundTarget.h"
#include <vector>
#include "Gunther.h"
#include "BouclierMiroir.h"
#include "Pistolet.h"
#include "Ennemi.h"
#include "Offensif.h"
#include "Menu.h"
#include "MenuOptions.h"

class Game : private sf::NonCopyable {
private:
	std::vector<Ennemi> activeEnnemi;
	std::vector<Offensif> activeOffEnnemi;
	Gunther gunt = Gunther(10);
	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	bool isDraggingBouclier = false;
	bool isDraggingPistolet = false;
	bool isInMenu = true;
	bool isInOptions = false;

	sf::RenderWindow mWindow{ sf::VideoMode{800, 600}, "Mirrors Dungeon", sf::Style::Close };
	sf::Text mStatisticsText;
	sf::Time mStatisticsUpdateTime = sf::Time::Zero;
	sf::Time mBulletsUpdateTime = sf::Time::Zero;
	sf::Time spawnBullets = sf::Time::Zero;
	std::size_t mStatisticsNumFrames{ 0 };
	sf::Font mFont;
	Menu menu{800, 600};
	MenuOptions options{ 800, 600 };

public:
	explicit Game();
	Gunther& getGunther();
	void run();
	void processEvents();
	void update(sf::Time elapsedTime);
	void updateStatistics(sf::Time elapsedTime);
	void updateBullets(sf::Time elapsedTime);
	void render();
	void draganddrop(sf::Event event);
};