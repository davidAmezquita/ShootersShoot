#pragma once
#include "dependency.h"
#include "Player.h"
#include "Wall.h"



class Game {

private:
    sf::RenderWindow window;
    sf::Text bulletCount;
    sf::Texture t;
    sf::Sprite bg;
    Player *myPlayer;
    bool currShotSate, prevShotState;
    std::vector<Zombie*> zombies;
    std::vector<Wall*> walls;


public:

    Game() {

        window.create(sf::VideoMode(W_WIDTH, W_HEIGHT), "Shooters Shot");
        window.setFramerateLimit(80);
        
        if (!t.loadFromFile("assets/background.png")) { exit(0); }
        bg.setTexture(t);

        myPlayer = new Player("assets/player_1.png", 0, (W_HEIGHT - FLOOR_H) - 50.f, 64.f, 64.f);

        //create walls
        for (int i = 0; i < 10; i++) {
            if (level_1[i].orientation == 0) {
                walls.push_back(new Wall("assets/wall_V.png", level_1[i].location, 92.f, 32.f));
            }
            else {
                walls.push_back(new Wall("assets/wall_H.png", level_1[i].location, 32.f, 96.f));
            }
        }

        //create zombies
        
        for (int j = 10; j < 15; j++) {
            zombies.push_back(new Zombie(level_1[j].location, 64.f, 64.f, level_1[j].orientation));
        }
        
        prevShotState = false;
        currShotSate = false;
    }

    ~Game() {
        zombies.clear();
        walls.clear();

        delete myPlayer;
    }
	
	void start() {


        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                    myPlayer->moveTrajectory('w');
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    myPlayer->moveTrajectory('s');
                }

                currShotSate = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

                if (currShotSate && prevShotState != currShotSate) {
                    myPlayer->shoot();
                    
                }
                prevShotState = currShotSate;
            }
            
            
            window.clear();
            window.draw(bg);
            myPlayer->update(window);
            myPlayer->checkHits(zombies, walls);
          
            for (const auto &z : zombies) {
                z->Draw(window);
            }

            for (const auto&  w: walls) {
                w->Draw(window);
            }
            
            window.display();
        }
	}
};



