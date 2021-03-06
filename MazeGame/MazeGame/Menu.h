#ifndef MENU_H
#define MENU_H

#include "TextureMenager.h"
#include <SFML/Graphics.hpp>
#include <utility>

#define MENU_BUTTONS 4
class Menu : public sf::Drawable
{
private:
	enum whichButton {EASY, MEDIUM, HARD, EXIT};

	int windowWidth, windowLenght;
	std::vector<std::pair<sf::Texture, sf::Texture>> menuButtonsTextures;
	std::vector<sf::Sprite> menuButtons;
	int selectedButton = 0;

	void setPositions();
	void select(whichButton pWitchButton);
	void unselect(whichButton pWitchButton);

public:

	Menu(int pWindowWidth,int  pWindowLenght);

	void setTextures(TextureMenager& pTextureMenager);
	void setSprites();
	void moveUp();
	void moveDown();
	int getPreessedButton();

	void draw(sf::RenderTarget& pTarget, sf::RenderStates pStates) const;

};

#endif // !MENU_H




