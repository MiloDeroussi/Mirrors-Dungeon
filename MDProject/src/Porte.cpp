#include "Porte.h"
#include "Salle.h"


Porte::Porte(Salle *salle, bool isRight) {
	this->salle = salle;
	if (isRight) {
		x = 1;
		y = 1;
	}
	else {
		x = -1;
		y = -1;
	}
	xshape = 1; yshape = 1;
}

Porte::Porte() {}

void Porte::onClick() {}