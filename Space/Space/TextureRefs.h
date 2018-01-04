#pragma once
#include <stdio.h>
#include <TGUI/TGUI.hpp>
//bg: 0,0 -> 1143,865
//space ship:7,870 -> 725, 1597
//reg shot: 795,900 -> 1309, 1027
//asteroid : 1149,0 -> 1565, 390
class TextureRefs
{
private:
	sf::Texture allTextures;
	TextureRefs() {
		allTextures.loadFromFile("TextureCollage.png");
	};
public:
	static std::shared_ptr<TextureRefs>& getTextRefs()
	{
		static std::shared_ptr<TextureRefs> INSTANCE{ new TextureRefs };
		return INSTANCE;
	}
	sf::Texture* getTexture()
	{
		return &allTextures;
	}
};
