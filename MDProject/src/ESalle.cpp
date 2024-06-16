#include "ESalle.h"

ESalle::ESalle(std::string id, int nsalle, pugi::xml_node room) : Salle(id,nsalle) {
	this->room = room;

}

void ESalle::GenerateEnnemis() {

}