#include "Menu.h"

Menu::Menu(float width, float height) {
    if (!font.loadFromFile("resources/Sansation.ttf")) {
        printf("Error loading menu");
    }
    
    titre.setFont(font); titre.setString("Mirrors Dungeon"); titre.setPosition(sf::Vector2f(width / 3, 50)); titre.setScale(float(1.6), float(1.6)); titre.setFillColor(sf::Color::Green);
    std::vector<std::string> items = { "Commencer", "Options", "Quitter" };
    for (size_t i = 0; i < items.size(); ++i) {
        sf::Text text;
        text.setFont(font);
        text.setString(items[i]);
        text.setPosition(sf::Vector2f(width*4/10, height / (float(items.size()) + 1) * (float(i) + 1) + 50));
        menuItems.push_back(text);
    }

    selectedIndex = 0;
    menuItems[selectedIndex].setFillColor(sf::Color::Red);
}

void Menu::draw(sf::RenderWindow& window) const {
    window.draw(titre);
    for (const auto& item : menuItems) {
        window.draw(item);
    }
}

void Menu::moveUp() {
    if (selectedIndex - 1 >= 0) {
        menuItems[selectedIndex].setFillColor(sf::Color::White);
        selectedIndex--;
        menuItems[selectedIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::moveDown() {
    if (selectedIndex + 1 < menuItems.size()) {
        menuItems[selectedIndex].setFillColor(sf::Color::White);
        selectedIndex++;
        menuItems[selectedIndex].setFillColor(sf::Color::Red);
    }
}

int Menu::getSelectedIndex() const {
    return selectedIndex;
}