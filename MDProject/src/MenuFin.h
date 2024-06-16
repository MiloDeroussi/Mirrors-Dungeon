#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <MenuState.h>

class MenuFin : public MenuState {
private:
    sf::Font font;
    sf::Text winText1;
    sf::Text loseText1;
    sf::Text winText2;
    sf::Text loseText2;
    sf::Text backText;

public:
    explicit MenuFin(MenuStateManager& manager);
    void render(sf::RenderWindow& window) override;
    void handleEvent(sf::Event event, sf::RenderWindow& window) override;
};