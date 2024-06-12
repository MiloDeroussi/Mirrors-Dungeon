#include "ESalle.h"

ESalle::ESalle(int id, Porte *porteR, Porte *porteL, int nsalle, std::vector<Ennemi> ennemis, pugi::xml_document listeEnnemis) : Salle(id,porteR,porteL,nsalle) { 
	this->ennemis = ennemis; //à modifier quand on fera plus précisément l'implémentation
	this->listeEnnemis = listeEnnemis.text();
}

void ESalle::GenerateEnnemis() {

}