#pragma once

#ifndef __SALLE_H__
#define __SALLE_H__
#include <string>

class Porte;

class Salle {
private:
	int nsalle;
	std::string id;
public:
	enum class Type { ESalle, MiniBoss, MediumBoss, Boss, HSalle, USalle };
	explicit Salle(std::string id, int nsalle);

	void Draw();
	void DrawDoors();
	std::string getid();
};

#endif // !__SALLE_H__