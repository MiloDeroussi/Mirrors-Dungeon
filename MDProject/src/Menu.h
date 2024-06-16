#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <MenuState.h>

class Menu : public MenuState {
private:
    int selectedIndex;
    sf::Font font;
    sf::Text titre;
    sf::Text playButton;
    sf::Text optionsButton;
    sf::Text exitButton;
    std::vector<sf::Text> menuItems;

public:
    explicit Menu(MenuStateManager& manager);
    void render(sf::RenderWindow& window) override;
    void handleEvent(sf::Event event, sf::RenderWindow& window) override;
    void moveUp();
    void moveDown();
    int getSelectedIndex() const;
};