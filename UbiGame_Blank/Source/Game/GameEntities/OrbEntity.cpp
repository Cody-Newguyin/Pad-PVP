#include "OrbEntity.h"

Game::OrbEntity::OrbEntity()
{
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetZLevel(2);
	this->SetPos(sf::Vector2f(100.f, 100.f));
	this->SetId(1);
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

void Game::OrbEntity::setTexture() {
	if (this->GetId() == 1) {
		m_renderComponent->SetTexture(GameEngine::eTexture::Orb_1);
	}
	else if (this->GetId() == 2) {
		m_renderComponent->SetTexture(GameEngine::eTexture::Orb_2);
	}
	else if (this->GetId() == 3) {
		m_renderComponent->SetTexture(GameEngine::eTexture::Orb_3);
	} 
	else if (this->GetId() == 4 ){
		m_renderComponent->SetTexture(GameEngine::eTexture::Orb_4);
	}
	else if (this->GetId() == 5) {
		m_renderComponent->SetTexture(GameEngine::eTexture::Orb_5);
	} 
	else {
		m_renderComponent->SetTexture(GameEngine::eTexture::Orb_6);
	}
}
