#include "MenuFin.h"
#include "MenuStateManager.h"

MenuFin::MenuFin(MenuStateManager& manager) : MenuState(manager) {
    float h_width = manager.width / 2;
    font.loadFromFile("resources/Sansation.ttf");

    winText1.setFont(font);
    winText1.setString("Bravo !");
    winText1.setCharacterSize(30);
    winText1.setPosition(sf::Vector2f(h_width - winText1.getGlobalBounds().width / 2, 200));
    winText1.setFillColor(sf::Color::Green);

    winText2.setFont(font);
    winText2.setString("Vous avez vaincu nataS et sauv� Hildegarde !");
    winText2.setCharacterSize(30);
    winText2.setPosition(sf::Vector2f(h_width - winText2.getGlobalBounds().width / 2, 300));

    loseText1.setFont(font);
    loseText1.setString("Perdu !");
    loseText1.setCharacterSize(30);
    loseText1.setPosition(sf::Vector2f(h_width - loseText1.getGlobalBounds().width / 2, 200));
    loseText1.setFillColor(sf::Color::Red);

    loseText2.setFont(font);
    loseText2.setString("Vous avez p�ri dans le donjon");
    loseText2.setCharacterSize(30);
    loseText2.setPosition(sf::Vector2f(h_width - loseText2.getGlobalBounds().width / 2, 300));

    loseText3.setFont(font);
    loseText3.setString("Qu'avez vous fait ? Hildegarde est morte...");
    loseText3.setCharacterSize(30);
    loseText3.setPosition(sf::Vector2f(h_width - loseText3.getGlobalBounds().width / 2, 300));

    backText.setFont(font);
    backText.setString("Appuyez pour quitter");
    backText.setCharacterSize(20);
    backText.setPosition(sf::Vector2f(manager.width - backText.getGlobalBounds().width - 20, manager.height - backText.getGlobalBounds().height - 20));
}

void MenuFin::render(sf::RenderWindow& window) {
    window.draw(manager.finSprite);
    if (manager.victory) {
        window.draw(winText1);
        window.draw(winText2);
    }
    else {
        window.draw(loseText1);
        if (manager.hilDeath) {
            window.draw(loseText3);
        }
        else {
            window.draw(loseText2);
        }
    }
    window.draw(backText);
}

void MenuFin::handleEvent(sf::Event event, sf::RenderWindow& window) {
    if (event.type == sf::Event::KeyPressed) {
        window.close();
    }
}