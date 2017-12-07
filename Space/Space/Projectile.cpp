#include "Projectile.h"


Projectile::Projectile(sf::Texture* pText, int pAOE, int pDam, float pSpeed, sf::Vector2f pPos)
{
	aTexture = pText;
	areaOfEffect = pAOE;
	aDamage = pDam;
	aSpeed = pSpeed;
	aSprite.setTextureRect(sf::IntRect(795, 900, 1309, 1027));
	aSprite.setTexture(*aTexture);
	aSprite.setScale(0.05, 0.05);
	aSprite.setPosition(pPos.x + 30.0, pPos.y + 15.0);

}
void Projectile::update()
{
	aSprite.move(aSpeed, 0.0);
}
sf::Sprite Projectile::getProjectile()
{
	return aSprite;
}
sf::Vector2f Projectile::getPosition()
{
	return aSprite.getPosition();
}
int Projectile::getDamage()
{
	return aDamage;
}
bool Projectile::operator==(const Projectile& p1)
{
	return (p1.areaOfEffect == areaOfEffect && p1.aSpeed == aSpeed && p1.aSprite.getPosition() == aSprite.getPosition());
}