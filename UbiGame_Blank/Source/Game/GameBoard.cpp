#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "Game/GameEntities/OrbEntity.h"
#include "Game/GameEntities/BoardEntity.h"
#include "Game/GameEntities/PlayerEntity.h"

using namespace Game;

GameBoard::GameBoard()
	:board(nullptr)
{
	board = new BoardEntity();
	player = new PlayerEntity(board);

	GameEngine::GameEngineMain::GetInstance()->AddEntity(board);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(player);
	
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}
