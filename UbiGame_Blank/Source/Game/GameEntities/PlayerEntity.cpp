#include "PlayerEntity.h"

#include <string>
#include "Game/GameComponent/BoardControl.h"
#include "GameEngine/GameEngineMain.h"

using namespace Game;

PlayerEntity::PlayerEntity(BoardEntity* board)
{
	name = new TextUI("Player 1");
	name->SetPos(board->GetPos() + sf::Vector2f(-80, -300));
	score = new TextUI("0");
	score->SetPos(board->GetPos() + sf::Vector2f(-40, -250));

	GameEngine::GameEngineMain::GetInstance()->AddEntity(name);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(score);

	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetZLevel(2);
	m_renderComponent->SetTexture(GameEngine::eTexture::Overlay);

	this->SetPos(sf::Vector2f(75.f,75.f));

	BoardControlComponent = AddComponent<BoardControl>();
	BoardControlComponent->SetBoard(board);
	BoardControlComponent->SetScoreUI(score);
}


PlayerEntity::~PlayerEntity()
{

}

void PlayerEntity::SetKeys(sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key down, sf::Keyboard::Key up, sf::Keyboard::Key confirm) {
	BoardControlComponent->SetKeys(left, right, down, up, confirm);
}


