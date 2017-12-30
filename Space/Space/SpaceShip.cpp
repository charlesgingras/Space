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
	}
	/*Increments remaining health by one unit*/
	void SpaceShip::repairShip()
	{
		aHealth++;
	}
	/*Moves the spaceShip object vertically*/
	void SpaceShip::moveUp(float p, int pHeight)
	{
		if (aShip.getPosition().y < 5 && p < 0) {}
		else if (aShip.getPosition().y > pHeight - 5 && p > 0) {}
		else aShip.move(0.0, p*aSpeed);
	}
	/*Moves the spaceShip object horizontally*/
	void SpaceShip::moveRight(float p, int pWidth)
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
	void SpaceShip::getHit(int pDamage)
	{
		aHealth -= pDamage;
		if (aHealth < 0)
		{
			//TODO
		}
	}
	/*Returns a Vector2f giving the position of the spaceShip object*/
	sf::Vector2f SpaceShip::getPosition()
	{
		return aShip.getPosition();
	}
	/*Returns the sprite of the spaceShip object*/
	sf::Sprite SpaceShip::getShip()
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


