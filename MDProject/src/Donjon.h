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
	pugi::xml_document doc;
	pugi::xml_node racine;
	std::random_device rd;
	std::mt19937 gen;
	std::vector<std::shared_ptr<Salle>> salles;
	std::vector<Salle::Type> donjon_path;

public:
	explicit Donjon();
	std::vector<Salle::Type>& getDungeonPath();
	std::vector<std::shared_ptr<Salle>>& getSalles();
	void generateSalle(std::vector<Salle::Type> donjon, int index, int difficulty);
};

