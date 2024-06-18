#include "MenuFin.h"
#include "MenuInGame.h"
#include "MenuStateManager.h"

MenuInGame::MenuInGame(MenuStateManager& manager) : MenuState(manager) {}

void MenuInGame::render(sf::RenderWindow& window) {
	window.draw(manager.fondSprite);
}

void MenuInGame::handleEvent(sf::Event event, sf::RenderWindow& window) {
	manager.endGame = true;
	manager.isInGame = false;
	manager.changeState(std::make_unique<MenuFin>(manager));
}