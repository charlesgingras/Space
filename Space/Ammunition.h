#pragma once
#include <stdio.h>
#include "TextureRefs.h"
#include "Projectile.h"
#include <TGUI/TGUI.hpp>

class Ammunition
{
protected:
	TextureRefs* allTextures = &(TextureRefs::getTextRefs());
	int ammountLeft = 0;
	int maxAmmo = 0;
	int aDamage;
	float speed;
	std::string aName;
	
	

public:
	//Ammunition(const Ammunition&);
	Ammunition();
	void reload();
	virtual Projectile* consume(sf::Vector2f pCurPos);
	//virtual void update();
	//virtual void update(sf::Vector2f pPos);
	//virtual sf::Vector2f getPosition();	
	int getDamage();

};

class RegBullet : public Ammunition {
private:
	
	RegBullet(const RegBullet&);

public:
	RegBullet();
	Projectile* consume(sf::Vector2f pCurPos);
	//sf::Vector2f getPosition();
	//void update();
	//void update(sf::Vector2f pPos);
};
