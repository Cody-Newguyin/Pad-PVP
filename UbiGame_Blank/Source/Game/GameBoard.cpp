#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "Game/GameEntities/OrbEntity.h"
#include "Game/GameEntities/BoardEntity.h"
#include "Game/GameEntities/PlayerEntity.h"

using namespace Game;

GameBoard::GameBoard()
	:board1(nullptr),
	 board2(nullptr)
{
	board1 = new BoardEntity(sf::Vector2f(400.f, 400.f));
	player1 = new PlayerEntity(board1);

	board2 = new BoardEntity(sf::Vector2f(1000.f, 400.f));
	player2 = new PlayerEntity(board2);

	GameEngine::GameEngineMain::GetInstance()->AddEntity(board1);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(player1);

	GameEngine::GameEngineMain::GetInstance()->AddEntity(board2);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(player2);

	player2->SetKeys(sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::Down, sf::Keyboard::Up);
	player1->SetKeys(sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::S, sf::Keyboard::W);
	
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}
