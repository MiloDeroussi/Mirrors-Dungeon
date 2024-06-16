#include "Menu.h"
#include "MenuInGame.h"
#include "MenuOptions.h"
#include "MenuStateManager.h"

Menu::Menu(MenuStateManager& manager) : MenuState(manager) {
    float h_width = manager.width / 2;
    if (!font.loadFromFile("resources/Sansation.ttf")) {
        printf("Error loading font");
    }
    
    titre.setFont(font); 
    titre.setString("Mirrors Dungeon");
    titre.setCharacterSize(50);
    titre.setPosition(sf::Vector2f(h_width - titre.getGlobalBounds().width / 2, 50));
    titre.setFillColor(sf::Color::Green);

    playButton.setFont(font);
    playButton.setString("Jouer");
    playButton.setCharacterSize(30);
    playButton.setPosition(h_width - playButton.getGlobalBounds().width / 2, 200);
    playButton.setFillColor(sf::Color::Red);
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

    selectedIndex = 0;
}

void Menu::render(sf::RenderWindow& window) {
    window.draw(manager.menuPrincipalSprite);
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

void Menu::handleEvent(sf::Event event, sf::RenderWindow& window) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            moveUp();
        }
        else if (event.key.code == sf::Keyboard::Down) {
            moveDown();
        }
        else if (event.key.code == sf::Keyboard::Space) {
            switch (getSelectedIndex()) {
            case 0: // Jouer
                manager.isInGame = true;
                manager.isInMenu = false;
                manager.changeState(std::make_unique<MenuInGame>(manager));
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