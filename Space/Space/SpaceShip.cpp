#include "SpaceShip.h"

	/*param pPosition: starting vertical position of spaceShip object*/
	SpaceShip::SpaceShip(float pPosition)
	{
		aShip.setTextureRect(sf::IntRect(7, 870, 725, 1597));
		aShip.setTexture(*(allTextures->getTexture()), false);
		aShip.setScale(0.1, 0.1);
		aShip.setPosition(30.0, pPosition);
		aAmmo = std::vector<Ammunition*>();
		aAmmo.push_back(new RegBullet);
		ammoPtr = (aAmmo.front());
		aHealth = 3;
		aSpeed = 0.3f;
	}
	/*Increments remaining health by one unit*/
	void SpaceShip::repairShip()
	{
		aHealth++;
	}
	/*Moves the spaceShip object vertically*/
	void SpaceObjects::moveUp(float p, int pHeight)
	{
		if (aShip.getPosition().y < 5 && p < 0) {}
		else if (aShip.getPosition().y > pHeight - 5 && p > 0) {}
		else aShip.move(0.0, p*aSpeed);
	}
	/*Moves the spaceShip object horizontally*/
	void SpaceObjects::moveRight(float p, int pWidth)
	{
		if (aShip.getPosition().x < 5 && p < 0) {}
		else if (aShip.getPosition().x > pWidth - 5 && p > 0) {}
		else aShip.move(p*aSpeed, 0.0);
	}
	/*Cycles through the Ammunition storage of the spaceShip object*/
	void SpaceShip::changeLoadOut(int pIndex)
	{
		ammoPtr = aAmmo[pIndex];
	}
	/*Take damage: called when object is hit by a Projectile*/
	void SpaceObjects::getHit(int pDamage)
	{
		aHealth -= pDamage;
		if (aHealth < 0)
		{
			//TODO
		}
	}
	/*Returns a Vector2f giving the position of the spaceShip object*/
	sf::Vector2f SpaceObjects::getPosition()
	{
		return aShip.getPosition();
	}
	/*Returns the sprite of the spaceShip object*/
	sf::Sprite SpaceObjects::getShip()
	{
		return aShip;
	}
	/*Shoots out a Projectile, using selected Ammunition*/
	Projectile* SpaceShip::shoot()
	{
		sf::Vector2f shipPosition;
		shipPosition = this->getPosition();
		shipPosition.x += 70;
		shipPosition.y += 30;
		return ammoPtr->consume(shipPosition);
		 
	}
	Ammunition* SpaceShip::getAmmoPtr()
	{
		return ammoPtr;
	}
	/*@param: pX, pY represent the X and Y positions of the asteroid
			  size is a ratio of 0 to 1 to determine the size of the sprite*/
	Asteroid::Asteroid(float pX, float pY, float size)
	{
		aSpeed = 0.1f; 
		aHealth = 1;
		aShip.setTextureRect(sf::IntRect(1149, 0, 1565, 390));
		aShip.setTexture(*(allTextures->getTexture()), false);
		aShip.setScale(size, size);
		aShip.setPosition(pX, pY);
	}


