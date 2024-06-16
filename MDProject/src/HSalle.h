#pragma once

#include "Salle.h"
#include <pugixml.hpp>
#include <vector>
#include <pugixml.hpp>

class HSalle : public Salle {
private:
	int heal_percent;
public:
	explicit HSalle(std::string id, int nsalle, int heal_percent);
};
