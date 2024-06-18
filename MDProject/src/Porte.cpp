#include "Porte.h"
#include "Salle.h"


Porte::Porte(Salle* salle, bool isRight) : salle(salle) {
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

void Porte::onClick() const {/* Pour le futur */}