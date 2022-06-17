#include "TextureMenager.h"

TextureMenager::TextureMenager(std::string pFileWithTexturesPath)
{
	this->fileWithTexturesPath = std::filesystem::current_path().append(pFileWithTexturesPath);
}

void TextureMenager::SetTextureMap()
{


	for (std::filesystem::directory_entry entry : std::filesystem::directory_iterator(this->fileWithTexturesPath))
	{
		sf::Texture texture;
		if (!texture.loadFromFile(entry.path().string()))
		{
			return;
		}

		this->TextureMap.insert({ entry.path().filename().string(), texture });
	}
}
