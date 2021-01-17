#pragma once

#include "Game/GameComponent/BoardControl.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Entity.h"

namespace Game
{
	class PlayerEntity : public GameEngine::Entity
	{
	public:
		PlayerEntity(BoardEntity* board);
		~PlayerEntity();

	protected:
		BoardControl* BoardControlComponent;
		GameEngine::SpriteRenderComponent* m_renderComponent;
	};
}


