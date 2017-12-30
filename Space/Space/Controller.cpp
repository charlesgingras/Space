#include "Controller.h"
#include <stdio.h>

Controller::Controller() 
{
	aBGSprite.setTextureRect(sf::IntRect(0, 0, 1143, 865)); //loads correct picture for background
	aBGSprite.setTexture(*(allTextures->getTexture()), false);
};
/*draws elements to the screen and refreshes the image*/
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
		if (aPlayer->getAmmoPtr()->getDelay() < dtAsSeconds)
		{
			Projectile* tmp = aPlayer->shoot();
			aProjectiles->addShot(tmp);
			aWindow->draw(tmp->getProjectile());
			dtAsSeconds = 0;
		}
		
	}
	aWindow->draw(aPlayer->getShip());
	aWindow->display();
}

Controller &Controller::getInstance()
{
	static Controller INSTANCE;
	return INSTANCE;
}
/*displays the main menu before the player enters the game*/
void Controller::mainMenu()
{
	tgui::Theme::Ptr theme = tgui::Theme::create("Black.txt");
	tgui::Button::Ptr button1 = theme->load("Button");
	tgui::Button::Ptr button2 = theme->load("Button");
	bool idle = true;
	button1->connect("pressed", [&]() {idle = false; });
	//button2->connect("pressed", 3d mode? TODO)
	tgui::Gui gui{ *aWindow };
	button1->setSize(200, 40);
	button2->setSize(tgui::bindSize(button1));
	button1->setText("Classic Play");
	button2->setText("3D mode (to come)");
	gui.add(button1, "Classic Play");
	gui.add(button2, "3D mode (to come)");
	button1->setPosition(tgui::Layout2d(sf::Vector2f(aWindowWidth/2-100, 200)));

	button2->setPosition(tgui::Layout2d(sf::Vector2f(aWindowWidth / 2-100, 400)));
	while (aWindow->isOpen() && idle)
	{
		sf::Event event;
		while (aWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				aWindow->close();

			gui.handleEvent(event);
		}

		aWindow->clear();
		gui.draw(); 
		aWindow->display();
	}
}
/*begins running the Controller object*/
void Controller::start()
{
	
	sf::RenderWindow someWindow(sf::VideoMode(aWindowWidth, aWindowHeight), "Space Invaders");
	aWindow = &someWindow;
	mainMenu();
	SpaceShip someShip = SpaceShip(aWindowHeight / 2.0);
	aPlayer = &someShip;
	AmmunitionShot someProjectiles = AmmunitionShot::getInstance();
	aProjectiles = &someProjectiles;
	clock.restart();
	while (aWindow->isOpen())
	{

		sf::Event event;
		while (aWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				aWindow->close();
		}
		dt = clock.restart();
		dtAsSeconds += dt.asMilliseconds();
		this->draw();
	}
	//clean();
}
