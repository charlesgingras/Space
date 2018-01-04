#pragma once
#include "SpaceShip.h"
#include "AmmunitionShot.h"
class SpaceObjectObserver
{
private:
	std::vector<std::shared_ptr<SpaceObjects> > aSpaceObjects;
	SpaceObjectObserver();

public:
	void displayAll(AmmunitionShot* pProj, sf::RenderWindow* pWin); //updates and displays all SpaceObjects, except the player controlled one
	~SpaceObjectObserver() {};
	static SpaceObjectObserver& getSpaceObjectObserver();
	void SpaceObjectObserver::addObjects(std::shared_ptr<SpaceObjects> pSpaceObject);
	void removeObject(std::shared_ptr<SpaceObjects> pSpaceObject);/*
	std::vector<std::shared_ptr<SpaceObjects> >::iterator SpaceObjectObserver::iterator();
	std::vector<std::shared_ptr<SpaceObjects> >::iterator SpaceObjectObserver::end();*/
};
