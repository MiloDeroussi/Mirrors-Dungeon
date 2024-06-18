#pragma once

#include "Salle.h"
#include <pugixml.hpp>
#include <vector>
#include <pugixml.hpp>

class USalle : public Salle {
private:
	int nb_augment;
public:
	explicit USalle(const std::string& id, int nsalle, int nb_augment);
};