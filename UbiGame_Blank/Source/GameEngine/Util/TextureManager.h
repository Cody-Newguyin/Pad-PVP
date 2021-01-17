#pragma once
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameEngine
{
	//TODO - if needed, move out of Engine part to some sort of loader on the game side of things
	namespace eTexture
	{
		enum type
		{
			None = -1,
			Orb_1 = 0,
			Orb_2 = 1,
			Orb_3 = 2,
			Orb_4 = 3,
			Orb_5 = 4,
			Orb_6 = 5,
			Board_Bg = 6,
			Overlay = 7,
			AddYourTexturesEnumerationsHere, // Replace this for your own enumerations

			Count,
		};
	}	

	inline const char* GetPath(eTexture::type texture)
	{	
		switch (texture)
		{
		case eTexture::Orb_1:	return "orb_1.png";
		case eTexture::Orb_2:	return "orb_2.png";
		case eTexture::Orb_3:	return "orb_3.png";
		case eTexture::Orb_4:	return "orb_4.png";
		case eTexture::Orb_5:	return "orb_5.png";
		case eTexture::Orb_6:	return "orb_6.png";
		case eTexture::Board_Bg: return "board_bg.png";
		case eTexture::Overlay: return "overlay.png";
		
		default:	return "UnknownTexType";
		}
		
	}

	class TextureManager
	{
	public:
		static TextureManager* GetInstance() { if (!sm_instance) sm_instance = new TextureManager(); return sm_instance; }
		~TextureManager();

		void LoadTextures();
		void UnLoadTextures();

		sf::Texture* GetTexture(eTexture::type texture) const { return m_textures[(int)texture]; }

	private:
		TextureManager();
		static TextureManager* sm_instance;

		sf::Texture* m_textures[eTexture::Count];
	};
}

namespace TextureHelper
{
	sf::Vector2f GetTextureTileSize(GameEngine::eTexture::type texture);
}

