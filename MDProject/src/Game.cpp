#include <Game.h>
#include <Gunther.h>
#include <sstream>
#include <iostream>

using namespace std;

Game::Game() {
	mFont.loadFromFile("resources/Sansation.ttf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(20);
}

Gunther& Game::getGunther() {
	return gunt;
}

void Game::processEvents() {
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		if (isInMenu) {
			if (event.type == sf::Event::KeyReleased) {
				switch (event.key.code) {
				case sf::Keyboard::Up:
					menu.moveUp();
					break;
				case sf::Keyboard::Down:
					menu.moveDown();
					break;
				case sf::Keyboard::Space:
					switch (menu.getSelectedIndex()) {
					case 0: // Commencer
						isInMenu = false;
						break;
					case 1: // Options
						isInMenu = false;
						isInOptions = true;
						break;
					case 2: // Quitter
						mWindow.close();
						break;
					}
					break;
				}
			}
		}
		else if (isInOptions) {
			options.handleEvent(event, isInOptions, isInMenu);
		}
		else {
			if (event.type == sf::Event::Closed) {
				mWindow.close();
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
				gunt.getPistolet().shoot(activeEnnemi, activeOffEnnemi);
			}
			draganddrop(event);
		}
	}
}

void Game::draganddrop(sf::Event event) {
	if (event.type == sf::Event::MouseButtonPressed) {
		auto localPosition = mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow));
		if (event.mouseButton.button == sf::Mouse::Left && gunt.getBouclier().getSprite().getGlobalBounds().contains(localPosition)) {
			isDraggingBouclier = true;
		}
		else if (event.mouseButton.button == sf::Mouse::Right && gunt.getPistolet().getSprite().getGlobalBounds().contains(localPosition)) {
			isDraggingPistolet = true;
		}
	}
	else if (event.type == sf::Event::MouseButtonReleased) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			isDraggingBouclier = false;
		}
		else if (event.mouseButton.button == sf::Mouse::Right) {
			isDraggingPistolet = false;
		}
	}
	else if (event.type == sf::Event::MouseMoved) {
		auto localPosition = mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow));
		if (isDraggingBouclier) {
			gunt.getBouclier().move(localPosition);
			gunt.getBouclier().reflect(activeOffEnnemi);
		}
		if (isDraggingPistolet) {
			gunt.getPistolet().move(localPosition);
		}
	}
}

void Game::updateStatistics(sf::Time elapsedTime) {
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(0.2f))
	{
		std::stringstream ss;
		ss << "PV: " << gunt.getHealth() << "/" << gunt.getMaxHealth();
		mStatisticsText.setString(ss.str());

		mStatisticsUpdateTime -= sf::seconds(0.2f);
		mStatisticsNumFrames = 0;
	}
}

void Game::updateBullets(sf::Time elapsedTime) {
	int i = 0;
	std::vector<Balle>& active = gunt.getPistolet().getActive();
	for (Balle& bullet : active) {
		bullet.getTime() += elapsedTime;
		if (bullet.getTime() > sf::seconds(2.0)) {
			active.erase(active.begin() + i);
		}
		i += 1;
	}
	for (Offensif& ennemi : activeOffEnnemi) {
		i = 0;
		std::vector<Balle>& activeOff = ennemi.getActiveEnnemi();
		for (Balle& bullet : activeOff) {
			bullet.getTime() += elapsedTime;
			if (bullet.getTime() > sf::seconds(2.0)) {
				gunt.doDamage(bullet.getDamage());
				if (!gunt.getAlive()) {
					std::cout << "Game Over : Gunther est mort !" << endl;
					mWindow.close();
				}
				activeOff.erase(activeOff.begin() + i);
			}
			i += 1;
		}
	}
}

void Game::update(sf::Time elapsedTime) {
	if (!isInMenu && !isInOptions) {
		spawnBullets += elapsedTime;
		if (spawnBullets >= sf::seconds(2.0)) {
			spawnBullets = sf::Time::Zero;
			for (Offensif& ennemi : activeOffEnnemi) {
				ennemi.shoot();
			}
		}
	}
	if (activeEnnemi.empty() && activeOffEnnemi.empty()) {
		std::cout << "Bravo tu remportes la victoire !" << endl;
		mWindow.close();
	}
}

void Game::render() {
	mWindow.clear();
	if (isInMenu) {
		menu.draw(mWindow);
	}
	else if (isInOptions) {
		options.draw(mWindow);
	}
	else {
		for (const Ennemi& ennemi : activeEnnemi) {
			ennemi.render(mWindow);
		}
		for (Offensif& ennemi : activeOffEnnemi) {
			ennemi.render(mWindow);
			for (const Balle& bullet : ennemi.getActiveEnnemi()) {
				bullet.render(mWindow);
			}
		}
		gunt.getPistolet().render(mWindow);
		for (const Balle& bullet : gunt.getPistolet().getActive()) {
			bullet.render(mWindow);
		}
		gunt.getBouclier().render(mWindow);
		mWindow.draw(mStatisticsText);
	}
	mWindow.display();
}

void Game::run() {
	auto demon1 = Ennemi(1, 100, 100, "line", "resources/FlameDemon.png", 0);
	auto demon2 = Offensif(2, 500, 100, "line", "resources/FlameArchDemon.png", 2);
	activeEnnemi.push_back(demon1); activeOffEnnemi.push_back(demon2);
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	mWindow.setVerticalSyncEnabled(true);
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			gunt.getPistolet().getReloadTime() += elapsedTime;
			processEvents();
		}
		update(elapsedTime);
		updateStatistics(elapsedTime);
		updateBullets(elapsedTime);
		render();

	}
}