#ifndef TEXTUREMENAGER_H
#define TEXTUREMENAGER_H

#include <SFML/Graphics.hpp>
#include <filesystem>
#include <unordered_map>

class TextureMenager
{
private:

	std::unordered_map<std::string, sf::Texture> TextureMap;
	std::filesystem::path fileWithTexturesPath;

public:

	TextureMenager(std::string pFileWithTexturesPath);
	void SetTextureMap();

};

#endif // !TEXTUREMENAGER_H