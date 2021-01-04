#include "Game.h"
#include "Menus.h"


int main()
{
    Menu menu;
    menu.show();
    
    
    const float wallHeight = 92.f;
    if (menu.levelSelected == 1) {
        //create level 1, first 10 entries refer to wall position, last 5 refer to zombies
        level_1[0].location = sf::Vector2f(300.f, W_HEIGHT - FLOOR_H - wallHeight);
        level_1[0].orientation = 0;
        level_1[1].location = sf::Vector2f(500.f, W_HEIGHT - FLOOR_H - wallHeight);
        level_1[1].orientation = 0;
        level_1[2].location = sf::Vector2f(700.f, W_HEIGHT - FLOOR_H - wallHeight);
        level_1[2].orientation = 0;
        level_1[3].location = sf::Vector2f(900.f, W_HEIGHT - FLOOR_H - wallHeight);
        level_1[3].orientation = 0;
        level_1[4].location = sf::Vector2f(1120.f, 300.f);
        level_1[4].orientation = 1;
        level_1[5].location = sf::Vector2f(1088.f, 236.f);
        level_1[5].orientation = 0;
        level_1[6].location = sf::Vector2f(1000.f, 504.f);
        level_1[6].orientation = 1;
        level_1[7].location = sf::Vector2f(600.f, 300.f);
        level_1[7].orientation = 1;
        level_1[8].location = sf::Vector2f(300.f, 0.f);
        level_1[8].orientation = 0;
        level_1[9].location = sf::Vector2f(200.f, 92.f);
        level_1[9].orientation = 1;

        //zombies
        level_1[10].location = sf::Vector2f(532.f, W_HEIGHT - FLOOR_H - 60.f);
        level_1[10].orientation = 0;
        level_1[11].location = sf::Vector2f(1100.f, W_HEIGHT - FLOOR_H - 60.f);
        level_1[11].orientation = 0;
        level_1[12].location = sf::Vector2f(232.f, 30.f);
        level_1[12].orientation = 0;
        level_1[13].location = sf::Vector2f(1120.f, 236.f);
        level_1[13].orientation = 1;
        level_1[14].location = sf::Vector2f(400.f, W_HEIGHT - FLOOR_H - 60.f);
        level_1[14].orientation = 1;
    }
    else if (menu.levelSelected == 2) {
        //create level 2, first 10 entries refer to wall position, last 5 refer to zombies
        level_1[0].location = sf::Vector2f(500.f, 500.f);
        level_1[0].orientation = 0;
        level_1[1].location = sf::Vector2f(500.f, 400.f);
        level_1[1].orientation = 0;
        level_1[2].location = sf::Vector2f(500.f, 250.f);
        level_1[2].orientation = 0;
        level_1[3].location = sf::Vector2f(500.f, 0.f);
        level_1[3].orientation = 0;
        level_1[4].location = sf::Vector2f(436.f, 92.f);
        level_1[4].orientation = 1; 
        level_1[5].location = sf::Vector2f(532.f, 400.f);
        level_1[5].orientation = 1;      
        level_1[6].location = sf::Vector2f(1122.f, 500.f);
        level_1[6].orientation = 1;       
        level_1[7].location = sf::Vector2f(1122.f, 300.f);
        level_1[7].orientation = 1;       
        level_1[8].location = sf::Vector2f(1000.f, 0.f);
        level_1[8].orientation = 0;
        level_1[9].location = sf::Vector2f(1000.f, 94.f);
        level_1[9].orientation = 1;
        
        //zombies positions
        level_1[10].location = sf::Vector2f(535.f, W_HEIGHT - FLOOR_H - 60.f);
        level_1[10].orientation = 1;
        level_1[11].location = sf::Vector2f(440.f, 30.f);
        level_1[11].orientation = 0;
        level_1[12].location = sf::Vector2f(1120.f, 236.f);
        level_1[12].orientation = 1;
        level_1[13].location = sf::Vector2f(1120.f, 436.f);
        level_1[13].orientation = 1;
        level_1[14].location = sf::Vector2f(1032.f, 32.f);
        level_1[14].orientation = 1;
        
    }

    if (menu.gameStart) {
        Game g;
        g.start();
    }
    

    return 0;
}