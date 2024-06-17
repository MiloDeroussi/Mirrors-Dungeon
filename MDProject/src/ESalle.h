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
	std::vector<Ennemi> GenerateEnnemis() const;
	double defineHealth(std::string const& str) const;
	double defineAttack(std::string const& str) const;
	std::string defineSprite(std::string const& str) const;
	explicit ESalle(std::string const & id, int nsalle, pugi::xml_node room);
};
