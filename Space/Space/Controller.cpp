#include "Controller.h"
#include <stdio.h>

Controller::Controller() 
{
	aBGSprite.setTextureRect(sf::IntRect(0, 0, 1143, 865));
	aBGSprite.setTexture(*(allTextures->getTexture()), false);
};
void Controller::draw()
{
	aWindow->clear(sf::Color::White);
	aWindow->draw(aBGSprite);
	
	aProjectiles->update(aWindow);
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		aPlayer->moveRight(-1.0, aWindowWidth);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		aPlayer->moveRight(1.0, aWindowWidth);
	}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		aPlayer->moveUp(-1.0, aWindowHeight);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		aPlayer->moveUp(1.0, aWindowHeight);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Projectile* tmp = aPlayer->shoot();
		aProjectiles->addShot(tmp);
		aWindow->draw(tmp->getProjectile());
	}
	aWindow->draw(aPlayer->getShip());
	aWindow->display();
}

Controller &Controller::getInstance()
{
	static Controller INSTANCE;
	return INSTANCE;
}

void Controller::start()
{
	
	sf::RenderWindow someWindow(sf::VideoMode(aWindowWidth, aWindowHeight), "Space Invaders");
	aWindow = &someWindow;
	spaceShip someShip = spaceShip(aWindowHeight / 2.0);
	aPlayer = &someShip;
	AmmunitionShot someProjectiles = AmmunitionShot::getInstance();
	aProjectiles = &someProjectiles;

	while (aWindow->isOpen())
	{
		sf::Event event;
		while (aWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				aWindow->close();
		}
		this->draw();
	}
	//clean();
}
