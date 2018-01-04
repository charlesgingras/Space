#pragma once
#include <stdio.h>
#include <vector>
#include "Projectile.h"
#include "spaceShip.h"
/*AmmunitionShot takes care of keeping track of all Projectile objects;
the Singleton design pattern is used, hence a single instance of the class may be initialzed*/
class AmmunitionShot
{
private:
	AmmunitionShot();
	
	std::vector<Projectile*> shotsFired;
	//AmmunitionShot(AmmunitionShot&& pAS);

public:
	~AmmunitionShot() {
		for (Projectile* p : shotsFired) { delete p; }
	};
	static AmmunitionShot& getInstance();
	AmmunitionShot& operator=(const AmmunitionShot&) = delete;
	void update(sf::RenderWindow* pWindow);
	void AmmunitionShot::calcCollisions(std::shared_ptr<SpaceObjects> aPlayer);
	void addShot(Projectile* pShot);
	void removeShot(Projectile* pShot);
	
};
