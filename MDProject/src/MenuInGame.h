#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <MenuState.h>

class MenuInGame : public MenuState {
public:
    explicit MenuInGame(MenuStateManager& manager);
    void render(sf::RenderWindow& window) override;
    void handleEvent(sf::Event event, sf::RenderWindow& window) override;
};