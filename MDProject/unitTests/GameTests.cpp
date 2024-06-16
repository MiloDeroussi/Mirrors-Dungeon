#include <gtest/gtest.h>
#include <string>
#include <sstream>
#include <iostream>
#include "Game.h"
#include "Gunther.h"
#include "Donjon.h"
#include "Salle.h"

namespace GameTesting {
    TEST(GameTests, Create) {
        Game game;
        double health = game.getGunther().getHealth();
        EXPECT_FLOAT_EQ(10, health);

        Ennemi ennemi(5.0, 100, 100, "line", "resources/Boule.png", 0);
        EXPECT_FLOAT_EQ(ennemi.getHealth(), 5.0);
        EXPECT_EQ(ennemi.getPattern(), "line");
    }

    TEST(GameTests, Shoot) {
        Game game;

        auto initialBulletCount = game.getGunther().getPistolet().getActiveBalle().size();
        game.getGunther().getPistolet().shoot(game.getActiveEnnemi(), game.getActiveOffEnnemi());
        EXPECT_EQ(game.getGunther().getPistolet().getActiveBalle().size(), initialBulletCount + 1);

        for (Offensif& ennemi : game.getActiveOffEnnemi()) {
            auto initialBulletEnnemiCount = ennemi.getActiveBalleEnnemi().size();
            ennemi.shoot();
            EXPECT_EQ(ennemi.getActiveBalleEnnemi().size(), initialBulletEnnemiCount + 1);
        }

        game.updateBullets(sf::seconds(5.0));
        EXPECT_EQ(game.getGunther().getPistolet().getActiveBalle().size(), initialBulletCount);
        for (Offensif& ennemi : game.getActiveOffEnnemi()) {
            EXPECT_EQ(ennemi.getActiveBalleEnnemi().size(), 0);
        }
    }

    TEST(GameTests, BouclierMiroirMovesWithMouse) {
        Game game;
        Gunther& gunt = game.getGunther();
        sf::Vector2f newPosition(gunt.getBouclier().getSprite().getPosition());
        sf::Event event1;
        event1.type = sf::Event::MouseButtonPressed; event1.mouseButton.button = sf::Mouse::Left;
        sf::Mouse::setPosition(sf::Vector2i(newPosition), game.getWindow());
        game.draganddrop(event1);

        sf::Event event2;
        event2.type = sf::Event::MouseMoved; sf::Vector2f moveto(200, 200);
        sf::Mouse::setPosition(sf::Vector2i(moveto), game.getWindow());
        game.draganddrop(event2);

        sf::Event event3;
        event3.type = sf::Event::MouseButtonReleased; event3.mouseButton.button = sf::Mouse::Left;
        game.draganddrop(event3);

        sf::Vector2f bouclierPosition = gunt.getBouclier().getSprite().getPosition();
        EXPECT_EQ(bouclierPosition.x, moveto.x - gunt.getBouclier().getSprite().getGlobalBounds().width / 2);
        EXPECT_EQ(bouclierPosition.y, moveto.y - gunt.getBouclier().getSprite().getGlobalBounds().height / 2);

        newPosition = gunt.getBouclier().getSprite().getPosition();
        event1.type = sf::Event::MouseButtonPressed; event1.mouseButton.button = sf::Mouse::Right;
        sf::Mouse::setPosition(sf::Vector2i(newPosition), game.getWindow());
        game.draganddrop(event1);

        event2.type = sf::Event::MouseMoved; sf::Vector2f moveto2(300, 300);
        sf::Mouse::setPosition(sf::Vector2i(moveto2), game.getWindow());
        game.draganddrop(event2);

        event3.type = sf::Event::MouseButtonReleased; event3.mouseButton.button = sf::Mouse::Right;
        game.draganddrop(event3);

        bouclierPosition = gunt.getBouclier().getSprite().getPosition();
        EXPECT_FALSE(bouclierPosition.x == moveto2.x - gunt.getBouclier().getSprite().getGlobalBounds().width / 2);
        EXPECT_FALSE(bouclierPosition.y == moveto2.y - gunt.getBouclier().getSprite().getGlobalBounds().height / 2);
    }

    TEST(GameTests, PistoletMovesWithMouse) {
        Game game;
        Gunther& gunt = game.getGunther();
        sf::Vector2f newPosition(gunt.getPistolet().getSprite().getPosition());
        sf::Event event1;
        event1.type = sf::Event::MouseButtonPressed; event1.mouseButton.button = sf::Mouse::Right;
        sf::Mouse::setPosition(sf::Vector2i(newPosition), game.getWindow());
        game.draganddrop(event1);

        sf::Event event2;
        event2.type = sf::Event::MouseMoved; sf::Vector2f moveto(200, 200);
        sf::Mouse::setPosition(sf::Vector2i(moveto), game.getWindow());
        game.draganddrop(event2);

        sf::Event event3;
        event3.type = sf::Event::MouseButtonReleased; event3.mouseButton.button = sf::Mouse::Right;
        game.draganddrop(event3);

        sf::Vector2f pistoletPosition = gunt.getPistolet().getSprite().getPosition();
        EXPECT_FLOAT_EQ(pistoletPosition.x, moveto.x - gunt.getPistolet().getSprite().getGlobalBounds().width * 3 / 4);
        EXPECT_FLOAT_EQ(pistoletPosition.y, moveto.y - gunt.getPistolet().getSprite().getGlobalBounds().height * 3 / 4);

        newPosition = gunt.getPistolet().getSprite().getPosition();
        event1.type = sf::Event::MouseButtonPressed; event1.mouseButton.button = sf::Mouse::Left;
        sf::Mouse::setPosition(sf::Vector2i(newPosition), game.getWindow());
        game.draganddrop(event1);

        event2.type = sf::Event::MouseMoved; sf::Vector2f moveto2(300, 300);
        sf::Mouse::setPosition(sf::Vector2i(moveto2), game.getWindow());
        game.draganddrop(event2);

        event3.type = sf::Event::MouseButtonReleased; event3.mouseButton.button = sf::Mouse::Left;
        game.draganddrop(event3);

        pistoletPosition = gunt.getPistolet().getSprite().getPosition();
        EXPECT_FALSE(pistoletPosition.x == moveto2.x - gunt.getPistolet().getSprite().getGlobalBounds().width * 3 / 4);
        EXPECT_FALSE(pistoletPosition.y == moveto2.y - gunt.getPistolet().getSprite().getGlobalBounds().height * 3 / 4);
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
            EXPECT_EQ(salles.at(i), expected_salles.at(i));
            Salle salle = donjon.generateSalle(salles, i, difficulty);
            printf("%s\n\n", salle.getid().c_str());
        }


    }

}