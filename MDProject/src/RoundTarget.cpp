#include "RoundTarget.h"

using namespace std;

RoundTarget::RoundTarget(float radius, sf::Color color, float x, float y, float a, float b)
{
    mShape.setFillColor(color);
    mShape.setRadius(radius);
    mShape.setPosition(x, y);
    mSpeed.x = a;
    mSpeed.y = b;
    mState = RoundTargetStatus::Alive;
}

void RoundTarget::die() {
    mState = RoundTargetStatus::Dying;
}

void RoundTarget::drawCurrent(sf::RenderWindow& window) const {
    window.draw(mShape);
}

sf::CircleShape RoundTarget::getShape() const {
    return mShape;
}

RoundTargetStatus RoundTarget::getState() const {
    return mState;
}

void RoundTarget::setColor(sf::Color c) {
    mShape.setFillColor(c);
}

void RoundTarget::setSpeed(float new_x, float new_y) {
    mSpeed.x = new_x;
    mSpeed.y = new_y;
}

void RoundTarget::setPosition(const sf::Vector2f& mousePosition) {
    mShape.setPosition(mousePosition);
}

bool RoundTarget::isHitByMouse(const sf::Vector2f& mousePosition) const {
    float minx = mShape.getPosition().x;
    float miny = mShape.getPosition().y;
    float maxx = minx + 2 * mShape.getRadius();
    float maxy = miny + 2 * mShape.getRadius();
    if (minx <= mousePosition.x && mousePosition.x <= maxx && miny <= mousePosition.y && mousePosition.y <= maxy) {
        return true;
    }
    return false;
}

void RoundTarget::move(sf::Vector2f& mousePosition) {
    mousePosition.x -= this->mShape.getRadius();
    mousePosition.y -= this->mShape.getRadius();
    this->setPosition(mousePosition);
}