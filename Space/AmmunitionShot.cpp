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
			Projectile* projectileOOB = *it;
			this->removeShot(projectileOOB);
			--it;
			delete projectileOOB;
		}
		else
		{
			pWindow->draw((*it)->getProjectile());
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
void AmmunitionShot::addShot( Projectile* pShot)
{
	shotsFired.push_back(pShot);
}
void AmmunitionShot::removeShot(Projectile* pShot)
{
	shotsFired.remove(pShot);
}


