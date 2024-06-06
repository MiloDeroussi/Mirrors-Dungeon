#pragma once
#include "SFML/Graphics.hpp"

class Balle {
private:
	bool IsAlly;
	double x;
	double y;
	double size;

public:
	explicit Balle(bool IsAlly, double x, double y, double size);
	void grow(double speed);
	void doDamage();
	void draw();
};