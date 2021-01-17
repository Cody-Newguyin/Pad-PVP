#pragma once
#include "GameEngine/EntitySystem/Entity.h"

#include <SFML/System/Vector2.hpp>
#include <vector>

namespace Game
{
	//Used for storing and controlling all game related entities, as well as providing an entry point for the "game" side of application	
	class BoardEntity;
	class PlayerEntity;

	class GameBoard
	{
	public:
		GameBoard();
		virtual ~GameBoard();

		void Update();		
		bool IsGameOver() { return false; }

	protected:
		BoardEntity* board1;
		PlayerEntity* player1;
		BoardEntity* board2;
		PlayerEntity* player2;

	};
}

