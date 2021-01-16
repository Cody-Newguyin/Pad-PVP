#include "PlayerEntity.h"

using namespace Game;

PlayerEntity::PlayerEntity()
{
	currentOrb = nullptr;
}


PlayerEntity::~PlayerEntity()
{

}

void PlayerEntity::setCurrentOrb(OrbEntity* newOrb)
{
	currentOrb = newOrb;
	currentOrb->SetId(1);
}

