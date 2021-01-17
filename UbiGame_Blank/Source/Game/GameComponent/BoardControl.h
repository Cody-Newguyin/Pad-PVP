#pragma once

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

		virtual void Update() override;
		void setCurrentOrb(OrbEntity* newOrb);

	private:
		bool lastState = false;
		bool currentState = false;

		bool LeftKeyFlag = false;
		bool RightKeyFlag = false;
		bool UpKeyFlag = false;
		bool DownKeyFlag = false;

		BoardEntity* board;
		OrbEntity* currentOrb;
	};

}