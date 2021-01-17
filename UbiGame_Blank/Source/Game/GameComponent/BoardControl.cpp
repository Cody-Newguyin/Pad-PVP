#include "BoardControl.h"

#include <iostream>
#include "Game/GameBoard.h"
#include "Game/GameEntities/BoardEntity.h"
#include "Game/GameEntities/TextUI.h"
#include "GameEngine/GameEngineMain.h"
#include <SFML/Window/Keyboard.hpp>

using namespace Game;

Game::BoardControl::BoardControl()
{
	
}

Game::BoardControl::~BoardControl()
{
}

void Game::BoardControl::SetBoard(BoardEntity* newBoard) {
	board = newBoard;
	currentOrb = board->GetFirstOrb();
}

void Game::BoardControl::SetScoreUI(TextUI* newUI) {
	scoreUI = newUI;
}

void Game::BoardControl::SetKeys(sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key down, sf::Keyboard::Key up, sf::Keyboard::Key confirm)
{
	LeftKey = left;
	RightKey = right;
	UpKey = up;
	DownKey = down;
	ConfirmKey = confirm;
}

void Game::BoardControl::Update()
{
	Component::Update();

	if (GameEngine::GameEngineMain::GetInstance()->IsGameOver())
	{
		return;
	}

	bool left = sf::Keyboard::isKeyPressed(LeftKey);
	bool right = sf::Keyboard::isKeyPressed(RightKey);
	bool up = sf::Keyboard::isKeyPressed(UpKey);
	bool down = sf::Keyboard::isKeyPressed(DownKey);
	
	// if (!board->started) {
	// 	if (left || right || up || down) {
	// 		board->started = true;
	// 	}
	// }


	if (!LeftKeyFlag && sf::Keyboard::isKeyPressed(LeftKey))
	{
		LeftKeyFlag = true;
		if (currentOrb->GetxPos() != 0)
		{
			board->SwapOrb(currentOrb->GetxPos(), currentOrb->GetyPos(), currentOrb->GetxPos() - 1, currentOrb->GetyPos());
			currentOrb->SetxPos(currentOrb->GetxPos() - 1);
		}
	}
	if (!RightKeyFlag && sf::Keyboard::isKeyPressed(RightKey))
	{
		RightKeyFlag = true;
		if (currentOrb->GetxPos() != 5)
		{
			board->SwapOrb(currentOrb->GetxPos(), currentOrb->GetyPos(), currentOrb->GetxPos() + 1, currentOrb->GetyPos());
			currentOrb->SetxPos(currentOrb->GetxPos() + 1);
		}
	}
	if (!UpKeyFlag && sf::Keyboard::isKeyPressed(UpKey))
	{
		UpKeyFlag = true;
		if (currentOrb->GetyPos() != 0)
		{
			board->SwapOrb(currentOrb->GetxPos(), currentOrb->GetyPos(), currentOrb->GetxPos(), currentOrb->GetyPos() - 1);
			currentOrb->SetyPos(currentOrb->GetyPos() - 1);
		}
	}
	if (!DownKeyFlag && sf::Keyboard::isKeyPressed(DownKey))
	{
		DownKeyFlag = true;
		if (currentOrb->GetyPos() != 4)
		{
			board->SwapOrb(currentOrb->GetxPos(), currentOrb->GetyPos(), currentOrb->GetxPos(), currentOrb->GetyPos() + 1);
			currentOrb->SetyPos(currentOrb->GetyPos() + 1);
		}
	}

	
	if (!EnterKeyFlag && sf::Keyboard::isKeyPressed(ConfirmKey)) {
		EnterKeyFlag = true;
		totalScore+= board->Solve();
		scoreUI->SetString(std::to_string(totalScore));

		board->randomizeBoard();
	}
	else if (!(sf::Keyboard::isKeyPressed(ConfirmKey))) EnterKeyFlag = false;

	GetEntity()->SetPos(currentOrb->GetPos());

	if (!(sf::Keyboard::isKeyPressed(LeftKey))) LeftKeyFlag = false;
	if (!(sf::Keyboard::isKeyPressed(RightKey))) RightKeyFlag = false;
	if (!(sf::Keyboard::isKeyPressed(UpKey))) UpKeyFlag = false;
	if (!(sf::Keyboard::isKeyPressed(DownKey))) DownKeyFlag = false;

}

void Game::BoardControl::setCurrentOrb(OrbEntity* newOrb)
{
	currentOrb = newOrb;
} 
