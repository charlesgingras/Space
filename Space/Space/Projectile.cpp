#include "Projectile.h"


Projectile::Projectile(sf::Texture* pText, int pAOE, int pDam, float pSpeed, sf::Vector2f pPos)
	:aSprite{ new sf::Sprite }
{
	aTexture = pText;
	areaOfEffect = pAOE;
	aDamage = pDam;
	aSpeed = pSpeed;
	aSprite->setTexture(*aTexture);
	aSprite->setTextureRect(sf::IntRect(795, 900, 1309, 1027));
	aSprite->setScale(0.05, 0.05);
	aSprite->setPosition(pPos.x + 30.0, pPos.y + 15.0);

}
Projectile::Projectile(Projectile&& pProj)
{
	aTexture = pProj.aTexture;
	areaOfEffect = pProj.areaOfEffect;
	aDamage = pProj.aDamage;
	aSpeed = pProj.aSpeed;
	aSprite = pProj.aSprite;
	pProj.aTexture = nullptr;
	pProj.areaOfEffect = 0;
	pProj.aDamage = 0;
	pProj.aSpeed = 0;
	pProj.aSprite = nullptr;
}
Projectile::~Projectile() {}
/*Updates the position of the object*/
void Projectile::update()
{
	aSprite->move(aSpeed, 0.0);
}
/*Returns the Sprite field of the Projectile object*/
sf::Sprite Projectile::getProjectile()
{
	return *aSprite;
}
/*Returns the Vector2f field of the Projectile object*/
sf::Vector2f Projectile::getPosition()
{
	return aSprite->getPosition();
}
/*Returns the damage field of the Projectile object*/
int Projectile::getDamage()
{
	return aDamage;
}
bool Projectile::operator==(const Projectile& p1)
{
	return (p1.areaOfEffect == areaOfEffect && p1.aSpeed == aSpeed && p1.aSprite->getPosition() == aSprite->getPosition());
}