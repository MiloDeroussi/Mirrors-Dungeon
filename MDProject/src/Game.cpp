#include <Game.h>
#include <Gunther.h>
#include "Donjon.h"
#include <sstream>
#include <iostream>
#include <chrono>
#include <thread>


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

std::vector<std::shared_ptr<Salle>>& Game::getRoom() {
	return shared_room;
}

sf::RenderWindow& Game::getWindow() {
	return mWindow;
}

void Game::processEvents() {
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		if (!menuStateMan.isInGame) {
			menuStateMan.handleEvent(event, mWindow);
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
		if (event.mouseButton.button == sf::Mouse::Right && gunt.getBouclier().getSprite().getGlobalBounds().contains(localPosition)) {
			isDraggingBouclier = true;
		}
		else if (event.mouseButton.button == sf::Mouse::Left && gunt.getPistolet().getSprite().getGlobalBounds().contains(localPosition)) {
			isDraggingPistolet = true;
		}
	}
	else if (event.type == sf::Event::MouseButtonReleased) {
		if (event.mouseButton.button == sf::Mouse::Right) {
			isDraggingBouclier = false;
		}
		else if (event.mouseButton.button == sf::Mouse::Left) {
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
		ss << "PV : " << gunt.getHealth() << "/" << gunt.getMaxHealth() << endl;
		ss << "Balles restantes : " << gunt.getPistolet().getBallePool().size();
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
				menuStateMan.endGame = true;
				menuStateMan.isInGame = false;
				sf::Event event; event.type = sf::Event::MouseButtonPressed;
				menuStateMan.handleEvent(event, mWindow);
			}
			i += 1;
		}
	}
}

void Game::update(sf::Time elapsedTime) {
	if (menuStateMan.isInGame) {
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
	if (activeEnnemi.empty() && activeOffEnnemi.empty() && current_room + 1 == shared_room.size()) { //CONDITION DE FIN DE JEU 
		menuStateMan.victory = true;
		menuStateMan.endGame = true;
		menuStateMan.isInGame = false;
		sf::Event event; event.type = sf::Event::MouseButtonPressed;
		menuStateMan.handleEvent(event, mWindow);
	}
	else if (activeEnnemi.empty() && activeOffEnnemi.empty()) {
		
		if (clock.getElapsedTime().asSeconds() >= 2.0f) {
			current_room++;
			loadSalle(shared_room.at(current_room));
			clock.restart();
		}
		
	}
	else {
		clock.restart();
	}

}

void Game::render(shared_ptr<Salle> salle) {
	mWindow.clear();
	menuStateMan.render(mWindow);
	if (menuStateMan.isInGame) {
		if (auto eSallePtr = dynamic_pointer_cast<ESalle>(salle); eSallePtr) {
			for (const Ennemi& ennemi : getActiveEnnemi()) {
				ennemi.render(mWindow);
			}
			for (Offensif& ennemi : getActiveOffEnnemi()) {
				ennemi.render(mWindow);
				for (const Balle& bullet : ennemi.getActiveBalleEnnemi()) {
					bullet.render(mWindow);
				}
			}
		}
		else if (auto hSallePtr = dynamic_pointer_cast<HSalle>(salle); hSallePtr) {
			hSallePtr.get()->render(mWindow);
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

void Game::loadSalle(shared_ptr<Salle> salle) {

	if (auto eSallePtr = dynamic_pointer_cast<ESalle>(salle); eSallePtr) {
		for (const Ennemi& e : eSallePtr->getEnnemis()) {
			getActiveEnnemi().push_back(e);
		}
		for (const Offensif& e : eSallePtr->getEnnemisOff()) {
			getActiveOffEnnemi().push_back(e);
		}
	}
	if (auto hSallePtr = dynamic_pointer_cast<HSalle>(salle); hSallePtr) {
		gunt.doDamage(-hSallePtr->Heal(gunt.getMaxHealth()));
	}
}

void Game::run() {
	int difficulty = 1;
	Donjon donjon;
	std::vector<Salle::Type>& salles = donjon.getDungeonPath();

	for (int i = 0; i < salles.size(); i++) {
		if (salles.at(i) == Salle::Type::MiniBoss) {
			difficulty = 2;
		}
		donjon.generateSalle(salles, i, difficulty);
	}
	for (const auto& s : donjon.getSalles()) {
		getRoom().push_back(s);
	}
	loadSalle(getRoom().at(current_room));

	sf::Clock clock_;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	mWindow.setVerticalSyncEnabled(true);
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock_.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			gunt.getPistolet().getReloadTime() += elapsedTime;
			processEvents();
		}
		update(elapsedTime);
		render(getRoom().at(current_room));

	}
}