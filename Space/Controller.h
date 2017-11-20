#pragma once
#include "spaceShip.h"
#include "TextureRefs.h"
#include "AmmunitionShot.h"

class Controller
{
private:
	Controller();
	TextureRefs* allTextures = &(TextureRefs::getTextRefs());
	Projectile* test;
	bool tested;
	sf::Sprite aBGSprite;
	sf::Texture aBGTexture;
	spaceShip* aPlayer;
	AmmunitionShot* aProjectiles;
	int aWindowWidth = 1024;
	int aWindowHeight = 720;
	sf::RenderWindow* aWindow;
	void draw();
	void clean();
	
public:
	static Controller& getInstance();
	void calcCollisions();
	void start();
	void addElement();
	

};


