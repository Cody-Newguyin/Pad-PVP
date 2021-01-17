#include "GameEngine/GameEngineMain.h"
#include "Game/GameEntities/TextUI.h"
#include "Game/GameBoard.h"

#include "Timer.h"

#include <algorithm>

using namespace std;

Game::Timer::Timer(GameBoard* gb) {

    gameBoard = gb;
	timerText = new TextUI("Timer: ");
	timerText->SetPos(sf::Vector2f(530, 50));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(timerText);

    reset();
}

Game::Timer::~Timer() {}

void Game::Timer::start() {
    started = true;
}
void Game::Timer::reset() {
    started = false;
    timeLeft = 5;
}

void Game::Timer::stop() {
    started = false;
}

void Game::Timer::update(float delta) {
    if (started) {
        timeLeft -= delta;
    }

    if (timeLeft < 0) timeLeft = 0;

	timerText->SetString("Time left: " + to_string(timeLeft));
}