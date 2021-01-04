#pragma once
#include "Entity.h"

class Zombie : public Entity {

private:
	std::string file;
	sf::Texture textures[2];
	int orientation;
	bool hit;
	int health;
	int damagePeriod;
	bool refreshPeriod;

public:

	Zombie(sf::Vector2f p, float h, float w, int ori)
		: Entity(p, h, w)
	{
		
		if (orientation == 0) {
			if (!textures[0].loadFromFile("assets/zombie_1.png")) {
				std::cout << "Failed to load zombie_1.png\n";
				exit(0);
			}
			if (!textures[1].loadFromFile("assets/zombie_1_damaged.png")) {
				std::cout << "Failed to load zombie_1.png\n";
				exit(0);
			}

		}
		else {
			if (!textures[0].loadFromFile("assets/zombie_2.png")) {
				std::cout << "Failed to load zombie_2.png\n";
				exit(0);
			}
			if (!textures[1].loadFromFile("assets/zombie_2_damaged.png")) {
				std::cout << "Failed to load zombie_2_damaged.png\n";
				exit(0);
			}
		}
		setTexture(textures[0]);

		this->orientation = ori;
		this->damagePeriod = 0;
		this->refreshPeriod = false;
		this->hit = false;
		this->health = 3;
	}

	void Draw(sf::RenderTarget& w) {
		if (hit) {
			setTexture(textures[1]);
			hit = false;
		}
		else {
			setTexture(textures[0]);
		}

		if (health > 0) {
			w.draw(getSprite());
		}
		
	}

	void startRefreshPeriod() {
		this->refreshPeriod = true;
	}

	bool collision(const sf::Vector2f& position) {

		float xPos = getX();
		float yPos = getY();

		//refresh period in which the entity will not take damage
		if (refreshPeriod && damagePeriod != 4) {
			this->damagePeriod++;
			return false;
		}
		else {
			this->damagePeriod = 0;
			
		}

		//checks if there was collision with any of the bounds of this entity
		if (position.x > xPos && position.x < xPos + 64 &&
			(position.y > yPos && position.y <= yPos + 64) && damagePeriod == 0) {
			return true;
		}
		else if (position.y > yPos && position.y < yPos + 64 &&
			(position.x > xPos && position.x <= xPos + 64) && damagePeriod == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void decHealth() {
		this->health--;
		this->hit = true;
	}
};
