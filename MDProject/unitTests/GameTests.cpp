#include <gtest/gtest.h>
#include <string>
#include "Game.h"
#include "Gunther.h"

namespace GameTesting {
	TEST(GameTests, gunther_create) {
		Game game;
		double health = game.getGunther().getHealth();
		EXPECT_FLOAT_EQ(10, health);
	}
}