#pragma once

#ifndef __SALLE_H__
#define __SALLE_H__
#include "Donjon.h"


class Porte;

class Salle {
private:
	Porte *porteR;
	Porte *porteL;
	int nsalle;
	int id;
public:
	explicit Salle(int id, Porte *porteR, Porte *porteL, int nsalle);
	explicit Salle();
	void Draw();
	void DrawDoors();
	void GenerateNextRooms(Salle salleR, Salle salleL);
};

#endif // !__SALLE_H__