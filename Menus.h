#pragma once
#include "dependency.h"

class Menu {
private:
	sf::RenderWindow mainWin;
    int selection;
    bool changeMenu;
    //main menu attributes
    sf::Text title;
    sf::Font font;
    sf::Text startText;
    sf::Text levelMenu;
    sf::Text quit;
    sf::Texture bgTexture;
    sf::Sprite mainBg;

    //level menu attributes
    sf::Text secTitle;
    sf::Texture bgTexture_2;
    sf::Sprite secBg;
    sf::Texture img_1, img_2, img_3, img_4;
    sf::Sprite sprImg_1, sprImg_2, sprImg_3, sprImg_4;
    sf::RectangleShape rec1, rec2, rec3, rec4;
    sf::Texture t_arrow;
    sf::Sprite backArrow;


public:
    bool gameStart;
    int levelSelected;

    Menu() {

        //setup main menu states
        mainWin.create(sf::VideoMode(W_WIDTH, W_HEIGHT), "Shooters Shoot");
        selection = 0;
        changeMenu = false;
        gameStart = false;
        levelSelected = 1;

        if (!bgTexture.loadFromFile("assets/m_background.jpg")) {
            std::cout << "Couldn't load main menu background.\n";
            exit(0);
        }
        mainBg.setTexture(bgTexture, true);
        mainBg.setTextureRect(sf::IntRect(20.f, 50.f, W_WIDTH, W_HEIGHT));

        //create font for main screen
        if (!font.loadFromFile("C:/Windows/Fonts/BERNHC.ttf")) {
            std::cout << "Couldn't load font.\n";
            exit(0);
        }

        //create title
        title.setFont(font);
        title.setCharacterSize(90);
        title.setPosition(150.f, 50.f);
        title.setString("Shooters Shoot");
        title.setFillColor(sf::Color::Red);

        //create start text
        startText.setFont(font);
        startText.setFillColor(sf::Color::White);
        startText.setCharacterSize(50);
        startText.setString("Start");
        startText.setPosition(1100.f, 250.f);

        levelMenu.setFont(font);
        levelMenu.setFillColor(sf::Color::White);
        levelMenu.setCharacterSize(40);
        levelMenu.setString("Choose Level");
        levelMenu.setPosition(990.f, 350.f);

        quit.setFont(font);
        quit.setFillColor(sf::Color::White);
        quit.setCharacterSize(40);
        quit.setString("Quit");
        quit.setPosition(1125.f, 450.f);

        //-----------------------------------------------------------------------
        //set up sec menu states
        secTitle.setFont(font);
        secTitle.setString("Choose Level");
        secTitle.setPosition(520.f, 10.f);
        secTitle.setFillColor(sf::Color::Green);
        secTitle.setCharacterSize(30);

        if (!bgTexture_2.loadFromFile("assets/m2_background.jpg")) {
            std::cout << "Couldn't load background.\n";
            exit(0);
        }
        secBg.setTexture(bgTexture_2);

        if (!img_1.loadFromFile("assets/level_1.jpg")) {
            std::cout << "Couldn't load image.\n";
            exit(0);
        }
        sprImg_1.setTexture(img_1);
        sprImg_1.setPosition(sf::Vector2f(100.f, 100.f));
        rec1.setSize(sf::Vector2f(410.f, 210.f));
        rec1.setPosition(sf::Vector2f(98.f, 98.f));
        rec1.setOutlineColor(sf::Color::Yellow);
        rec1.setOutlineThickness(5.f);

        if (!img_2.loadFromFile("assets/level_2_.jpg")) {
            std::cout << "Couldn't load image.\n";
            exit(0);
        }
        sprImg_2.setTexture(img_2);
        sprImg_2.setPosition(sf::Vector2f(100.f, 350.f));
        rec2.setSize(sf::Vector2f(410.f, 210.f));
        rec2.setPosition(sf::Vector2f(98.f, 348.f));
        rec2.setOutlineColor(sf::Color::Blue);
        rec2.setOutlineThickness(5.f);

        sprImg_3.setTexture(img_1);
        sprImg_3.setPosition(sf::Vector2f(700.f, 100.f));
        rec3.setSize(sf::Vector2f(410.f, 210.f));
        rec3.setPosition(sf::Vector2f(698.f, 98.f));
        rec3.setOutlineColor(sf::Color::Blue);
        rec3.setOutlineThickness(5.f);

        sprImg_4.setTexture(img_1);
        sprImg_4.setPosition(sf::Vector2f(700.f, 350.f));
        rec4.setSize(sf::Vector2f(410.f, 210.f));
        rec4.setPosition(sf::Vector2f(698.f, 348.f));
        rec4.setOutlineColor(sf::Color::Blue);
        rec4.setOutlineThickness(5.f);

        if (!t_arrow.loadFromFile("assets/backArrow.png")) {
            std::cout << "Couldn't load arrow texture.\n";
            exit(0);
        }
        backArrow.setTexture(t_arrow);
        backArrow.setPosition(sf::Vector2f(0.f, 0.f));


    }

