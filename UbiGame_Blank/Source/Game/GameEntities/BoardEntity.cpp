// Ravinder Mangat - BoardEntity.cpp
// Purpose to create physical board to hold tiles

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BoardEntity.h"
#include "OrbEntity.h"


#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/GameEngineMain.h"
#include <SFML/Graphics.hpp>

using namespace Game;

BoardEntity::BoardEntity(sf::Vector2f position)
	:orb(nullptr)
{

	srand((unsigned)time(0));
	this->SetPos(position);
	initBoardPos();

	for (int i = 0; i < 6; i++) {
		tiles.push_back(std::vector < OrbEntity* >());
		for (int j = 0; j < 5; j++) {
			orb = new OrbEntity();
			GameEngine::GameEngineMain::GetInstance()->AddEntity(orb);
			tiles[i].push_back(orb);
			orb->SetPos(tilesPos[i][j]);
			// Add position attributes to the orb object
			orb->SetxPos(i);
			orb->SetyPos(j);
			orb->SetId(randomizeId());
			orb->SetTexture();
		}
	}

	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::Board_Bg);
	m_renderComponent->SetZLevel(1);
	m_renderComponent->SetTileIndex(0, 0);

	
	this->SetSize(sf::Vector2f(480.f, 405.f));


}

BoardEntity::~BoardEntity() {

}

void BoardEntity::OnAddToWorld() {
	Entity::OnAddToWorld();
}

int BoardEntity::randomizeId() {
	return (rand() % 6) + 1;

}

void BoardEntity::initBoardPos() {
	for (int i = 0; i < 6; i++) {
		int x = (i - 2.5) * 75;
		for (int j = 0; j < 5; j++) {
			int y = (j - 2) * 75;
			tilesPos[i][j] = sf::Vector2f(x,y) + this->GetPos();
		}
	}
}

void BoardEntity::SwapOrb(int x1, int y1, int x2, int y2) {
	OrbEntity* tempOrb = Game::BoardEntity::tiles[x1][y1];
	Game::BoardEntity::tiles[x1][y1] = Game::BoardEntity::tiles[x2][y2];
	Game::BoardEntity::tiles[x1][y1]->SetxPos(x2);
	Game::BoardEntity::tiles[x1][y1]->SetyPos(y2);
	Game::BoardEntity::tiles[x2][y2] = tempOrb;
	Game::BoardEntity::tiles[x2][y2]->SetxPos(x1);
	Game::BoardEntity::tiles[x2][y2]->SetyPos(y1);
	Game::BoardEntity::tiles[x1][y1]->SetPos(sf::Vector2f(tilesPos[x1][y1]));
	Game::BoardEntity::tiles[x2][y2]->SetPos(sf::Vector2f(tilesPos[x2][y2]));
}

void Game::BoardEntity::Solve()
{
	bool isMatchArray[6][5] = { false };
	int comboCount = 0;
	// check vertical matches

	for( int i = 0; i < 3; i++ )
	{
		for( int j = 0; j < 6; j++ )
		{
			int n = i;
			int counter = 0;

			while(n < 5)
			{
				if (Game::BoardEntity::tiles[j][n]->GetId() == Game::BoardEntity::tiles[j][i]->GetId())
				{
					counter++;
				}
				else
				{
					break;
				}
				n++;
			}
			if (counter >= 3)
			{
				bool isCombo = true;
	
				for(int x = 0; x < counter; x++)
				{
					if (isMatchArray[j][i + x])isCombo = false;
					isMatchArray[j][i + x] = true;
				}
				if (isCombo)comboCount++;
			}
		}
	}

	// check horizontal matches

	for( int i = 0; i < 5; i++ )
	{
		for( int j = 0; j < 4; j++ )
		{
			int n = j;
			int counter = 0;

			while(n < 6)
			{
				if (Game::BoardEntity::tiles[n][i]->GetId() == Game::BoardEntity::tiles[j][i]->GetId())
				{
					counter++;
				}
				else
				{
					break;
				}
				n++;
			}
			if (counter >= 3)
			{
				bool isCombo = true;
				for(int x = 0; x < counter; x++)
				{
					if (isMatchArray[j + x][i])isCombo = false;
					isMatchArray[j + x][i] = true;
				}
				if (isCombo)comboCount++;
			}
		}

	}
	int score = 0;
	for( int i = 0; i < 5; i++ )
	{
		for( int j = 0; j < 6; j++ )
		{
			if (isMatchArray[j][i])
			{
				score++;
				Game::BoardEntity::tiles[j][i]->SetId(7);
			}

		}

	}
	std::cout << "Combo: " << comboCount << std::endl;
	std::cout << "Score: " << score << " x " << comboCount << " = " << score * comboCount << std::endl;






}



OrbEntity* BoardEntity::GetFirstOrb() {
	return Game::BoardEntity::tiles[0][0];
}

std::vector<std::vector<OrbEntity*>> BoardEntity::GetTiles() {
	return tiles;
}