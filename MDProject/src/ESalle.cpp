#include "ESalle.h"
#include <string_view>

ESalle::ESalle(std::string const& id, int nsalle, pugi::xml_node room) : Salle(id,nsalle) {
	this->room = room;

}

std::vector<Ennemi> ESalle::GenerateEnnemis() const {
	std::vector<Ennemi> ennemies;
	
	for (const auto& child : room.children()) {
		if (child.name() == std::string("ennemi")) {
			std::string id = child.attribute("id").as_string();
// faire une condition pour séparer Offensif et Non Offensif
			ennemies.emplace_back(defineHealth(id), child.attribute("xpos").as_int(), child.attribute("ypos").as_int(), child.attribute("pattern").as_string(), defineSprite(id), defineAttack(id));
		}
	}
	return ennemies;
}

std::string ESalle::defineSprite(std::string const &str) const {
	if (str == std::string_view("demon")) {
		return std::string("resources/demon.png");
	}
	else if (str == std::string_view("demon_mineur")) {
		return std::string("resources/demon_mineur.png");
	}
	else if (str == std::string_view("demon_shield")) {
		return std::string("resources/demon_shield.png");
	}
	else if (str == std::string_view("demon_miroir")) {
		return std::string("resources/demon_miroir.png");
	}
	else if (str == std::string_view("demon_majeur")) {
		return std::string("resources/demon_majeur.png");
	}
	else if (str == std::string_view("beholder")) {
		return std::string("resources/beholder.png");
	}
	else if (str == std::string_view("natas")) {
		return std::string("resources/natas.png");
	}
	else if (str == std::string_view("hildegarde")) {
		return std::string("resources/hildegarde.png");
	}
	
}

double ESalle::defineHealth(std::string const & str) const {
	if (str == std::string_view("demon")) {
		return 2.0;
	}
	else if (str == std::string_view("demon_mineur")) {
		return 1.0;
	}
	else if (str == std::string_view("demon_shield")) {
		return 3.0;
	}
	else if (str == std::string_view("demon_miroir")) {
		return 5.0;
	}
	else if (str == std::string_view("demon_majeur")) {
		return 7.0;
	}
	else if (str == std::string_view("beholder")) {
		return 10.0;
	}
	else if (str == std::string_view("natas")) {
		return 12.0;
	}
	else if (str == std::string_view("hildegarde")) {
		return 10.0;
	}
}

double ESalle::defineAttack(std::string const& str) const {
	if (str == std::string_view("demon")) {
		return 1.0;
	}
	else if (str == std::string_view("demon_mineur")) {
		return 1.0;
	}
	else if (str == std::string_view("demon_shield")) {
		return 0;
	}
	else if (str == std::string_view("demon_miroir")) {
		return 0;
	}
	else if (str == std::string_view("demon_majeur")) {
		return 5.0;
	}
	else if (str == std::string_view("beholder")) {
		return 3.0;
	}
	else if (str == std::string_view("natas")) {
		return 5.0;
	}
	else if (str == std::string_view("hildegarde")) {
		return 7.0;
	}
}