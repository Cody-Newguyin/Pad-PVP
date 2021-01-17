#include "BoardControl.h"

#include <iostream>
#include "Game/GameEntities/BoardEntity.h"
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


void Game::BoardControl::Update()
{
	Component::Update();

	if (GameEngine::GameEngineMain::GetInstance()->IsGameOver())
	{
		return;
	}


	if (!LeftKeyFlag && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		LeftKeyFlag = true;
		if (currentOrb->GetxPos() != 0)
		{
			board->SwapOrb(currentOrb->GetxPos(), currentOrb->GetyPos(), currentOrb->GetxPos() - 1, currentOrb->GetyPos());
			currentOrb->SetxPos(currentOrb->GetxPos() - 1);
		}
		std::cout << "Left" << std::endl;
	}
	if (!RightKeyFlag && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		RightKeyFlag = true;
		if (currentOrb->GetxPos() != 5)
		{
			board->SwapOrb(currentOrb->GetxPos(), currentOrb->GetyPos(), currentOrb->GetxPos() + 1, currentOrb->GetyPos());
			currentOrb->SetxPos(currentOrb->GetxPos() + 1);
		}
		std::cout << "Right" << std::endl;
	}
	if (!UpKeyFlag && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		UpKeyFlag = true;
		if (currentOrb->GetyPos() != 0)
		{
			board->SwapOrb(currentOrb->GetxPos(), currentOrb->GetyPos(), currentOrb->GetxPos(), currentOrb->GetyPos() - 1);
			currentOrb->SetyPos(currentOrb->GetyPos() - 1);
		}
		std::cout << "Up" << std::endl;
	}
	if (!DownKeyFlag && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		DownKeyFlag = true;
		if (currentOrb->GetyPos() != 4)
		{
			board->SwapOrb(currentOrb->GetxPos(), currentOrb->GetyPos(), currentOrb->GetxPos(), currentOrb->GetyPos() + 1);
			currentOrb->SetyPos(currentOrb->GetyPos() + 1);
		}
		std::cout << "Down" << std::endl;
	}
	GetEntity()->SetPos(currentOrb->GetPos());

	if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))) LeftKeyFlag = false;
	if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))) RightKeyFlag = false;
	if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) UpKeyFlag = false;
	if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))) DownKeyFlag = false;

}

void Game::BoardControl::setCurrentOrb(OrbEntity* newOrb)
{
	currentOrb = newOrb;
}
