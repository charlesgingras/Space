#include "spaceShip.h"

	spaceShip::spaceShip(float pPosition)
	{
		aShip.setTextureRect(sf::IntRect(7, 870, 725, 1597));
		aShip.setTexture(*(allTextures->getTexture()), false);
		aShip.setScale(0.1, 0.1);
		aShip.setPosition(30.0, pPosition);
		aAmmo = std::vector<Ammunition>();
		RegBullet b;
		aAmmo.push_back(b);
		ammoPtr = &(aAmmo.front());
	}
	void spaceShip::repairShip()
	{
		aHealth++;
	}
	void spaceShip::moveUp(float p, int pHeight)
	{
		if (aShip.getPosition().y < 5 && p < 0) {}
		else if (aShip.getPosition().y > pHeight - 5 && p > 0) {}
		else aShip.move(0.0, p*aSpeed);
	}
	void spaceShip::moveRight(float p, int pWidth)
	{
		if (aShip.getPosition().x < 5 && p < 0) {}
		else if (aShip.getPosition().x > pWidth - 5 && p > 0) {}
		else aShip.move(p*aSpeed, 0.0);
	}
	void spaceShip::changeLoadOut(int pIndex)
	{
		ammoPtr = &aAmmo[pIndex];
	}
	void spaceShip::getHit(int pDamage)
	{
		aHealth -= pDamage;
		if (aHealth < 0)
		{
			//TODO
		}
	}
	sf::Vector2f spaceShip::getPosition()
	{
		return aShip.getPosition();
	}

	sf::Sprite spaceShip::getShip()
	{
		return aShip;
	}

	Projectile* spaceShip::shoot()
	{
		sf::Vector2f shipPosition;
		shipPosition = this->getPosition();
		shipPosition.x += 70;
		shipPosition.y += 30;
		return ammoPtr->consume(shipPosition);
		 
	}


