#include "AmmunitionShot.h"

AmmunitionShot::AmmunitionShot() {};
//AmmunitionShot::AmmunitionShot(AmmunitionShot&& pAS)
//{
//
//}
/*Returns the instance of the AmmunitionShot class*/
AmmunitionShot &AmmunitionShot::getInstance()
{
	static AmmunitionShot INSTANCE;
	return INSTANCE;
}

/*Iterates through the Projectiles, updates them, and removes those out of bounds*/
void AmmunitionShot::update(sf::RenderWindow* pWindow)
{
	std::vector<Projectile*> copy = shotsFired;
	for (std::vector<Projectile*>::iterator cur = copy.begin(); cur != copy.end(); ++cur)
	{
		(*cur)->update();
		sf::Vector2f tmp = (*cur)->getPosition();
		sf::Vector2u size = pWindow->getSize();
		if (tmp.x > size.x || tmp.y > size.y)
		{
			removeShot(*cur);
		}
		else
		{
			pWindow->draw((*cur)->getProjectile());
		}
	}
}
/*Determines if a collision occured between aPlayer and some Projectile;
may need to be modified/optimized for checking collisions on multiple spaceShip instances*/
void AmmunitionShot::calcCollisions(std::shared_ptr<SpaceObjects> aPlayer)
{
	sf::Vector2f sp = aPlayer->getPosition();
	std::vector<Projectile*> copy = shotsFired;

	//check for error at end of list
	for (std::vector<Projectile*>::iterator cur = copy.begin(); cur != copy.end(); ++cur)
	{
		sf::Vector2f pp = (*cur)->getPosition();
		/*float distance = sqrtf(pow((pp.x - sp.x), 2.0) + pow((pp.y - sp.y), 2.0));
		if (distance < 5.0)*/
		if ( aPlayer->getShip().getGlobalBounds().intersects((*cur)->getProjectile().getGlobalBounds())) //TO clean
		{
			int remainder = aPlayer->getHit((*cur)->getDamage());
			removeShot(*cur);
			if (remainder <= 0)
			{
				throw - 1;
			}
			
		}
	}
}

void AmmunitionShot::addShot(Projectile* pShot)
{
	shotsFired.push_back(pShot);
}
void AmmunitionShot::removeShot(Projectile* pShot)
{
	for (std::vector<Projectile*>::iterator p = shotsFired.begin(); p != shotsFired.end(); ++p)
	{
		if (*p = pShot)
		{
			shotsFired.erase(p);
			break;
		}
	}	
}


