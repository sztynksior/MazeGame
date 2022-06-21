#ifndef MENU_H
#define MENU_H

#include "TextureMenager.h"
#include <SFML/Graphics.hpp>
#include <utility>

#define MENU_BUTTONS 5
class Menu : sf::Drawable
{
private:
	enum whichButton {PLAY, EXIT, EASY, MEDIUM, HARD};

	std::vector<std::pair<sf::Sprite, sf::Sprite>> menuButtons;

public:

	void setTextures(TextureMenager& pTextureMenager);

};

#endif // !MENU_H




