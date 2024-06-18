#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>
#include <memory>
#include "MenuState.h"

class MenuStateManager {
public:
	std::unique_ptr<MenuState> menuState;
	sf::Font mFont;
	sf::Texture textureJeu;
	sf::Texture textureMenuPrincipal;
	sf::Texture textureMenuRegles;
	sf::Texture textureFin;
	sf::Sprite fondSprite;
	sf::Sprite menuPrincipalSprite;
	sf::Sprite menuReglesSprite;
	sf::Sprite finSprite;
	float width = 800;
	float height = 600;
	bool hilDeath = false;
	bool isInOpening = false;
	bool isInMenu = true;
	bool isInRegles = false;
	bool isInGame = false;
	bool endGame = false;
	bool victory = false;

	explicit MenuStateManager();
	void render(sf::RenderWindow& window) const;
	void handleEvent(sf::Event event, sf::RenderWindow& window);
	void changeState(std::unique_ptr<MenuState> state);
};
	