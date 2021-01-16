#include "PlayerEntity.h"
#include "Game/GameComponent/BoardControl.h"

using namespace Game;

PlayerEntity::PlayerEntity(BoardEntity* board)
{
	BoardControlComponent = AddComponent<BoardControl>();
	BoardControlComponent->SetBoard(board);
}


PlayerEntity::~PlayerEntity()
{

}



