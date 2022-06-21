#include "Menu.h"

void Menu::setTextures(TextureMenager& pTextureMenager)
{
	this->menuButtonsTextures.push_back({ pTextureMenager.getTextureWithGivenName("EasyBytton") ,pTextureMenager.getTextureWithGivenName("SelectedEasyBytton") });

	this->menuButtonsTextures.push_back({ pTextureMenager.getTextureWithGivenName("MediumButton") ,pTextureMenager.getTextureWithGivenName("SelectedMediumButton") });

	this->menuButtonsTextures.push_back({ pTextureMenager.getTextureWithGivenName("HardButton") ,pTextureMenager.getTextureWithGivenName("SelectedHardButton") });

	this->menuButtonsTextures.push_back({ pTextureMenager.getTextureWithGivenName("ExitButton") ,pTextureMenager.getTextureWithGivenName("SelectedExitButton") });
}