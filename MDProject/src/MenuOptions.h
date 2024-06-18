#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "MenuState.h"

class MenuOptions : public MenuState {
private:
    sf::Font font;
    sf::Text rulesText;
    sf::Text backText;

public:
    explicit MenuOptions(MenuStateManager& manager);
    void render(sf::RenderWindow& window) override;
    void handleEvent(sf::Event event, sf::RenderWindow& window) override;
    void update(sf::Time elapsedTime);
};
