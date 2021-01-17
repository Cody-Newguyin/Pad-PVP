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


	if (!lastState) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			lastState = true;
			if (currentOrb->GetxPos() != 0)
			{
				board->SwapOrb(currentOrb->GetxPos(), currentOrb->GetyPos(), currentOrb->GetxPos() - 1, currentOrb->GetyPos());
				currentOrb->SetxPos(currentOrb->GetxPos() - 1);
			}
			std::cout << "Left" << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			lastState = true;
			if (currentOrb->GetxPos() != 5)
			{
				board->SwapOrb(currentOrb->GetxPos(), currentOrb->GetyPos(), currentOrb->GetxPos() + 1, currentOrb->GetyPos());
				currentOrb->SetxPos(currentOrb->GetxPos() + 1);
			}
			std::cout << "Right" << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			lastState = true;
			if (currentOrb->GetyPos() != 0)
			{
				board->SwapOrb(currentOrb->GetxPos(), currentOrb->GetyPos(), currentOrb->GetxPos(), currentOrb->GetyPos() - 1);
				currentOrb->SetyPos(currentOrb->GetyPos() - 1);
			}
			std::cout << "Up" << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			lastState = true;
			if (currentOrb->GetyPos() != 4)
			{
				board->SwapOrb(currentOrb->GetxPos(), currentOrb->GetyPos(), currentOrb->GetxPos(), currentOrb->GetyPos() + 1);
				currentOrb->SetyPos(currentOrb->GetyPos() + 1);
			}
			std::cout << "Down" << std::endl;
		}
		GetEntity()->SetPos(currentOrb->GetPos());
	}
	else if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Down))) {
			lastState = false;
	};

}

void Game::BoardControl::setCurrentOrb(OrbEntity* newOrb)
{
	currentOrb = newOrb;
}
