#pragma once
#include "SpaceShip.h"
#include "TextureRefs.h"
#include "AmmunitionShot.h"
#include "stdafx.h"

class Controller
{
private:
	Controller();
	TextureRefs* allTextures = &(TextureRefs::getTextRefs());
	
	sf::Sprite aBGSprite;
	sf::Texture* aBGTexture;
	SpaceShip* aPlayer;
	AmmunitionShot* aProjectiles;
	int aWindowWidth = 1024;
	int aWindowHeight = 720;
	sf::RenderWindow* aWindow;
	void draw();
	sf::Clock clock;
	sf::Time dt;
	int32_t dtAsSeconds;
	void mainMenu();


	
public:
	static Controller& getInstance();
	void start();
	void addElement();
	

};


