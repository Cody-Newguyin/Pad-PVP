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

	protected:
		int Id;

		GameEngine::SpriteRenderComponent* m_renderComponent;
	};
}


