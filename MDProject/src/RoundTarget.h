#pragma once
#include "SFML/Graphics.hpp"

enum class RoundTargetStatus { Alive, Dying, Dead };

class RoundTarget {
public:
    RoundTarget(float radius, sf::Color color, float x, float y, float a, float b);
    void					drawCurrent(sf::RenderWindow& window) const;
    void					update(const sf::Time& elapsedTime, const sf::Vector2u& windowSize);
    sf::CircleShape         getShape() const;
    RoundTargetStatus       getState() const;
    void                    setColor(sf::Color c);
    void                    setSpeed(float new_x, float new_y);
    bool                    isHitByMouse(const sf::Vector2i& mousePosition) const;
    void                    die();

private:
    bool					mIsMovingUp{ false };
    bool					mIsMovingDown{ false };
    bool					mIsMovingRight{ false };
    bool					mIsMovingLeft{ false };
    sf::CircleShape			mShape;
    sf::Vector2f            mSpeed;
    RoundTargetStatus       mState;
    int                     FramesLeft = 60;
    float                   rayon_initial;
};
