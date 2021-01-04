#pragma once
#include "Entity.h"

class Wall : public Entity{

private:
	int sideHit;

public:
	Wall(const std::string& fileName, float x, float y, float h, float w) :
		Entity(fileName, x, y, h, w) {
		sideHit = 0;
	}

	Wall(const std::string& fileName, sf::Vector2f p, float h, float w) :
		Entity(fileName, p, h, w) {
		sideHit = 0;
	}

	int getSideHit() {
		return this->sideHit;
	}


	//returns true if a projectile collided with this wall
	//position represents the projectiles current position
	//offset represent the amount of pixles the projectile is moving in each direction
	bool collision(const sf::Vector2f position, const sf::Vector2f offset) {

		float wallHeight = getHeight();
		float wallWidth = getWidth();
		float xPos = getX();
		float yPos = getY();
		
		bool flag = false;

		
		if ((position.x + offset.x) >= xPos && position.x < xPos
			&& position.y > yPos && position.y <= yPos + wallHeight) {
			flag = true;	//left vertical side was hit
			this->sideHit = 0;
			
		}
		else if ((position.x - offset.x) <= (xPos + wallWidth) && position.x > (xPos + wallWidth)
				&& position.y > yPos && position.y <= yPos + wallHeight) {
			flag = true;	//right vertical side was hit
			this->sideHit = 0;
			
		}
		else if ((position.y + offset.y) >= yPos && position.y < yPos
			&& position.x > xPos && position.x < xPos + wallWidth) {
			flag = true;	//top side of wall was hit
			this->sideHit = 1;
		
		}
		else if ((position.y - offset.y) <= (yPos + wallHeight) && position.y > (yPos + wallHeight)
				&& position.x > xPos && position.x < (xPos + wallWidth)) {
			flag = true;	//under side of wall was hit
			this->sideHit = 1;
			
		}
		
		
		return flag;

	}
};