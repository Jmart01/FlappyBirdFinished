#pragma once
#include <TyrantCore.h>
#include "Application.h"
#include <memory>
#include <vector>
namespace ty
{
	class TYRANT_API Level
	{
	public:
		Level(class Application* App);
		class Application* GetApp() { return m_App; };

		//game loop
		virtual void BeginPlay();
		virtual void Tick(float DeltaTime);
		virtual void Draw();
		virtual void DrawBackground();
		virtual void DrawEntities();
		virtual void DrawForeground();
		virtual void HandleInput();

		void SetBackGround(const std::string& name);
		sf::Sprite& GetBackGround() { return m_BackGround; };
		
		
		const class Application* GetApp() const { return m_App; }

		sf::RenderWindow* GetWindow()const { return m_App->GetWindow(); }
		sf::RenderWindow* GetWindow() { return m_App->GetWindow(); }
		//asset managing
		sf::Texture& LoadTexture(const std::string& name);

		void AddEntity(const std::shared_ptr<class Entity>& NewEntity) { m_Entities.push_back(NewEntity); }
		void AddPendingKillEntity(class Entity* entity) { m_PendingDestoryEntities.push_back(entity); }
		std::vector<std::shared_ptr<class Entity>>& GetEntities() { return m_Entities; }
	private:
		void DestroyPendingKillEntities();


	private:
		class Application* m_App;
		sf::Sprite m_BackGround;
		std::map<std::string, sf::Texture> m_TextureAssets;
		std::vector<std::shared_ptr<class Entity>> m_Entities;
		std::vector<class Entity*> m_PendingDestoryEntities;
	};
}
//share ptr structure
//m_ptr* = rawPtr
//int refCount = 1
//another share ptr
//int refCount++


//when share ptr out of scope
// int refCount--

//whenever refCount = 0
//delete m_ptr
