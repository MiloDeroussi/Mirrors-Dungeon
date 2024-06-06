#pragma once
#include "SFML/Graphics.hpp"
#include "Blessable.h"
#include <string>

class Ennemi : public Blessable {
private:
	double x;
	double y;
	std::string MovePattern;

public:
	explicit Ennemi(double health, double x, double y, std::string pattern);
	void draw();
	void move(std::string pattern);
};
