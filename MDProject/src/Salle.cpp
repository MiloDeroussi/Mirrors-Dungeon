#include "Salle.h"
#include "Porte.h"

Salle::Salle(const std::string& id, int nsalle) : id(id), nsalle(nsalle) {}

std::string Salle::getid() const {
	return this->id;
}