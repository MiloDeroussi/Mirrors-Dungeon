#include "RoundTarget.h"

using namespace std;

RoundTarget::RoundTarget(sf::Color color, double x, double y)
{
    mSprite.setColor(color);
    mSprite.setPosition(float(x), float(y));
}

void RoundTarget::render(sf::RenderWindow& window) const {
    window.draw(mSprite);
}

sf::Sprite& RoundTarget::getSprite() {
    return mSprite;
}

void RoundTarget::setColor(sf::Color c) {
    mSprite.setColor(c);
}

void RoundTarget::setPosition(const sf::Vector2f& mousePosition) {
    mSprite.setPosition(mousePosition);
}

bool RoundTarget::isHitByMouse(const sf::Vector2f& mousePosition) const {
    return mSprite.getGlobalBounds().contains(mousePosition);
}