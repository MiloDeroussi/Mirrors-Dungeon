#pragma once
#include "SFML/Graphics.hpp"

enum class RoundTargetStatus { Alive, Dying, Dead };

class RoundTarget {
public:
    RoundTarget(float radius, sf::Color color, float x, float y, float a, float b);
    void					drawCurrent(sf::RenderWindow& window) const;
    sf::CircleShape         getShape() const;
    RoundTargetStatus       getState() const;
    void                    setColor(sf::Color c);
    void                    setSpeed(float new_x, float new_y);
    bool                    isHitByMouse(const sf::Vector2f& mousePosition) const;
    void                    die();
    void                    setPosition(const sf::Vector2f& mousePosition);
    void                    move(sf::Vector2f& mousePosition);

protected:
    sf::CircleShape			mShape;
    sf::Vector2f            mSpeed;
    RoundTargetStatus       mState;
};
