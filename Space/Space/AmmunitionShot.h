#pragma once
#include <stdio.h>
#include <memory>
#include "Projectile.h"
#include "spaceShip.h"
class AmmunitionShot
{
private:
	AmmunitionShot();
	std::list<Projectile*> shotsFired;


public:
	static AmmunitionShot& getInstance();
	AmmunitionShot& operator=(const AmmunitionShot&) = delete;
	void update(sf::RenderWindow* pWindow);
	void AmmunitionShot::calcCollisions(spaceShip* aPlayer);
	void addShot(Projectile* pShot);
	void removeShot(Projectile* pShot);
	std::list<Projectile*>::iterator iterator();
	std::list<Projectile*>::iterator end();
	
};
