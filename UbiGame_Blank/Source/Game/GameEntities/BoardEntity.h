// Ravinder Mangat - BoardEntity.h
// Purpose to create physical board to hold tiles
#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "OrbEntity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "Game/GameBoard.h"

// Creating board class

namespace Game
{
	class OrbEntity;

	class BoardEntity : public GameEngine::Entity
	{
	public: 
		BoardEntity();
		BoardEntity(sf::Vector2f position, GameBoard* gb);
		~BoardEntity();

		virtual void OnAddToWorld() override;

		void initBoardPos();

		void SwapOrb(int x1, int y1, int x2, int y2);

		void Solve();

		OrbEntity* GetFirstOrb();

		std::vector<std::vector<OrbEntity*>> GetTiles();

		int randomizeId();
        GameBoard* gameBoard;

	protected:
		OrbEntity* orb;
		std::vector<std::vector<OrbEntity*>> tiles;
		sf::Vector2f tilesPos[6][5];

		GameEngine::SpriteRenderComponent* m_renderComponent;
	};
}