#pragma once
#include "TyrantCore.h"
#include "Level.h"
namespace ty {
	class TYRANT_API GameObject
	{
	public:
		GameObject(class Level* level)
			:m_level(level) {};
		

		//getter
		class Level* GetLevel() { return m_level; }
		class Application* GetApp() { return m_level->GetApp(); }
		sf::RenderWindow* GetWindow() { return m_level->GetWindow(); }
		const sf::RenderWindow* GetWindow()const { return m_level->GetWindow(); }
		sf::Vector2f GetWindowSize()const { return sf::Vector2f( GetWindow()->getSize().x, GetWindow()->getSize().y); }
		float GetWindowWidth() const { return GetWindowSize().x; }
		float GetWindowHeight()const { return GetWindowSize().y; }

		const sf::Texture& LoadTexture(const std::string& Dir) {return GetLevel()->LoadTexture(Dir); }

	private:
		class Level* m_level;
	};
}