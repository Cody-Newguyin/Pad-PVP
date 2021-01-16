#pragma once

#include "GameEngine/EntitySystem/Entity.h"
#include "OrbEntity.h"

namespace Game
{
	class PlayerEntity : public GameEngine::Entity
	{
	public:
		PlayerEntity();
		~PlayerEntity();

		void setCurrentOrb(OrbEntity* newOrb);
	protected:
		OrbEntity* currentOrb;

	};
}


