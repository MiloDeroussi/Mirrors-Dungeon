#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "MenuState.h"

class MenuOpening : public MenuState {
private:
    sf::Font font;
    sf::Text explText;
    sf::Text contText;

public:
    explicit MenuOpening(MenuStateManager& manager);
    void render(sf::RenderWindow& window) override;
    void handleEvent(sf::Event event, sf::RenderWindow& window) override;
    void update(sf::Time elapsedTime[[maybe_unused]]) const;
};
