// Ravinder Mangat - BoardEntity.h
// Purpose to create physical board to hold tiles
#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "OrbEntity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

// Creating board class

namespace Game
{
	class OrbEntity;

	class BoardEntity : public GameEngine::Entity
	{
	public: 
		BoardEntity();
		~BoardEntity();

		virtual void OnAddToWorld() override;

		void initBoardPos();

		OrbEntity* GetFirstOrb();

		std::vector<std::vector<OrbEntity*>> GetTiles();

	protected:
		OrbEntity* orb;
		std::vector<std::vector<OrbEntity*>> tiles;
		sf::Vector2f tilesPos[6][5];

		GameEngine::SpriteRenderComponent* m_renderComponent;
	};
}