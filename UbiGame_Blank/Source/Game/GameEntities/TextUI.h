#pragma once

#include "GameEngine/EntitySystem/Entity.h"
#include <string.h>
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"

namespace Game
{
	class TextUI : public GameEngine::Entity
	{
	public:
		TextUI(std::string text);
		~TextUI();
		void SetString(std::string text);

	protected:
		GameEngine::TextRenderComponent* textComponent;
	};
	;
}

