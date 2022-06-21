#include "Menu.h"

void Menu::setSprites()
{
	sf::Vector2f textureSize(this->menuButtonsTextures[EASY].first.getSize().x, this->menuButtonsTextures[EASY].first.getSize().y);

	this->menuButtons[EASY].setTexture(this->menuButtonsTextures[EASY].second);
	this->menuButtons[MEDIUM].setTexture(this->menuButtonsTextures[MEDIUM].first);
	this->menuButtons[HARD].setTexture(this->menuButtonsTextures[HARD].first);
	this->menuButtons[EXIT].setTexture(this->menuButtonsTextures[EXIT].first);

	this->menuButtons[EASY].setPosition(sf::Vector2f((this->windowWidth / 2) - (textureSize.x / 2), this->windowLenght / MENU_BUTTONS * 1));
	this->menuButtons[MEDIUM].setPosition(sf::Vector2f((this->windowWidth / 2) - (textureSize.x / 2), this->windowLenght / MENU_BUTTONS * 1));
	this->menuButtons[HARD].setPosition(sf::Vector2f((this->windowWidth / 2) - (textureSize.x / 2), this->windowLenght / MENU_BUTTONS * 1));
	this->menuButtons[EXIT].setPosition(sf::Vector2f((this->windowWidth / 2) - (textureSize.x / 2), this->windowLenght / MENU_BUTTONS * 1));
}

Menu::Menu(int pWindowWidth, int pWindowLenght)
{
	this->windowWidth = pWindowWidth;
	this->windowLenght = pWindowLenght;
}

void Menu::setTextures(TextureMenager& pTextureMenager)
{
	this->menuButtonsTextures.push_back({ pTextureMenager.getTextureWithGivenName("EasyBytton") ,pTextureMenager.getTextureWithGivenName("SelectedEasyBytton") });

	this->menuButtonsTextures.push_back({ pTextureMenager.getTextureWithGivenName("MediumButton") ,pTextureMenager.getTextureWithGivenName("SelectedMediumButton") });

	this->menuButtonsTextures.push_back({ pTextureMenager.getTextureWithGivenName("HardButton") ,pTextureMenager.getTextureWithGivenName("SelectedHardButton") });

	this->menuButtonsTextures.push_back({ pTextureMenager.getTextureWithGivenName("ExitButton") ,pTextureMenager.getTextureWithGivenName("SelectedExitButton") });
}