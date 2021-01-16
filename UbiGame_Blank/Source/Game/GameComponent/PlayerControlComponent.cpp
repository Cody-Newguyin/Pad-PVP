#include "PlayerControlComponent.h"

#include "GameEngine/GameEngineMain.h"

#include <SFML/Window/Keyboard.hpp>

using namespace Game;

PlayerControlComponent::PlayerControlComponent()
{

}


PlayerControlComponent::~PlayerControlComponent()
{

}


void PlayerControlComponent::Update()
{
	Component::Update();

	if (GameEngine::GameEngineMain::GetInstance()->IsGameOver())
	{
		return;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{

	}

}