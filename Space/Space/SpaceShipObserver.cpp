#include "SpaceObjectObserver.h"
SpaceObjectObserver::SpaceObjectObserver() {};
/*Returns the Observer instance*/
SpaceObjectObserver& SpaceObjectObserver::getSpaceObjectObserver()
{
	static SpaceObjectObserver INSTANCE;
	return INSTANCE;
}
/*Updates the position of Objects, before verifying if they hit a projectile; then draw them to the window*/
void SpaceObjectObserver::displayAll(AmmunitionShot* pProj, sf::RenderWindow* pWin)
{
	std::vector<std::shared_ptr<SpaceObjects> > copy = aSpaceObjects;
	sf::Vector2u tmp = pWin->getSize();
	for (std::vector<std::shared_ptr<SpaceObjects> >::iterator it = copy.begin(); it != copy.end(); ++it)
	{
		
		//(*it)->moveUp(1, tmp.y);
		(*it)->moveRight(-1, tmp.x);
		sf::Vector2f pos = (*it)->getPosition();
		if (pos.x - 30.0 > tmp.x || pos.y - 20.0 > tmp.y)
		{
			removeObject(*it);
		}
		else{
			try {
				pProj->calcCollisions(*it);
				pWin->draw((*it)->getShip());
				}
			catch (int e) // object destroyed
			{
				removeObject(*it);
			}
		}
		
	}

}
void SpaceObjectObserver::addObjects(std::shared_ptr<SpaceObjects> pSpaceObject)
{
	aSpaceObjects.push_back(pSpaceObject);
}
void SpaceObjectObserver::removeObject(std::shared_ptr<SpaceObjects> pSpaceObject)
{
	for (std::vector<std::shared_ptr<SpaceObjects> >::iterator p = aSpaceObjects.begin(); p != aSpaceObjects.end(); ++p)
	{
		if (*p = pSpaceObject)
		{
			aSpaceObjects.erase(p);
			break;
		}
	}
}
//std::vector<std::shared_ptr<SpaceObjects> >::iterator SpaceObjectObserver::iterator()
//{
//	return aSpaceObjects.begin();
//}
//std::vector<std::shared_ptr<SpaceObjects> >::iterator SpaceObjectObserver::end()
//{
//	return aSpaceObjects.end();
//}