#include "TextureMenager.h"

TextureMenager::TextureMenager(std::string pFileWithTexturesPath)
{
	this->fileWithTexturesPath = std::filesystem::current_path().append(pFileWithTexturesPath);
}

void TextureMenager::SetTextureMap()
{
	std::regex stringToReplace(".jpg");

	for (std::filesystem::directory_entry entry : std::filesystem::directory_iterator(this->fileWithTexturesPath))
	{
		std::string tFileName = entry.path().filename().string();
		std::string textureName;

		std::regex_replace(std::back_inserter(textureName), tFileName.begin(), tFileName.end(), stringToReplace, "");

		sf::Texture texture;
		if (!texture.loadFromFile(entry.path().string()))
		{
			return;
		}

		this->TextureMap.insert({ textureName, texture });

	}
}

sf::Texture& TextureMenager::getTextureWithGivenName(const std::string& pTextureName)
{
	return this->TextureMap[pTextureName];
}