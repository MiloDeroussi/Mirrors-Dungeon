#include <gtest/gtest.h>
#include <string>
#include "Game.h"
#include "Gunther.h"
#include "Donjon.h"
#include "Salle.h"

namespace GameTesting {
	TEST(GameTests, gunther_create) {
		Game game;
		double health = game.getGunther().getHealth();
		EXPECT_FLOAT_EQ(10, health);
	}

	TEST(GameTests, dungeon_create) {
		int difficulty = 1;
		Donjon donjon;
		std::vector<Salle::Type> expected_salles = {
		Salle::Type::ESalle,
		Salle::Type::ESalle,
		Salle::Type::USalle,
		Salle::Type::ESalle,
		Salle::Type::ESalle,
		Salle::Type::USalle,
		Salle::Type::MiniBoss,
		Salle::Type::HSalle,
		Salle::Type::ESalle,
		Salle::Type::ESalle,
		Salle::Type::USalle,
		Salle::Type::ESalle,
		Salle::Type::ESalle,
		Salle::Type::USalle,
		Salle::Type::MediumBoss,
		Salle::Type::HSalle,
		Salle::Type::Boss
		};


		std::vector<Salle::Type> salles = donjon.GenerateDungeon();
		EXPECT_EQ(salles.size(), expected_salles.size());
		for (int i = 0; i < expected_salles.size(); i++) {
			if (salles.at(i) == Salle::Type::MiniBoss) {
				difficulty = 2;
			}
			EXPECT_EQ(salles.at(i),expected_salles.at(i));
			Salle salle = donjon.generateSalle(salles, i,difficulty);
			printf("%s\n\n", salle.getid().c_str());
		}
		
		
	}
}