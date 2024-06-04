#include "RoundTarget.h"

RoundTarget::RoundTarget(float radius, sf::Color color, float x, float y, float a, float b)
{
    mShape.setRadius(radius);
    mShape.setFillColor(color);
    mShape.setPosition(x, y);
    mSpeed.x = a;
    mSpeed.y = b;
    mState = RoundTargetStatus::Alive;
    rayon_initial = radius;

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

void RoundTarget::update(const sf::Time& elapsedTime, const sf::Vector2u& windowSize) {
    if (mState == RoundTargetStatus::Dead) {
        return;
    }

    else if (mState == RoundTargetStatus::Dying) {
        FramesLeft--;
        mShape.setRadius(rayon_initial * FramesLeft / 60);
        if (!FramesLeft) {
            mState = RoundTargetStatus::Dead;
        }
        return;
    }

    sf::Vector2f movement(0.f, 0.f);
    if (mShape.getPosition().x >= static_cast<float>(windowSize.x) - mShape.getRadius() * 2) {
        mSpeed.x = -mSpeed.x;
    }
    if (mShape.getPosition().x <= 0) {
        mSpeed.x = -mSpeed.x;
    }

    if (mShape.getPosition().y >= static_cast<float>(windowSize.y) - mShape.getRadius() * 2) {
        mSpeed.y = -mSpeed.y;
    }

    if (mShape.getPosition().y <= 0) {
        mSpeed.y = -mSpeed.y;
    }

    movement.x = mSpeed.x;
    movement.y = mSpeed.y;

    mShape.move(movement * elapsedTime.asSeconds());

}

bool RoundTarget::isHitByMouse(const sf::Vector2i& mousePosition) const {
    float minx = mShape.getPosition().x;
    float miny = mShape.getPosition().y;
    float maxx = minx + 2 * mShape.getRadius();
    float maxy = miny + 2 * mShape.getRadius();
    if (minx <= mousePosition.x && mousePosition.x <= maxx && miny <= mousePosition.y && mousePosition.y <= maxy) {
        return true;
    }
    return false;
}