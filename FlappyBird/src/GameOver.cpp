#include "GameOver.h"
#include "PlayBtn.h"
#include <string>
//#include 

GameOver::GameOver(ty::Application* app)
	:Level(app)
{
	SetBackGround("background.png");
	m_GameOverBody.setTexture(LoadTexture("GameOverBody.png"));
	m_GameOverTitle.setTexture(LoadTexture("GameOverTitle.png"));

	m_GameOverBody.setPosition(150.f, 150.f);
	m_GameOverTitle.setPosition(75.f, 75.f);

	AddEntity(std::shared_ptr<PlayBtn>(new PlayBtn(this)));
	std::cout << "Score: " << GetApp()->GetScore() << std::endl;
	std::cout << "Highscore: " << GetApp()->GetHighScore() << std::endl;

	m_scoreFont.loadFromFile("Resources/Fonts/Elfboyclassic.tff");
	m_scoreText.setFont(m_scoreFont);
	m_scoreText.setString(std::to_string(GetApp()->GetScore()));
	m_scoreText.setCharacterSize(100);
	m_scoreText.setFillColor(sf::Color::White);
	m_scoreText.setPosition(500, 145);

	m_HiscoreText.setFont(m_scoreFont);
	m_HiscoreText.setString(std::to_string(GetApp()->GetHighScore()));
	m_scoreText.setCharacterSize(100);
	m_scoreText.setFillColor(sf::Color::White);
	m_scoreText.setPosition(500, 250);
}

void GameOver::Tick(float DeltaTime)
{
	Level::Tick(DeltaTime);
}

void GameOver::DrawBackground()
{
	GetApp()->GetWindow()->draw(GetBackGround());
	GetApp()->GetWindow()->draw(m_GameOverBody);
	GetApp()->GetWindow()->draw(m_GameOverTitle);
}
