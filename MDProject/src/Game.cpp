#include <Game.h>
#include <Gunther.h>
#include <sstream>

using namespace std;

Game::Game() {
	mFont.loadFromFile("resources/Sansation.ttf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(20);
}

Gunther Game::getGunther() const {
	return gunt;
}

void Game::processEvents() {
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			mWindow.close();
		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
			gunt.getPistolet().shoot();
		}
		draganddrop(event);
	}
}

void Game::draganddrop(sf::Event event) {
	if (event.type == sf::Event::MouseButtonPressed) {
		auto localPosition = mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow));
		if (event.mouseButton.button == sf::Mouse::Left) {
			if (gunt.getBouclier().getSprite().getGlobalBounds().contains(localPosition)) {
				isDraggingBouclier = true;
			}
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
		}
		if (isDraggingPistolet) {
			gunt.getPistolet().move(localPosition);
		}
	}
}

void Game::updateStatistics(sf::Time elapsedTime) {
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		std::stringstream ss;
		ss << "PV: " << gunt.getHealth() << "/" << gunt.getMaxHealth();
		mStatisticsText.setString(ss.str());

		mStatisticsUpdateTime -= sf::seconds(1.0f);
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
}

void Game::render() {
	mWindow.clear();
	gunt.getBouclier().render(mWindow);
	gunt.getPistolet().render(mWindow);
	for (const Balle& bullet : gunt.getPistolet().getActive()) {
		bullet.render(mWindow);
	}
	mWindow.draw(mStatisticsText);
	mWindow.display();
}

void Game::run() {
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
		updateStatistics(elapsedTime);
		updateBullets(elapsedTime);
		render();

	}
}