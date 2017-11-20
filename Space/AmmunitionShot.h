#pragma once
#include <stdio.h>
#include "Projectile.h"

class AmmunitionShot
{
private:
	AmmunitionShot();
	std::list<Projectile*> shotsFired;


public:
	static AmmunitionShot& getInstance();
	void update(sf::RenderWindow* pWindow);
	void addShot(Projectile* pShot);
	void removeShot(Projectile* pShot);
	std::list<Projectile*>::iterator iterator();
	std::list<Projectile*>::iterator end();
	
};
