#pragma once
#include <stdio.h>
#include "TextureRefs.h"
#include "Projectile.h"
#include <TGUI/TGUI.hpp>
/*The ammunition class is used to represent stored Projectiles,
shooting causes ammunition to be decremented and creates a Projectile with an actual visual representation*/
class Ammunition
{
protected:
	TextureRefs* allTextures = &(TextureRefs::getTextRefs());
	int ammountLeft;
	int maxAmmo;
	int32_t aDelay;
	int aDamage;
	float speed;
	std::string aName;
	
public:
	Ammunition() {};
	Ammunition(Ammunition& pAmm) = delete;
	Ammunition(Ammunition&& pAmm) = delete;
	virtual ~Ammunition() {};
	virtual void reload();
	virtual Projectile* consume(sf::Vector2f pCurPos) =0;
	virtual int32_t getDelay() =0;
	virtual int getDamage();
};

class RegBullet : public Ammunition 
{
public:
	RegBullet();
	~RegBullet();
	Projectile* consume(sf::Vector2f pCurPos);
	int32_t getDelay();
};
