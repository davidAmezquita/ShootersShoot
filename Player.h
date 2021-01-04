#pragma once
#include "Projectiles.h"
#include "Entity.h"
#include "Wall.h"
#include <math.h>
#include "Enemy.h"

class Player : public Entity{

private:
	std::vector<sf::CircleShape> aim;
	float aimOriginX, aimOriginY;
	float aimX, aimY;
	float radians;
	int radius;
	std::vector<Bullet*> bullets;
	sf::Texture bulletTexture;
	std::vector<sf::Sprite> bulletDisplay; //displays amunition on screen
	int numBullets;
	int numShots;
	

public:

	Player(const std::string& filename, float x, float y, float h, float w) : 
		 Entity(filename, x, y, h, w) {
		
		this->radius = 200;
		this->aimOriginX = x + 64; 
		this->aimOriginY = y + (64 / 2);
		this->aimX = aimOriginX + radius;
		this->aimY = aimOriginY;
		this->radians = 0;
		

		//set circle objects in a liner manner to represent trajectory in which the bullet will travel
		for (int i = 0; i < 8; i++) {
			aim.push_back(sf::CircleShape(2.f));
			aim.at(i).setPosition(sf::Vector2f(aimOriginX + (20 * (i+ 1)), aimOriginY));
			aim.at(i).setFillColor(sf::Color(50, 50, 50));
		}
		
		this->numBullets = 5;
		this->numShots = 0;

		if (!bulletTexture.loadFromFile("assets/bullet.png")) {
			std::cout << "Failed to load bullet texture\n";
			exit(0);
		}

		//create bullets
		for (int i = 0; i < numBullets; i++) {
			bullets.push_back(new Bullet(0.0,0.0, 5.f));
			bulletDisplay.push_back(sf::Sprite(bulletTexture));
			bulletDisplay.at(i).setPosition(i * 10, W_HEIGHT - 16.f);
		}

	}

	~Player() {
		bullets.clear();
	}


	void checkHits(std::vector<Zombie*>& zombies, std::vector<Wall*>& walls) {

		for (int i = 0; i < numShots; i++) {

			Bullet* b = bullets.at(i);
			
			if (b->getNumCollisions() > 6) {
				continue;
			}
			
			//detect collisions with the window boarder
			b->wallCollison();
			
			//detect collisions with enemeis
			for (Zombie* e : zombies) {
				if (e->collision(b->getPosition())) {
					b->incCollision();
					e->decHealth();
					e->startRefreshPeriod();
				}
			}
			
			//check collisions with metal walls
			for (Wall* w : walls) {
				
				if (w->collision(b->getPosition(), b->getOffset())) {
					b->divertDirection(b->getDirection(), w->getSideHit());	
				}
			}
			
		}

	}

	//updates the players actions on screen
	void update(sf::RenderTarget &w) {

		Draw(w); //draws player
		
		//draws trajectory
		for(const auto &c : aim)
		{
			w.draw(c);
		}

		//draws bullets
		for (int i = 0; i < numShots; i++) {
			bullets.at(i)->Update(w);
		}

		//draw amount of amunition left
		for (int i = 0; i < numBullets - numShots; i++) {
			w.draw(bulletDisplay.at(i));
		}

	}

	//moves the players aim
	void moveTrajectory(char d) {

		int len = aim.size();
		//moves the aim upward and stops at an 80 degree angle from the starting positon
		if (d == 'w' && radians >= -1.44) { 
			radians -= 0.04;
			for (int i = 0; i < len; i++) {
				aimX = aimOriginX + cos(radians) * (20 * (i + 1));
				aimY = aimOriginY + sin(radians) * (20 * ( i + 1));
				aim.at(i).setPosition(aimX, aimY);	
			}	
		}

		//moves aim downward and stops at a -10 degree angle from the starting position
		if (d == 's' && radians <= 0.08) {
			radians += 0.04;
			for (int i = 0; i < len; i++) {
				aimX = aimOriginX + cos(radians) * (20 * (i + 1));
				aimY = aimOriginY + sin(radians) * (20 * (i + 1));
				aim.at(i).setPosition(aimX, aimY);
			}
		}
	}


	void shoot() {
		//player ran out of bullets to shoot when this condition is true
		if (this->numShots == bullets.size()) {
			return;
		}
		


		//grabs the difference in hight between y values of two circle
		float y1 = aim.front().getPosition().y;
		float y2 = aim.back().getPosition().y;
		float changeInY = y1 - y2;


		//x cord for the bullet to start from
		float x1 = aim.front().getPosition().x;
		float x2 = aim.back().getPosition().x;
		float changeInX = x1 - x2;
		
		//if the difference is positive, the bullet should travel in a up right direction
		if (changeInY > 0.0) {
			bullets.at(numShots)->setTrajectory(x2, y2, abs(changeInX), abs(changeInY), UpRight);
		}
		else if (changeInY < 0.0){
			//if the difference is negative, the bullet should travel in a down right direction
			bullets.at(numShots)->setTrajectory(x2, y2, abs(changeInX), abs(changeInY), DownRight);
		}
		else {
			//this means the difference is 0, therfore the bullet should travel in a stright direction
			bullets.at(numShots)->setTrajectory(x2, y2, abs(changeInX), abs(changeInY), Right);
		}

		this->numShots++;  //keeps track of what bullet has been shot and how many have been shot

	}
};

