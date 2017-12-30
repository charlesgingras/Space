#pragma once

#include <TGUI/TGUI.hpp>
/*The Projectile class is used to represent projectiles in flight, both conceptually and visually;
the class is generic for all projectiles*/
class Projectile
{
private:
	sf::Sprite* aSprite;
	sf::Texture* aTexture;
	int areaOfEffect;
	int aDamage;
	float aSpeed;
public:
	Projectile(sf::Texture* pText, int pAOE, int pDam, float pSpeed, sf::Vector2f pPos);
	Projectile(Projectile&& pProj);
	~Projectile();
	void update();
	sf::Sprite getProjectile();
	sf::Vector2f getPosition();
	int getDamage();
	bool operator==(const Projectile& p1);
};
