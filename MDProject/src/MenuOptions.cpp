#include "MenuOptions.h"
#include "MenuStateManager.h"
#include "Menu.h"

MenuOptions::MenuOptions(MenuStateManager& manager) : MenuState(manager) {
    font.loadFromFile("resources/Sansation.ttf");

    rulesText.setFont(font);
    rulesText.setString("Règles:\n\n1. Utilisez le clic gauche pour déplacer le bouclier.\n2. Utilisez le clic droit pour déplacer le pistolet.\n3. Appuyez sur Espace pour tirer.\n4. Tuez tous les ennemis d'une salle pour passer à la suivante.");
    rulesText.setCharacterSize(20);
    rulesText.setPosition(sf::Vector2f(10, 10));

    backText.setFont(font);
    backText.setString("Appuyez sur Échap pour retourner au menu principal");
    backText.setCharacterSize(20);
    backText.setPosition(sf::Vector2f(manager.width - backText.getGlobalBounds().width - 10, manager.height - backText.getGlobalBounds().height - 10));
}

void MenuOptions::render(sf::RenderWindow& window) {
    window.draw(manager.menuReglesSprite);
    window.draw(rulesText);
    window.draw(backText);
}

void MenuOptions::handleEvent(sf::Event event, sf::RenderWindow& window) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        manager.isInMenu = true;
        manager.isInRegles = false;
        manager.changeState(std::make_unique<Menu>(manager));
    }
}