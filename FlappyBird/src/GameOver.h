#pragma once
#include "Level.h"
#include <iostream>
class GameOver : public ty::Level
{
public:
	GameOver(class ty::Application* app);
	virtual void Tick(float DeltaTime) override;
	virtual void DrawBackground() override;
private:
	sf::Sprite m_GameOverTitle;
	sf::Sprite m_GameOverBody;
	sf::Text m_scoreText;
	sf::Font m_scoreFont;
	sf::Text m_HiscoreText;
};