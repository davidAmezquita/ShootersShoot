#pragma once
#include "dependency.h"

class Entity {

private:
	sf::Texture eTexture;
	sf::Sprite eSprite;
	const float xPos, yPos;
	const float height, width;


public:

	Entity(sf::Vector2f p, float h, float w) :
		xPos(p.x), yPos(p.y), height(h), width(w) {};

	
	Entity(const std::string& fileName, float x, float y, float h, float w) :
		xPos(x), yPos(y), height(h), width(w)
	{
		//load texture
		if (!eTexture.loadFromFile(fileName)) {
			std::cout << "Texture failed to load." << std::endl;
			exit(0);
		}

		eSprite.setTexture(eTexture);
		eSprite.setPosition(sf::Vector2f(xPos, yPos));
		
	}

	Entity(const std::string& fileName, sf::Vector2f p, float h, float w) :
		xPos(p.x), yPos(p.y), height(h), width(w)
	{
		//load texture
		if (!eTexture.loadFromFile(fileName)) {
			std::cout << "Texture failed to load." << std::endl;
			exit(0);
		}

		eSprite.setTexture(eTexture);
		eSprite.setPosition(sf::Vector2f(xPos, yPos));
	}

	float getX() {
		return this->xPos;
	}

	float getY() {
		return this->yPos;
	}

	float getWidth() {
		return this->width;
	}

	float getHeight() {
		return this->height;
	}

	sf::Sprite getSprite() {
		return this->eSprite;
	}

	void setTexture(const sf::Texture &t) {
		this->eSprite.setTexture(t);
		this->eSprite.setPosition(xPos, yPos);
	}



	void Draw(sf::RenderTarget& w) {
		w.draw(eSprite);
	}

	
};
