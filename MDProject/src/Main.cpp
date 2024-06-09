#include "Main.h"
#include "BouclierMiroir.h"
#include "Pistolet.h"
#include "pugixml.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace std::literals;

const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

void processEvents(sf::RenderWindow& mWindow, BouclierMiroir& bouc, Pistolet& pist) {
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			mWindow.close();
		}
		else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
			auto localPosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(mWindow));
			bouc.move(localPosition);
		}
		else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right) {
			auto localPosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(mWindow));
			pist.move(localPosition);
			pist.shoot();
		}
	}
}

int myMain()
{
	sf::Clock clock;
	BouclierMiroir bouc("resources/BouclierMiroir.png");
	Pistolet pist(true, 0, 0, 20, "resources/Pistolet.png");
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	auto mWindow = sf::RenderWindow{ sf::VideoMode{640, 480}, "Mirrors Dungeon", sf::Style::Close };
	mWindow.setVerticalSyncEnabled(true);
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents(mWindow, bouc, pist);
		}
		mWindow.clear();
		bouc.render(mWindow);
		pist.render(mWindow);
		mWindow.display();
		
	}
	return 0;
}