#include "ESalle.h"

ESalle::ESalle(int id, Porte *porteR, Porte *porteL, int nsalle, std::vector<Ennemi> ennemis, pugi::xml_document listeEnnemis) : Salle(id,porteR,porteL,nsalle) { 
	this->ennemis = ennemis; //� modifier quand on fera plus pr�cis�ment l'impl�mentation
	this->listeEnnemis = listeEnnemis.text();
}

void ESalle::GenerateEnnemis() {

}