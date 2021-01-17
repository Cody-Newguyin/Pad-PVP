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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		currentOrb->SetId(3);
		std::cout << "LEFT" << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		board->SwapOrb(currentOrb->GetxPos(), currentOrb->GetyPos(), currentOrb->GetxPos() + 1, currentOrb->GetyPos());
		std::cout << "Right" << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		std::cout << "Up" << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		std::cout << "Up" << std::endl;
	}
}

void Game::BoardControl::setCurrentOrb(OrbEntity* newOrb)
{
	currentOrb = newOrb;
}
