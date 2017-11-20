#pragma once

#include <TGUI/TGUI.hpp>
class Projectile
{
private:
	sf::Sprite aSprite;
	sf::Texture* aTexture;
	int areaOfEffect;
	int aDamage;
	float aSpeed;
public:
	Projectile(sf::Texture* pText, int pAOE, int pDam, float pSpeed, sf::Vector2f pPos)
	{
		aTexture = pText;
		areaOfEffect = pAOE;
		aDamage = pDam;
		aSpeed = pSpeed;
		aSprite.setTexture(*aTexture);
		aSprite.setScale(0.05, 0.05);
		aSprite.setPosition(pPos.x+30.0, pPos.y+15.0);

	}
	void update()
	{
		aSprite.move(aSpeed, 0.0);
	}
	sf::Sprite getProjectile()
	{
		return aSprite;
	}
	sf::Vector2f getPosition()
	{
		return aSprite.getPosition();
	}
	int getDamage()
	{
		return aDamage;
	}
	bool operator==(const Projectile& p1)
	{
		return (p1.areaOfEffect == areaOfEffect && p1.aSpeed == aSpeed && p1.aSprite.getPosition() == aSprite.getPosition());
	}
};
