#pragma once

#ifndef __PORTE_H__
#define __PORTE_H__
#include "Salle.h"


class Salle;

class Porte {
private:
	Salle *salle;
	bool isRight;
	//string salleType;
	double x;
	double y;
	double xshape;
	double yshape;
public:
	explicit Porte(Salle* salle, bool isRight);
	explicit Porte();
	void onClick();
};

#endif // !__PORTE_H__