#include "Menu.h"
#include "MenuOpening.h"
#include "MenuInGame.h"
#include "MenuOptions.h"
#include "MenuStateManager.h"

Menu::Menu(MenuStateManager& manager) : MenuState(manager) {
    float h_width = manager.width / 2;
    if (!font.loadFromFile("resources/Sansation.ttf")) {
        printf("Error loading font");
    }
    selectedIndex = 0;
    
    titre.setFont(font); 
    titre.setString("Mirrors Dungeon");
    titre.setCharacterSize(50);
    titre.setPosition(sf::Vector2f(h_width - titre.getGlobalBounds().width / 2, 50));
    titre.setFillColor(sf::Color::Green);

    playButton.setFont(font);
    playButton.setString("Jouer");
    playButton.setCharacterSize(30);
    playButton.setPosition(h_width - playButton.getGlobalBounds().width / 2, 200);
    menuItems.push_back(playButton);

    optionsButton.setFont(font);
    optionsButton.setString("Règles");
    optionsButton.setCharacterSize(30);
    optionsButton.setPosition(h_width - optionsButton.getGlobalBounds().width / 2, 300);
    menuItems.push_back(optionsButton);

    exitButton.setFont(font);
    exitButton.setString("Quitter");
    exitButton.setCharacterSize(30);
    exitButton.setPosition(h_width - exitButton.getGlobalBounds().width / 2, 400);
    menuItems.push_back(exitButton);
}

void Menu::render(sf::RenderWindow& window) {
    window.draw(manager.menuPrincipalSprite);
    window.draw(titre);
    for (const auto& item : menuItems) {
        window.draw(item);
    }
}

void Menu::handleMouseHover(const sf::Vector2f& mousePosition) {
    for (size_t i = 0; i < menuItems.size(); ++i) {
        if (menuItems[i].getGlobalBounds().contains(mousePosition)) {
            menuItems[selectedIndex].setFillColor(sf::Color::White);
            selectedIndex = int(i);
            menuItems[selectedIndex].setFillColor(sf::Color::Red);
        }
    }
}

void Menu::handleMouseClick(const sf::Vector2f& mousePosition, sf::RenderWindow& window) {
    for (size_t i = 0; i < menuItems.size(); ++i) {
        if (menuItems[i].getGlobalBounds().contains(mousePosition)) {
            switch (i) {
            case 0: // Jouer
                manager.isInOpening = true;
                manager.isInMenu = false;
                manager.changeState(std::make_unique<MenuOpening>(manager));
                break;
            case 1: // Règles
                manager.isInRegles = true;
                manager.isInMenu = false;
                manager.changeState(std::make_unique<MenuOptions>(manager));
                break;
            case 2: // Quitter
                window.close();
                break;
            default:
                window.close();
            }
        }
    }
}

void Menu::handleEvent(sf::Event event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseMoved) {
        auto mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        handleMouseHover(mousePosition);
    }
    else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        auto mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        handleMouseClick(mousePosition, window);
    }
}