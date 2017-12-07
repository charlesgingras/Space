#include "AmmunitionShot.h"

AmmunitionShot::AmmunitionShot() {};



AmmunitionShot &AmmunitionShot::getInstance()
{
	static AmmunitionShot INSTANCE;
	return INSTANCE;
}

void AmmunitionShot::update(sf::RenderWindow* pWindow)
{
	for (std::list<Projectile*>::iterator it = shotsFired.begin(); it != shotsFired.end(); ++it)
	{
		(*it)->update();
		sf::Vector2f tmp = (*it)->getPosition();
		sf::Vector2u size = pWindow->getSize();
		if (tmp.x > size.x || tmp.y > size.y)
		{
			if (it == shotsFired.end())
			{
				shotsFired.erase(it);
			}
			else shotsFired.erase(it++);
		}
		else
		{
			pWindow->draw((*it)->getProjectile());
		}
	}
}

void AmmunitionShot::calcCollisions(spaceShip* aPlayer)
{
	sf::Vector2f sp = aPlayer->getPosition();
	//check for error at end of list
	for (std::list<Projectile*>::iterator it = shotsFired.begin(); it != shotsFired.end(); it++)
	{
		sf::Vector2f pp = (*it)->getPosition();
		float distance = sqrtf(pow((pp.x - sp.x), 2.0) + pow((pp.y - sp.y), 2.0));
		if (distance < 5.0)
		{
			aPlayer->getHit((*it)->getDamage());
			if (it == shotsFired.end())
			{
				shotsFired.erase(it);
			}
			else shotsFired.erase(it++);

		}
	}
}
std::list<Projectile*>::iterator AmmunitionShot::iterator()
{
	return shotsFired.begin();
}
std::list<Projectile*>::iterator AmmunitionShot::end()
{
	return shotsFired.end();
}
void AmmunitionShot::addShot(Projectile* pShot)
{
	shotsFired.push_back(pShot);
}
void AmmunitionShot::removeShot(Projectile* pShot)
{
	shotsFired.remove(pShot);
}


