#include "Controller.h"
#include <stdio.h>

Controller::Controller() 
{
	allTextures->init();
	tested = false; //to remove
	aBGTexture = allTextures->get("bg");
	aBGSprite.setTexture(aBGTexture, false);
};
void Controller::draw()
{
	aWindow->clear(sf::Color::White);
	aWindow->draw(aBGSprite);
	if (tested) //to remove
	{
		test->update();
		aWindow->draw(test->getProjectile());
	}
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
		//Projectile tmp = aPlayer->shoot();
		test = aPlayer->shoot();

		/*aProjectiles->addShot(tmp);
		aWindow->draw(tmp.getProjectile());*/
		aWindow->draw(test->getProjectile()); //to remove
		tested = true;						  //to remove
	}
	aWindow->draw(aPlayer->getShip());
	aWindow->display();
}
void Controller::calcCollisions()
{
	std::list<Projectile*>::iterator ending = aProjectiles->end();
	//check for error at end of list
	for (std::list<Projectile*>::iterator it = aProjectiles->iterator(); it != ending; it++)
	{
		sf::Vector2f pp = (*it)->getPosition();
		sf::Vector2f sp = aPlayer->getPosition();
		float distance = sqrtf(pow((pp.x-sp.x), 2.0)+pow((pp.y-sp.y),2.0));
		if ( distance < 5.0 )
		{
			aPlayer->getHit((*it)->getDamage());
			Projectile* tmp = *it;
			it--;
			aProjectiles->removeShot(tmp);
			
		}
	}
}
Controller &Controller::getInstance()
{
	static Controller INSTANCE;
	return INSTANCE;
}
void Controller::clean()
{
	std::list<Projectile*>::iterator ending = aProjectiles->end();
	for (std::list<Projectile*>::iterator it = aProjectiles->iterator(); it != ending; it++)
	{
		Projectile* aProjectile = *it;
		aProjectiles->removeShot(aProjectile);
		--it;
		delete aProjectile;
		
	}
	delete test;
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
	clean();
}
