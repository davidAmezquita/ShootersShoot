#pragma once
#include "dependency.h"

enum Direction { UpLeft, DownLeft, UpRight, 
				DownRight, Up, Down, Left, Right};

class Bullet {
private:
	float xPos, yPos;
	float xChange, yChange;
	Direction direction;
	float velocity;
	sf::CircleShape bullet;
	int numCollisons;
	float radius;
	sf::Vector2f offset;

public:

	Bullet(float x, float y, float r)
		: xPos(x), yPos(y), radius(r)
	{
		this->bullet.setRadius(radius);
		this->bullet.setFillColor(sf::Color::White);
		this->velocity = 10.f;
		this->numCollisons = 0;
		this->direction = Right;
		this->offset.x = 0.f;
		this->offset.y = 0.f;
		this->xChange = 0.f;
		this->yChange = 0.f;

	}


	sf::Vector2f getPosition() {
		return sf::Vector2f(xPos, yPos);
	}

	Direction getDirection() {
		return this->direction;
	}

	int getNumCollisions() {
		return this->numCollisons;
	}

	sf::Vector2f getOffset() {
		return offset;
	}

	void Update(sf::RenderTarget &w) {
		if (numCollisons > 6) { return;  }

		move();
		w.draw(bullet);
	}

	//moves bullet across screen
	void move() {

		switch (this->direction)
		{
		case Up:
			this->yPos -= offset.y;
			break;
		case Down:
			this->yPos += offset.y;
			break;
		case Left:
			this->xPos -= offset.x;
			break;
		case Right:
			this->xPos += offset.x;
			break;
		case UpLeft:
			this->xPos -= offset.x;
			this->yPos -= offset.y;
			break;
		case DownLeft:
			this->xPos -= offset.x;
			this->yPos += offset.y;
			break;
		case UpRight:
			this->xPos += offset.x;
			this->yPos -= offset.y;
			break;
		case DownRight:
			this->xPos += offset.x;
			this->yPos += offset.y;
			break;
		default:
			break;
		}

		bullet.setPosition(sf::Vector2f(xPos, yPos));
	}

	void setDirection(Direction d) {
		this->direction = d;
	}

	void setTrajectory(float x, float y, float changeInX, float changeInY, Direction d) {
		this->direction = d;
		this->xChange = changeInX;
		this->yChange = changeInY;
		this->xPos = x;
		this->yPos = y;
		this->offset.x = xChange / velocity;
		this->offset.y = yChange / velocity;
	}
	
	void divertDirection(Direction d, int flag) {
		
		//flag = 0 is a veritcle collision
		switch (d)
		{
		case UpLeft:
			if (flag) { this->direction = DownLeft; }
			else { this->direction = UpRight; }
			break;
		case DownLeft:
			if (flag) { this->direction = UpLeft; }
			else { this->direction = DownRight; }
			break;
		case UpRight:
			if (flag) { this->direction = DownRight; }
			else { this->direction = UpLeft; }
			break;
		case DownRight:
			if (flag) { this->direction = UpRight; }
			else { this->direction = DownLeft; }
			break;
		case Up:
			this->direction = Down;
			break;
		case Down:
			this->direction = Up;
			break;
		case Left:
			this->direction = Right;
			break;
		case Right:
			this->direction = Left;
			break;
		default:
			break;
		}
	}

	//checks for collison, returns true if bullet collided with something
	void wallCollison() {

		//checks collison with window border
		if (xPos + radius + velocity > W_WIDTH) {
			//collision with right verticle window wall
			divertDirection(this->direction, 0);
			
			this->numCollisons++;
		}
		else if (xPos + radius + velocity < 0) {
			//collision with left verticle window wall
			divertDirection(this->direction, 0);

			this->numCollisons++;
		}
		else if (yPos + radius > W_HEIGHT - FLOOR_H) {
			//collision with floor
			divertDirection(this->direction, 1);

			this->numCollisons++;
		}
		else if( yPos + radius < 0){
			//collision with ceiling
			divertDirection(this->direction, 1);
			
			this->numCollisons++;
		}
		else {
			return;
		}
	}
	
	void incCollision() {
		this->numCollisons++;
	}

	


};
