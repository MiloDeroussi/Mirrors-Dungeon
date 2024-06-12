#include "Salle.h"
#include "Porte.h"
#include <pugixml.hpp>
#include <vector>
#include "Ennemi.h"
#include <pugixml.hpp>

class ESalle : public Salle {
private:
	std::vector<Ennemi> ennemis;
	pugi::xml_text listeEnnemis;
public:
	void GenerateEnnemis();
	explicit ESalle(int id, Porte *porteR, Porte *porteL, int nsalle, std::vector<Ennemi> ennemis, pugi::xml_document listeEnnemis);
};
