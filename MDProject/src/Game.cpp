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

std::vector<Offensif>& Game::getActiveOffEnnemi() {
	return activeOffEnnemi;
}

std::vector<Ennemi>& Game::getActiveEnnemi() {
	return activeEnnemi;
}

sf::RenderWindow& Game::getWindow() {
	return mWindow;
}

void Game::handleMenu(sf::Event event) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Up) {
			menu.moveUp();
		}
		else if (event.key.code == sf::Keyboard::Down) {
			menu.moveDown();
		}
		else if (event.key.code == sf::Keyboard::Space) {
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
			default:
				mWindow.close();
				break;
			}
		}
	}
}

void Game::processEvents() {
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		if (isInMenu) {
			handleMenu(event);
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
			gunt.getBouclier().reflect(getActiveOffEnnemi());
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

		mStatisticsUpdateTime = sf::Time::Zero;
		mStatisticsNumFrames = 0;
	}
}

void Game::updateBullets(sf::Time elapsedTime) {
	int i = 0;
	std::vector<Balle>& active = gunt.getPistolet().getActiveBalle();
	for (Balle& bullet : active) {
		bullet.getTime() += elapsedTime;
		if (bullet.getTime() > sf::seconds(2.0)) {
			active.erase(active.begin() + i);
		}
		i += 1;
	}
	for (Offensif& ennemi : getActiveOffEnnemi()) {
		i = 0;
		std::vector<Balle>& activeOff = ennemi.getActiveBalleEnnemi();
		for (Balle& bullet : activeOff) {
			bullet.getTime() += elapsedTime;
			if (bullet.getTime() > sf::seconds(2.0)) {
				gunt.doDamage(bullet.getDamage());
				activeOff.erase(activeOff.begin() + i);
			}
			if (!gunt.getAlive()) {
				mWindow.close();
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
		updateStatistics(elapsedTime);
		updateBullets(elapsedTime);
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
		for (const Ennemi& ennemi : getActiveEnnemi()) {
			ennemi.render(mWindow);
		}
		for (Offensif& ennemi : getActiveOffEnnemi()) {
			ennemi.render(mWindow);
			for (const Balle& bullet : ennemi.getActiveBalleEnnemi()) {
				bullet.render(mWindow);
			}
		}
		gunt.getPistolet().render(mWindow);
		for (const Balle& bullet : gunt.getPistolet().getActiveBalle()) {
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
	getActiveEnnemi().push_back(demon1); getActiveOffEnnemi().push_back(demon2);
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
		render();

	}
}