#include "Salle.h"
#include "Porte.h"

Salle::Salle(int id, Porte *porteR, Porte *porteL, int nsalle) {
	//this->id = id;
	this->nsalle = nsalle;
	this->porteL = porteL;
	this->porteR = porteR;
}

Salle::Salle(){}


void Salle::Draw() {

}

void Salle::DrawDoors() {

}

void Salle::GenerateNextRooms(Salle salleR, Salle salleL) {

}