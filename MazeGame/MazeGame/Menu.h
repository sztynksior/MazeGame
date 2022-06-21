#ifndef MENU_H
#define MENU_H

#include "TextureMenager.h"
#include <SFML/Graphics.hpp>
#include <utility>

#define MENU_BUTTONS 4
class Menu : sf::Drawable
{
private:
	enum whichButton {EASY, MEDIUM, HARD, EXIT};

	int windowWidth, windowLenght;
	std::vector<std::pair<sf::Texture, sf::Texture>> menuButtonsTextures;
	std::vector<sf::Sprite> menuButtons;
	whichButton selectedButton = EASY;

	void setSprites();
	void setPositions();
	void select(whichButton pWitchButton);
	void unselect(whichButton pWitchButton);

public:

	void setTextures(TextureMenager& pTextureMenager);
	void moveUp();
	void moveDown();

};

#endif // !MENU_H




