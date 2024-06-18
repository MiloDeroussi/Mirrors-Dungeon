#pragma once

#include "Salle.h"
#include <pugixml.hpp>
#include <vector>
#include "Ennemi.h"
#include "Offensif.h"
#include <pugixml.hpp>

class ESalle : public Salle {
private:
	pugi::xml_node room;
	std::vector<Ennemi> ennemis;
	std::vector<Offensif> ennemis_off;

public:
	std::vector<Ennemi>& getEnnemis();
	std::vector<Offensif>& getEnnemisOff();
	bool defineType(std::string const& str) const;
	double defineHealth(std::string const& str) const;
	double defineAttack(std::string const& str) const;
	std::string defineSprite(std::string const& str) const;
	explicit ESalle(std::string const& id, int nsalle, pugi::xml_node room);
};