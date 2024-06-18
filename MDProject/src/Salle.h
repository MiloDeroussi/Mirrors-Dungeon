#pragma once

#ifndef __SALLE_H__
#define __SALLE_H__
#include <string>

class Porte;

class Salle {
private:
	std::string id;
	int nsalle;

public:
	enum class Type { ESalle, MiniBoss, MediumBoss, Boss, HSalle, USalle };
	explicit Salle(const std::string& id, int nsalle);
	std::string getid() const;
	virtual ~Salle() = default;
};

#endif // !__SALLE_H__