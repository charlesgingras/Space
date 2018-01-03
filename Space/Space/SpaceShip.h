#pragma once
#include<stdio.h>
#include "Ammunition.h"
#include "TextureRefs.h"

#include<TGUI/TGUI.hpp>

class SpaceObjects
{
protected:
	TextureRefs* allTextures = &(TextureRefs::getTextRefs());
	sf::Sprite aShip;
	double aSpeed;
	const int MAX_HEALTH = 5;
	int aHealth;
public:
	void moveUp(float p, int pHeight);
	void moveRight(float p, int pWidth);
	void getHit(int pDamage);
	sf::Vector2f getPosition();
	sf::Sprite getShip();
	SpaceObjects() {};
	~SpaceObjects() {};
	
};
/*The spaceShip class is used to represent space ships (surprise...);
it is used both by AI and players*/
class SpaceShip: public SpaceObjects
{
private:
	std::vector<Ammunition*> aAmmo;
	Ammunition* ammoPtr;

public:
	void repairShip();
	void changeLoadOut(int pIndex);
	Projectile* shoot();
	SpaceShip(float pPosition);
	~SpaceShip() { delete ammoPtr; };
	Ammunition* getAmmoPtr();
};
class Asteroid : public SpaceObjects
{
private:
	int aDamage = 1;
public:
	Asteroid(float pX, float pY, float size);
	~Asteroid();
};
