#pragma once

#include "Game/GameEntities/TextUI.h"
#include "Game/GameEntities/OrbEntity.h"
#include "Game/GameEntities/BoardEntity.h"
#include "GameEngine/EntitySystem/Component.h"

namespace Game
{
	class BoardControl : public GameEngine::Component
	{
	public:
		BoardControl();
		~BoardControl();

		void SetBoard(BoardEntity* newBoard);

		void SetScoreUI(TextUI* newUI);

		void SetKeys(sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key down, sf::Keyboard::Key up, sf::Keyboard::Key confirm);

		virtual void Update() override;
		void setCurrentOrb(OrbEntity* newOrb);

		int totalScore = 0;
		float timeAtClear = 0;

	private:
		
		sf::Keyboard::Key ConfirmKey;
		sf::Keyboard::Key LeftKey;
		sf::Keyboard::Key RightKey;
		sf::Keyboard::Key UpKey;
		sf::Keyboard::Key DownKey;

		bool EnterKeyFlag = false;
		bool LeftKeyFlag = false;
		bool RightKeyFlag = false;
		bool UpKeyFlag = false;
		bool DownKeyFlag = false;

		BoardEntity* board;
		OrbEntity* currentOrb;
		TextUI* scoreUI;
	};

}