	void show() {

        while (mainWin.isOpen())
        {
            sf::Event event;
            sf::Vector2i mousePosition = sf::Mouse::getPosition(mainWin);
            sf::FloatRect r(mousePosition.x, mousePosition.y, 10.f, 10.f);

            selection = 0;

            if (!changeMenu) {
                menuOptionHandler(r);
            }
            else {
                levelMenuHandler(r);   
            }




            //handles all events
            while (mainWin.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    mainWin.close();

                if (event.type == sf::Event::MouseButtonPressed) {

                    if (selection == 1) { //start text was clicked
                        gameStart = true;
                        mainWin.close();
                    }
                    else if (selection == 2) {  //change level text was clicked
                        changeMenu = true;
                    }
                    else if (selection == 3) {  //quit text was clicked 
                        mainWin.close();
                    }
                    else if (selection == 4) {  //back button in level selection menu was clicked
                        changeMenu = false;
                    }
                    else if (selection == 5) {
                        levelSelected = 1;
                        rec1.setOutlineColor(sf::Color::Yellow);
                    }
                    else if (selection == 6) {
                        levelSelected = 2;
                        rec1.setOutlineColor(sf::Color::Yellow);
                    }
                    else if (selection == 7) {
                        levelSelected = 3;
                        rec1.setOutlineColor(sf::Color::Yellow);
                    }
                    else if (selection == 8) {
                        levelSelected = 4;
                        rec1.setOutlineColor(sf::Color::Yellow);
                    }
                }
            }
            
            mainWin.clear();
            if (!changeMenu) {
                showMainMenu();
            }
            else  {
                showLevelMenu();
            }

            mainWin.display();
        }

    }

private:

    //handles state changes for main menu
    void menuOptionHandler(sf::FloatRect &r) {
        //animation for when user hovers over text with mouse
        if (r.intersects(startText.getGlobalBounds())) {
            startText.setFillColor(sf::Color::Yellow);
            startText.setScale(sf::Vector2f(1.5, 1.5));
            startText.setPosition(1050.f, 230.f);
            selection = 1;
        }
        else {
            startText.setFillColor(sf::Color::White);
            startText.setScale(sf::Vector2f(1.f, 1.f));
            startText.setPosition(1100.f, 250.f);

        }

        //animation for level text
        if (r.intersects(levelMenu.getGlobalBounds())) {
            levelMenu.setFillColor(sf::Color::Yellow);
            levelMenu.setScale(sf::Vector2f(1.5, 1.5));
            levelMenu.setPosition(910.f, 330.f);
            selection = 2;
        }
        else {
            levelMenu.setFillColor(sf::Color::White);
            levelMenu.setScale(sf::Vector2f(1.f, 1.f));
            levelMenu.setPosition(990.f, 350.f);
        }

        //animation for quit text
        if (r.intersects(quit.getGlobalBounds())) {
            quit.setFillColor(sf::Color::Yellow);
            quit.setScale(sf::Vector2f(1.5, 1.5));
            quit.setPosition(1105.f, 420.f);
            selection = 3;
        }
        else {
            quit.setFillColor(sf::Color::White);
            quit.setScale(sf::Vector2f(1.f, 1.f));
            quit.setPosition(1125.f, 450.f);
        }
    }

    //hangles state changes for level selection menu
    void levelMenuHandler(sf::FloatRect &r) {

        if (r.intersects(backArrow.getGlobalBounds())) {
            backArrow.setScale(1.5, 1.5);
            selection = 4;
        }
        else {
            backArrow.setScale(1.f, 1.f);
        }

        if (r.intersects(sprImg_1.getGlobalBounds())) {
            rec1.setOutlineColor(sf::Color::Green);
            selection = 5;
        }
        else {
            if (levelSelected != 1) {
                rec1.setOutlineColor(sf::Color::White);
            }
            else { rec1.setOutlineColor(sf::Color::Yellow); }
        }

        if (r.intersects(sprImg_2.getGlobalBounds())) {
            rec2.setOutlineColor(sf::Color::Green);
            selection = 6;
        }
        else {
            if (levelSelected != 2) {
                rec2.setOutlineColor(sf::Color::White);
            }
            else { rec2.setOutlineColor(sf::Color::Yellow); }
        }
        
        if (r.intersects(sprImg_3.getGlobalBounds())) {
            rec3.setOutlineColor(sf::Color::Green);
            selection = 7;
        }
        else {
            if (levelSelected != 3) {
                rec3.setOutlineColor(sf::Color::White);
            }
            else { rec3.setOutlineColor(sf::Color::Yellow); }
        }

        if (r.intersects(sprImg_4.getGlobalBounds())) {
            rec4.setOutlineColor(sf::Color::Green);
            selection = 8;
        }
        else {
            if (levelSelected != 4) {
                rec4.setOutlineColor(sf::Color::White);
            }
            else { rec4.setOutlineColor(sf::Color::Yellow); }
        }
    }


	// Draws main menu
	void showMainMenu() {
        mainWin.draw(mainBg);
        mainWin.draw(title);
        mainWin.draw(startText);
        mainWin.draw(levelMenu);
        mainWin.draw(quit);
	}

    //draws level selection menu
    void showLevelMenu() {   
        mainWin.draw(secBg);
        mainWin.draw(backArrow);
        mainWin.draw(secTitle);
        mainWin.draw(rec1);
        mainWin.draw(sprImg_1);
        mainWin.draw(rec2);
        mainWin.draw(sprImg_2);
        mainWin.draw(rec3);
        mainWin.draw(sprImg_3);
        mainWin.draw(rec4);
        mainWin.draw(sprImg_4);
    }

};
