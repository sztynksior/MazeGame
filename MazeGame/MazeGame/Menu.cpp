#include "Menu.h"

void Menu::setSprites()
{
	sf::Vector2f textureSize(this->menuButtonsTextures[EASY].first.getSize().x, this->menuButtonsTextures[EASY].first.getSize().y);

	this->menuButtons.push_back(sf::Sprite(this->menuButtonsTextures[EASY].second));
	this->menuButtons.push_back(sf::Sprite(this->menuButtonsTextures[MEDIUM].second));
	this->menuButtons.push_back(sf::Sprite(this->menuButtonsTextures[HARD].second));
	this->menuButtons.push_back(sf::Sprite(this->menuButtonsTextures[EXIT].second));

	this->menuButtons[EASY].setPosition(sf::Vector2f((this->windowWidth / 2) - (textureSize.x / 2), this->windowLenght / MENU_BUTTONS * 1));
	this->menuButtons[MEDIUM].setPosition(sf::Vector2f((this->windowWidth / 2) - (textureSize.x / 2), this->windowLenght / MENU_BUTTONS * 1));
	this->menuButtons[HARD].setPosition(sf::Vector2f((this->windowWidth / 2) - (textureSize.x / 2), this->windowLenght / MENU_BUTTONS * 1));
	this->menuButtons[EXIT].setPosition(sf::Vector2f((this->windowWidth / 2) - (textureSize.x / 2), this->windowLenght / MENU_BUTTONS * 1));
}

void Menu::draw(sf::RenderTarget& pTarget, sf::RenderStates pStates) const
{
	for (sf::Sprite i : this->menuButtons)
	{
		pTarget.draw(i, pStates);
	}
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