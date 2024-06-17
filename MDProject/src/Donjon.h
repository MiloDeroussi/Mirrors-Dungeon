#pragma once

#include <pugixml.hpp>
#include <vector>
#include <random>
#include <memory>
#include "HSalle.h"
#include "USalle.h"
#include "ESalle.h"


class Donjon {
private:
	int max_difficulties_room = 4;
	int max_difficulties = 2;
	pugi::xml_document doc ;
	pugi::xml_node racine ;
	std::random_device rd;
	std::mt19937 gen;
	std::vector<std::shared_ptr<Salle>> salles;
public:
	std::vector<Salle::Type> GenerateDungeon() const;
	void generateSalle(std::vector<Salle::Type> donjon, int index, int difficulty);
	explicit Donjon();
	std::vector<std::shared_ptr<Salle>> getSalles();
};

