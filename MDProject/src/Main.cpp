#include "Main.h"
#include "BouclierMiroir.h"
#include "pugixml.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace std::literals;

const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

void processEvents(sf::RenderWindow& mWindow, BouclierMiroir& bouc) {
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			mWindow.close();
		}
		else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
			sf::Vector2i localPosition = sf::Mouse::getPosition(mWindow);
			bouc.reflect(localPosition);
		}
	}
}

void render(sf::RenderWindow& mWindow, const BouclierMiroir& bouc)
{
	mWindow.clear();
	bouc.render(mWindow);
	mWindow.display();
}

int myMain()
{
	sf::Clock clock;
	BouclierMiroir bouc;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	auto mWindow = sf::RenderWindow{ sf::VideoMode{640, 480}, "SFML Application", sf::Style::Close };
	mWindow.setVerticalSyncEnabled(true);
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processEvents(mWindow, bouc);
		}
		render(mWindow, bouc);
	}
	return 0;
}