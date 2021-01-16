#include "OrbEntity.h"

Game::OrbEntity::OrbEntity()
{
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::Orb_1);
	m_renderComponent->SetZLevel(2);
	this->SetPos(sf::Vector2f(100.f, 100.f));

	Id = 1;
	//this->SetSize(sf::Vector2f(30.f, 30.f));
}

Game::OrbEntity::~OrbEntity()
{
}

int Game::OrbEntity::GetId()
{
	return Id;
}

void Game::OrbEntity::SetId(int newId)
{
	Id = newId;
}
