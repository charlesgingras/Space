#pragma once
#include <stdio.h>
#include <unordered_map>
#include <TGUI/TGUI.hpp>

class TextureRefs
{
private:
	std::unordered_map<std::string, sf::Texture> aTextures;
	TextureRefs() {};
public:
	static TextureRefs& getTextRefs()
	{
		static TextureRefs INSTANCE;
		return INSTANCE;
	}
	sf::Texture get(std::string pString)
	{
		/*std::unordered_map<std::string, sf::Texture>::const_iterator got = aTextures.find(pString);
		return got->second;*/
		return aTextures.find(pString)->second;
	}
	void init()
	{
		sf::Texture tmp;
		tmp.loadFromFile("bg.png");
		aTextures.insert({ "bg", tmp });
		tmp.loadFromFile("myShip.png");
		aTextures.insert({ "myShip", tmp });
		tmp.loadFromFile("regShot.png");
		aTextures.insert({ "regShot", tmp });
	}
};
