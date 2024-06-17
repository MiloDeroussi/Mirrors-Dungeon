#include "MenuStateManager.h"
#include "Menu.h"

MenuStateManager::MenuStateManager() {
    if (!textureJeu.loadFromFile("resources/Donjon.png")) {
        printf("Impossible de load textureJeu\n");
    }
    if (!textureMenuPrincipal.loadFromFile("resources/Donjon.png")) {
        printf("Impossible de load textureMenuPrincipal\n");
    }
    if (!textureMenuRegles.loadFromFile("resources/Regles.jpg")) {
        printf("Impossible de load textureMenuRegles\n");
    }
    if (!textureFin.loadFromFile("resources/Donjon.png")) {
        printf("Impossible de load textureFin\n");
    }

    fondSprite.setTexture(textureJeu);
    menuPrincipalSprite.setTexture(textureMenuPrincipal);
    menuReglesSprite.setTexture(textureMenuRegles);
    finSprite.setTexture(textureFin);

    sf::Vector2u windowSize = { 800, 600 };

    // Calculate scale factors for each texture
    auto scaleSpriteToWindow = [&](sf::Sprite& sprite, const sf::Texture& texture) {
        sf::Vector2u textureSize = texture.getSize();
        float scaleX = static_cast<float>(windowSize.x) / float(textureSize.x);
        float scaleY = static_cast<float>(windowSize.y) / float(textureSize.y);
        sprite.setScale(scaleX, scaleY);
        };

    scaleSpriteToWindow(fondSprite, textureJeu);
    scaleSpriteToWindow(menuPrincipalSprite, textureMenuPrincipal);
    scaleSpriteToWindow(menuReglesSprite, textureMenuRegles);
    scaleSpriteToWindow(finSprite, textureFin);

    mFont.loadFromFile("resources/Sansation.ttf");
    auto newState = std::make_unique<Menu>(*this);
    menuState = std::move(newState);
}

void MenuStateManager::render(sf::RenderWindow& window) const {
    menuState->render(window);
}

void MenuStateManager::handleEvent(sf::Event event, sf::RenderWindow& window) {
    menuState->handleEvent(event, window);
}

void MenuStateManager::changeState(std::unique_ptr<MenuState> state) {
    menuState = std::move(state);
}