#include "PlayerEntity.h"

using namespace Game;

PlayerEntity::PlayerEntity()
{

}


PlayerEntity::~PlayerEntity()
{

}

void PlayerEntity::setCurrentOrb(OrbEntity* newOrb)
{
	currentOrb = newOrb;
	currentOrb->SetId(2);
}

