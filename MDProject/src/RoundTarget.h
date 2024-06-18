#pragma once
#include "SFML/Graphics.hpp"

class RoundTarget {
private:
    sf::Sprite mSprite;

public:
    RoundTarget(sf::Color color, double x, double y);
    virtual ~RoundTarget();
    sf::Sprite& getSprite();
    void render(sf::RenderWindow& window) const;
    void setColor(sf::Color c);
    bool isHitByMouse(const sf::Vector2f& mousePosition) const;
    void setPosition(const sf::Vector2f& mousePosition);
    virtual void move(sf::Vector2f& mousePosition) = 0;
};
