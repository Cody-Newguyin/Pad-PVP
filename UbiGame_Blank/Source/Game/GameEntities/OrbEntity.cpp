#include "OrbEntity.h"

Game::OrbEntity::OrbEntity()
{
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetZLevel(2);
	this->SetPos(sf::Vector2f(100.f, 100.f));
	this->SetId(1);
	this->SetTexture();
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
	this->SetTexture();
}

void Game::OrbEntity::SetTexture() {
	switch (Id) {
	case (1):
		m_renderComponent->SetTexture(GameEngine::eTexture::Orb_1);
		break;
	case (2):
		m_renderComponent->SetTexture(GameEngine::eTexture::Orb_2);
		break;
	}
}
