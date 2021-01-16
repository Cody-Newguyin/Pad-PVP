#pragma once

#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

namespace Game
{
	class OrbEntity : public GameEngine::Entity
	{
	public:
		OrbEntity();
		~OrbEntity();
		
		int GetId();
		void SetId(int newId);

		int GetxPos();
		int GetyPos();

		void SetxPos(int xPos);
		void SetyPos(int yPos);

		void setTexture();

	protected:
		int Id;
		float xPos;
		float yPos;

		GameEngine::SpriteRenderComponent* m_renderComponent;
	};
}


