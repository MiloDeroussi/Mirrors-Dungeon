#include "HSalle.h"

HSalle::HSalle(std::string id, int nsalle, int heal_percent): Salle(id,nsalle)
{
	this->heal_percent = heal_percent;
}
