#include "Salle.h"
#include "Porte.h"

Salle::Salle(std::string id, int nsalle) {
	this->id = id;
	this->nsalle = nsalle;
}

void Salle::Draw() {

}

void Salle::DrawDoors() {

}

std::string Salle::getid()
{
	return this->id ;
}
