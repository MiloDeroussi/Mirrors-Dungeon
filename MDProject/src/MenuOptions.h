#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class MenuOptions {
public:
    MenuOptions(float width, float height);
    void draw(sf::RenderWindow& window) const;
    void handleEvent(const sf::Event& event, bool& isInOptions, bool& isInMenu) const;

private:
    sf::Font font;
    sf::Text rulesText;
    sf::Text backText;
};
