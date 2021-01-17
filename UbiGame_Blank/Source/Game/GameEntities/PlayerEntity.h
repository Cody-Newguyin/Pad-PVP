#pragma once

#include "TextUI.h"
#include <string.h>
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

		void SetKeys(sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key down, sf::Keyboard::Key up, sf::Keyboard::Key confirm);

	protected:
		TextUI* name;
		TextUI* score;

		BoardControl* BoardControlComponent;
		GameEngine::SpriteRenderComponent* m_renderComponent;
	};
}


