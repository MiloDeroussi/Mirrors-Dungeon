#include "Donjon.h"
#include <iostream>

Donjon::Donjon(): gen(rd()) {
	if (auto result = doc.load_file("resources/salles.xml"); !result)
    {
        std::cerr << "Could not open file salles.xml because " << result.description() << std::endl;
    }
	racine = doc.document_element();
	using enum Salle::Type;

	pugi::xml_node node;
	donjon_path = {
		ESalle,
		ESalle,

		ESalle,
		ESalle,

		MiniBoss,
		HSalle,
		ESalle,
		ESalle,

		ESalle,
		ESalle,

		MediumBoss,
		HSalle,
		Boss
	};
}

std::vector<std::shared_ptr<Salle>>& Donjon::getSalles() {
	return salles;
}

std::vector<Salle::Type>& Donjon::getDungeonPath() {
	return donjon_path;
}

void Donjon::generateSalle(std::vector<Salle::Type> donjon, int index, int difficulty) {
	pugi::xml_node node;
	pugi::xml_node room;
	if (donjon.at(index) == Salle::Type::USalle) {
		node = racine.child("usalle");
	}
	else if (donjon.at(index) == Salle::Type::HSalle) {
		node = racine.child("hsalle");
	}
	else {
		node = racine.child("esalle");
		if (donjon.at(index) == Salle::Type::MiniBoss) {
			node = node.child("mini_boss");
		}
		else if (donjon.at(index) == Salle::Type::MediumBoss) {
			node = node.child("medium_boss");
		}
		else if (donjon.at(index) == Salle::Type::Boss) {
			node = node.child("boss");
		}
		else if (difficulty == 1) {
			node = node.child("difficulty_rank_1");
		}
		else if (difficulty == 2){
			node = node.child("difficulty_rank_2");
		}
	}

	int randnode = 0;


	if (auto nb = (int) std::distance(node.children("salle").begin(), node.children("salle").end()); nb == 0){
		std::cout << "No node found\n";
	}
	else {
		std::uniform_int_distribution dis(0, nb-1);
		randnode = dis(gen);
	}
		
	int i = 0;
	for (auto n : node.children()) {
		if (i == randnode) {
			room = n;
			break;
		}
		i++;
	}
	std::cout << room.child_value("id");

	if (donjon.at(index) == Salle::Type::USalle) {
		auto salle = std::make_shared<USalle>(room.attribute("id").as_string(), index, room.attribute("nb_upgrade").as_int());
		salles.push_back(salle);
		
	}
	else if (donjon.at(index) == Salle::Type::HSalle) {
		auto salle = std::make_shared<HSalle>(room.attribute("id").value(), index,room.attribute("heal").as_int());
		salles.push_back(salle);
		
	}
	else {
		auto salle = std::make_shared<ESalle>(room.attribute("id").value(), index, room);
		salles.push_back(salle);
	}
}

