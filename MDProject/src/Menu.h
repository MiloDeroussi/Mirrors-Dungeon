#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Menu {
private:
    int selectedIndex;
    sf::Font font;
    std::vector<sf::Text> menuItems;
    sf::Text titre;

public:
    Menu(float width, float height);
    void draw(sf::RenderWindow& window) const;
    void moveUp();
    void moveDown();
    int getSelectedIndex() const;
};