#include "Ammunition.h"

Ammunition::Ammunition() {};
void Ammunition::reload()
{
	ammountLeft = maxAmmo;
}
//Ammunition::Ammunition(const Ammunition& pThis)
//{
//	aTexture = pThis.aTexture;
//	aAmmunition.setTexture(*aTexture);
//	aAmmunition.setScale(0.05, 0.05);
//	aDamage = pThis.aDamage;
//	maxAmmo = pThis.maxAmmo;
//	speed = pThis.speed;
//	ammountLeft = 1;
//}
Projectile* Ammunition::consume(sf::Vector2f pCurPos)
{
	ammountLeft--;
	return new Projectile((allTextures->getTexture()), 0, aDamage, speed, pCurPos);

}

//void Ammunition::update()
//{
//	aAmmunition.move(speed, 0);
//}
//sf::Vector2f Ammunition::getPosition()
//{
//	return aAmmunition.getPosition();
//}
//void Ammunition::update(sf::Vector2f pPos)
//{
//	aAmmunition.setPosition(pPos);
//}
int Ammunition::getDamage()
{
	return aDamage;
}
int32_t Ammunition::getDelay()
{
	return aDelay;
}
RegBullet::RegBullet()
{
	aDelay = 500;
	aName = "regShot";
	aDamage = 5;
	maxAmmo = 1;
	speed = 0.5f;
	ammountLeft = 1;
}
RegBullet::RegBullet(const RegBullet& pThis)
{
	aDelay = 500;
	aName = "regShot";
	aDamage = 5;
	maxAmmo = 1;
	speed = 0.5f;
	ammountLeft = 1;
}
Projectile* RegBullet::consume(sf::Vector2f pCurPos)
{
	return new Projectile((allTextures->getTexture()), 0, aDamage, speed, pCurPos);	
}
int32_t RegBullet::getDelay()
{
	return aDelay;
}
//sf::Vector2f RegBullet::getPosition()
//{
//	return aAmmunition.getPosition();
//}

//void RegBullet::update()
//{
//	aAmmunition.move(speed, 0);
//}
//void RegBullet::update(sf::Vector2f pPos)
//{
//	aAmmunition.setPosition(pPos);
//}


	
	
	

