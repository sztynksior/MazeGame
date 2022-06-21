#include "Menu.h"

void Menu::setTextures(TextureMenager& pTextureMenager)
{
	this->menuButtons[PLAY].first.setTexture(pTextureMenager.getTextureWithGivenName("PlayButton"));
	this->menuButtons[PLAY].second.setTexture(pTextureMenager.getTextureWithGivenName("SelectedPlayButton"));

	this->menuButtons[EXIT].first.setTexture(pTextureMenager.getTextureWithGivenName("ExitButton"));
	this->menuButtons[EXIT].second.setTexture(pTextureMenager.getTextureWithGivenName("SelectedExitButton"));

	this->menuButtons[EASY].first.setTexture(pTextureMenager.getTextureWithGivenName("EasyButton"));
	this->menuButtons[EASY].second.setTexture(pTextureMenager.getTextureWithGivenName("SelectedEasyButton"));

	this->menuButtons[MEDIUM].first.setTexture(pTextureMenager.getTextureWithGivenName("MediumButton"));
	this->menuButtons[MEDIUM].second.setTexture(pTextureMenager.getTextureWithGivenName("SelectedMediumButton"));

	this->menuButtons[HARD].first.setTexture(pTextureMenager.getTextureWithGivenName("HardButton"));
	this->menuButtons[HARD].second.setTexture(pTextureMenager.getTextureWithGivenName("SelectedHardButton"));
}
