#include "TextUI.h"


Game::TextUI::TextUI(std::string text)
{
	textComponent = AddComponent<GameEngine::TextRenderComponent>();
	textComponent->SetFont("arial.ttf");
	textComponent->SetFillColor(sf::Color::White);
	textComponent->SetZLevel(4);
	textComponent->SetCharacterSizePixels(40);
	textComponent->SetString(text);
}

Game::TextUI::~TextUI()
{
}

void Game::TextUI::SetString(std::string text) {
	textComponent->SetString(text);
}



