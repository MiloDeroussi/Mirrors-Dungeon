#pragma once

#include "Salle.h"
#include <pugixml.hpp>
#include <vector>
#include "Ennemi.h"
#include <pugixml.hpp>

class ESalle : public Salle {
private:
	pugi::xml_node room;

public:
	void GenerateEnnemis();
	explicit ESalle(std::string id, int nsalle, pugi::xml_node room);
};
