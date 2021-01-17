#pragma once

#include "Game/GameEntities/TextUI.h"
#include "Game/GameBoard.h"

namespace Game
{
	class Timer {
      public:
		Timer(GameBoard* gb);
		~Timer();

		void start();
        void stop();
        void reset();
		void update(float delta);

        TextUI* timerText;
        GameBoard* gameBoard;
        float timeLeft;
        bool started;
	};
}