#include "MenuOptions.h"

MenuOptions::MenuOptions(float width, float height) {
    if (!font.loadFromFile("resources/Sansation.ttf")) {
        // handle error
    }

    rulesText.setFont(font);
    rulesText.setString("Règles:\n1. Utilisez le clic gauche pour déplacer le bouclier.\n2. Utilisez le clic droit pour déplacer le pistolet.\n3. Appuyez sur Espace pour tirer.\n4. Tuez tous les ennemis d'une salle pour passer à la suivante.");
    rulesText.setCharacterSize(20);
    rulesText.setPosition(sf::Vector2f(50, 50));

    // Back option to return to the main menu
    backText.setFont(font);
    backText.setString("Appuyez sur Echap pour retourner au menu principal");
    backText.setCharacterSize(20);
    backText.setPosition(sf::Vector2f(width / 2 - 150, height - 100));
}

void MenuOptions::draw(sf::RenderWindow& window) const {
    window.draw(rulesText);
    window.draw(backText);
}

void MenuOptions::handleEvent(const sf::Event& event, bool& isInOptions, bool& isInMenu) const {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        isInOptions = false;
        isInMenu = true;
    }
}