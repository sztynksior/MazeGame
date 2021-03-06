#ifndef TEXTUREMENAGER_H
#define TEXTUREMENAGER_H

#include <SFML/Graphics.hpp>
#include <filesystem>
#include <unordered_map>
#include <string>
#include <regex>
#include <iterator>

class TextureMenager
{
private:

	std::unordered_map<std::string, sf::Texture> TextureMap;
	std::filesystem::path fileWithTexturesPath;

public:

	TextureMenager(std::string pFileWithTexturesPath);
	void SetTextureMap();
	sf::Texture& getTextureWithGivenName(const std::string& pTextureName);
};

#endif // !TEXTUREMENAGER_H