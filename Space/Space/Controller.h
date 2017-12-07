#pragma once
#include "spaceShip.h"
#include "TextureRefs.h"
#include "AmmunitionShot.h"

class Controller
{
private:
	Controller();
	TextureRefs* allTextures = &(TextureRefs::getTextRefs());
	
	sf::Sprite aBGSprite;
	sf::Texture* aBGTexture;
	spaceShip* aPlayer;
	AmmunitionShot* aProjectiles;
	int aWindowWidth = 1024;
	int aWindowHeight = 720;
	sf::RenderWindow* aWindow;
	void draw();

	
public:
	static Controller& getInstance();
	void start();
	void addElement();
	

};


