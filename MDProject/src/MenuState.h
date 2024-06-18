#pragma once
#include "SFML/Graphics.hpp"

class MenuStateManager;

class MenuState {
protected:
	MenuStateManager& manager;

public:
	explicit MenuState(MenuStateManager& manager) : manager(manager) {};
	virtual ~MenuState() = default;
	virtual void render(sf::RenderWindow& window) = 0;
	virtual void handleEvent(sf::Event event, sf::RenderWindow& window) = 0;
};