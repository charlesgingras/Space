#pragma once
#include<stdio.h>
#include "Ammunition.h"
#include "TextureRefs.h"

#include<TGUI/TGUI.hpp>


/*The spaceShip class is used to represent space ships (surprise...);
it is used both by AI and players*/
class SpaceShip
{
private:
	TextureRefs* allTextures = &(TextureRefs::getTextRefs());
	std::vector<Ammunition*> aAmmo;
	sf::Sprite aShip;
	Ammunition* ammoPtr;
	double aSpeed = 0.3f;
	const int MAX_HEALTH = 5;
	int aHealth = 3;

public:
	void repairShip();
	void moveUp(float p, int pHeight);
	void moveRight(float p, int pWidth);
	void changeLoadOut(int pIndex);
	void getHit(int pDamage);
	Projectile* shoot();
	sf::Vector2f getPosition();
	sf::Sprite getShip();
	SpaceShip(float pPosition);
	~SpaceShip() { delete ammoPtr; };
	Ammunition* getAmmoPtr();
};
