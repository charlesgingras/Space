#pragma once
#include <stdio.h>
#include <unordered_map>
#include <TGUI/TGUI.hpp>
//bg: 0,0 -> 1143,865
//space ship:7,870 -> 725, 1597
//reg shot: 795,900 -> 1309, 1027
class TextureRefs
{
private:
	sf::Texture allTextures;
	TextureRefs() {
		allTextures.loadFromFile("Textures.png");
	};
public:
	static TextureRefs& getTextRefs()
	{
		static TextureRefs INSTANCE;
		return INSTANCE;
	}
	sf::Texture* getTexture()
	{
		return &allTextures;
	}
};
