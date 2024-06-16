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
	Gunther gunt = Gunther(10);
	std::vector<Offensif> activeOffEnnemi;
	std::vector<Ennemi> activeEnnemi;
	bool isDraggingBouclier = false;
	bool isDraggingPistolet = false;
	bool isInMenu = true;
	bool isInOptions = false;
	sf::Text mStatisticsText;
	sf::Font mFont;
	Menu menu{800, 600};
	MenuOptions options{ 800, 600 };
	sf::RenderWindow mWindow{ sf::VideoMode{800, 600}, "Mirrors Dungeon", sf::Style::Close };
	sf::Time mStatisticsUpdateTime = sf::Time::Zero;
	sf::Time mBulletsUpdateTime = sf::Time::Zero;
	sf::Time spawnBullets = sf::Time::Zero;
	std::size_t mStatisticsNumFrames{ 0 };

public:
	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	explicit Game();
	std::vector<Offensif>& getActiveOffEnnemi();
	std::vector<Ennemi>& getActiveEnnemi();
	sf::RenderWindow& getWindow();
	Gunther& getGunther();
	void run();
	void processEvents();
	void update(sf::Time elapsedTime);
	void updateStatistics(sf::Time elapsedTime);
	void updateBullets(sf::Time elapsedTime);
	void render();
	void draganddrop(sf::Event event);
	void handleMenu(sf::Event event);
};