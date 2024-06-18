#include "MenuOpening.h"
#include "MenuStateManager.h"
#include "Menu.h"
#include "MenuInGame.h"

MenuOpening::MenuOpening(MenuStateManager& manager) : MenuState(manager) {
    font.loadFromFile("resources/Sansation.ttf");

    explText.setFont(font);
    explText.setString("Alors que Gunther le chasseur de démons rentre chez lui un soir, il se retrouve nez à nez \navec nataS qui tient sa petite Hildegarde entre ses griffes. 'Viens me chercher si tu \nl'oses' lui lance-t-il avant de s'envoler avec son bébé.\n \n Ni une ni deux, Gunther le suit jusqu'à son donjon et s'apprête à en découdre !\n");
    explText.setCharacterSize(20);
    explText.setPosition(sf::Vector2f(1, 1));

    contText.setFont(font);
    contText.setString("Cliquez sur l'écran pour commencer");
    contText.setCharacterSize(20);
    contText.setPosition(sf::Vector2f(manager.width - contText.getGlobalBounds().width - 20, manager.height - contText.getGlobalBounds().height - 20));
}

void MenuOpening::render(sf::RenderWindow& window) {
    window.draw(manager.menuReglesSprite);
    window.draw(explText);
    window.draw(contText);
}

void MenuOpening::handleEvent(sf::Event event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        manager.isInGame = true;
        manager.isInOpening = false;
        manager.changeState(std::make_unique<MenuInGame>(manager));
    }
}

void MenuOpening::update(sf::Time elapsedTime[[maybe_unused]]) const {/* Pas besoin d'update ici */}