#include "TextureManager.h"

using namespace GameEngine;

TextureManager* TextureManager::sm_instance = nullptr;

TextureManager::TextureManager()
{
	for (int a = 0; a < (int)eTexture::Count; ++a)
	{
		m_textures[a] = nullptr;
	}
}


TextureManager::~TextureManager()
{
	UnLoadTextures();
}


void TextureManager::LoadTextures()
{
	for (int a = 0; a < (int)eTexture::Count; ++a)
	{
		sf::Texture* texture = new sf::Texture();
		std::string filePath;
		filePath.append("Resources/img/");
		filePath.append(GetPath((eTexture::type)a));
		texture->loadFromFile(filePath);

		m_textures[a] = texture;
	}
}


void TextureManager::UnLoadTextures()
{
	for (int a = 0; a < (int)eTexture::Count; ++a)
	{
		delete m_textures[a];
		m_textures[a] = nullptr;
	}
}

namespace TextureHelper
{
	sf::Vector2f GetTextureTileSize(GameEngine::eTexture::type texture)
	{	
		switch (texture)
		{
		case GameEngine::eTexture::Orb_1:	return sf::Vector2f(75.f, 75.f);
		case GameEngine::eTexture::Orb_2:	return sf::Vector2f(75.f, 75.f);
		case GameEngine::eTexture::Orb_3:	return sf::Vector2f(75.f, 75.f);
		case GameEngine::eTexture::Orb_4:	return sf::Vector2f(75.f, 75.f);
		case GameEngine::eTexture::Orb_5:	return sf::Vector2f(75.f, 75.f);
		case GameEngine::eTexture::Orb_6:	return sf::Vector2f(75.f, 75.f);
		case GameEngine::eTexture::Board_Bg:	return sf::Vector2f(480.f, 405.f);
		case GameEngine::eTexture::Overlay:		return sf::Vector2f(75.f, 75.f);
		}
		return sf::Vector2f(-1.f, -1.f);
	}
}
