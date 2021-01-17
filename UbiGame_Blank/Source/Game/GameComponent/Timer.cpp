#include "GameEngine/GameEngineMain.h"
#include "Game/GameEntities/TextUI.h"
#include "Game/GameBoard.h"

#include "Timer.h"

#include <algorithm>
#include <iostream>

using namespace std;

const float STARTING_TIME = 60;

Game::Timer::Timer(GameBoard* gb) {

    gameBoard = gb;
	timerText = new TextUI("Timer: ");
	timerText->SetPos(sf::Vector2f(530, 50));
    reset();
}

Game::Timer::~Timer() {}

void Game::Timer::start() {
    started = true;
}
void Game::Timer::reset() {
    started = false;
    timeLeft = STARTING_TIME + 5;
}

void Game::Timer::stop() {
    started = false;
}

void Game::Timer::update(float delta) {
    if (started) {
        timeLeft -= delta;
    }

    if (timeLeft < 0) timeLeft = 0;

    float countDown = timeLeft - STARTING_TIME;

    if (countDown > -2) {
        if (countDown > 1) {
           timerText->SetString(to_string((int)(timeLeft - STARTING_TIME)));
        } else {
            timerText->SetString("GO!");
        }
    } else {
        timerText->SetString("Time left: " + to_string(timeLeft));
    }
}