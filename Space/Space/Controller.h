#pragma once
#include "SpaceShip.h"
#include "TextureRefs.h"
#include "AmmunitionShot.h"
#include "SpaceObjectObserver.h"
#include "stdafx.h"

class Controller
{
private:
	Controller();
	std::shared_ptr<TextureRefs> allTextures = TextureRefs::getTextRefs();

	int aWindowWidth = 1024;
	int aWindowHeight = 720;
	sf::Sprite aBGSprite;
	sf::Texture* aBGTexture;
	std::shared_ptr<SpaceShip> aPlayer{new SpaceShip(aWindowHeight/2)};
	AmmunitionShot* aProjectiles;
	SpaceObjectObserver* aSpaceObjects;
	
	sf::RenderWindow* aWindow;
	void draw();
	sf::Clock clock;
	sf::Time dt;
	int32_t dtAsSeconds;
	int32_t prev_dtAsSeconds;
	void mainMenu();


	
public:
	static Controller& getInstance();
	void start();
	void addElement();
	

};


