#include "Menu.h"

void Menu::setSprites()
{
	sf::Vector2f textureSize(this->menuButtonsTextures[EASY].first.getSize().x, this->menuButtonsTextures[EASY].first.getSize().y);

	this->menuButtons.push_back(sf::Sprite(this->menuButtonsTextures[EASY].second));
	this->menuButtons.push_back(sf::Sprite(this->menuButtonsTextures[MEDIUM].first));
	this->menuButtons.push_back(sf::Sprite(this->menuButtonsTextures[HARD].first));
	this->menuButtons.push_back(sf::Sprite(this->menuButtonsTextures[EXIT].first));

	this->menuButtons[EASY].setPosition(sf::Vector2f((this->windowWidth / 2) - (textureSize.x / 2), this->windowLenght / MENU_BUTTONS * 2/3));
	this->menuButtons[MEDIUM].setPosition(sf::Vector2f((this->windowWidth / 2) - (textureSize.x / 2), this->windowLenght / MENU_BUTTONS * 5/3));
	this->menuButtons[HARD].setPosition(sf::Vector2f((this->windowWidth / 2) - (textureSize.x / 2), this->windowLenght / MENU_BUTTONS * 8/3));
	this->menuButtons[EXIT].setPosition(sf::Vector2f((this->windowWidth / 2) - (textureSize.x / 2), this->windowLenght / MENU_BUTTONS * 11/3));
}

void Menu::moveUp()
{
	if (this->selectedButton - 1 >= 0)
	{
		this->menuButtons[selectedButton].setTexture(this->menuButtonsTextures[selectedButton].first);
		this->selectedButton--;
		this->menuButtons[selectedButton].setTexture(this->menuButtonsTextures[selectedButton].second);
	}
}

void Menu::moveDown()
{
	if (this->selectedButton + 1 < MENU_BUTTONS)
	{
		this->menuButtons[selectedButton].setTexture(this->menuButtonsTextures[selectedButton].first);
		this->selectedButton++;
		this->menuButtons[selectedButton].setTexture(this->menuButtonsTextures[selectedButton].second);
	}
}

int Menu::getPreessedButton()
{
	return this->selectedButton;
}

void Menu::draw(sf::RenderTarget& pTarget, sf::RenderStates pStates) const
{
	for (sf::Sprite i : this->menuButtons)
	{
		pTarget.draw(i, pStates);
	}
}

void Menu::setPositions()
{
}

void Menu::select(whichButton pWitchButton)
{
}

void Menu::unselect(whichButton pWitchButton)
{
}

Menu::Menu(int pWindowWidth, int pWindowLenght)
{
	this->windowWidth = pWindowWidth;
	this->windowLenght = pWindowLenght;
}

void Menu::setTextures(TextureMenager& pTextureMenager)
{
	this->menuButtonsTextures.push_back({ pTextureMenager.getTextureWithGivenName("EasyButton") ,pTextureMenager.getTextureWithGivenName("SelectedEasyButton") });

	this->menuButtonsTextures.push_back({ pTextureMenager.getTextureWithGivenName("MediumButton") ,pTextureMenager.getTextureWithGivenName("SelectedMediumButton") });

	this->menuButtonsTextures.push_back({ pTextureMenager.getTextureWithGivenName("HardButton") ,pTextureMenager.getTextureWithGivenName("SelectedHardButton") });

	this->menuButtonsTextures.push_back({ pTextureMenager.getTextureWithGivenName("ExitButton") ,pTextureMenager.getTextureWithGivenName("SelectedExitButton") });
}