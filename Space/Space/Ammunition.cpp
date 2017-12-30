#include "Ammunition.h"

/*Replenishes fully ammountLeft*/
void Ammunition::reload()
{
	ammountLeft = maxAmmo;
}
/*Returns the damage field of an ammo type*/
int Ammunition::getDamage()
{
	return aDamage;
}int32_t Ammunition::getDelay()
{
	return aDelay;
}
RegBullet::RegBullet()
{
	aDelay = 100;
	aName = "regShot";
	aDamage = 5;
	maxAmmo = 1;
	speed = 0.5f;
	ammountLeft = 1;
}
RegBullet::~RegBullet() {}
/*Uses one ammo unit and returns a projectile*/
Projectile* RegBullet::consume(sf::Vector2f pCurPos)
{
	return new Projectile((allTextures->getTexture()), 0, aDamage, speed, pCurPos);	
}
/*Specifies the shooting speed of the Ammunition object*/
int32_t RegBullet::getDelay()
{
	return aDelay;
}



	
	
	

