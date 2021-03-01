#pragma once
#include "TyrantCore.h"
#include "GameObject.h"
namespace ty {
	class TYRANT_API Entity : public GameObject {
	public:
		Entity(class Level* level) : GameObject(level) {};
		virtual ~Entity();

		void SetVisualTexture(const std::string& Dir);

		virtual void HandleInput();
		
		void SetPos(const sf::Vector2f& Pos) { m_Visual.setPosition(Pos); }
		void SetPos(float PosX, float PosY) { m_Visual.setPosition(PosX, PosY); }
		void SetPosX(float PosX) { m_Visual.setPosition(PosX, m_Visual.getPosition().y); }
		void SetPosY(float PosY) {m_Visual.setPosition(m_Visual.getPosition().x,PosY); }
		const sf::Vector2f& GetPosition()const { return m_Visual.getPosition(); }
		float GetPositionX()const { return m_Visual.getPosition().x; }
		float GetPositionY()const { return m_Visual.getPosition().y; }

		sf::FloatRect GetBounds()const { return m_Visual.getGlobalBounds(); }
		float GetWidth() {return GetBounds().width; }
		float GetHeight() {return GetBounds().height; }

		void Move(const sf::Vector2f& Amt) { m_Visual.move(Amt); }
		void MoveX(float amount) { m_Visual.move(sf::Vector2f(amount, 0.f)); }
		void MoveY(float amount) { m_Visual.move(sf::Vector2f(0.f, amount)); }

		void SetPivot(const sf::Vector2f& pivot) { m_Visual.setOrigin(pivot); }
		const sf::Sprite& GetVisual() const { return m_Visual; }

		template<typename T>
		T* ConstructComponent()
		{
			T* newCompRaw = new T(this);
			std::shared_ptr<T> newComp(newCompRaw);
			m_Components.push_back(newComp);
			return newCompRaw;
		}

		virtual void Tick(float DeltaTime);
		virtual void TickComponent(float DeltaTime);

		void SetVisibility(bool Visible);
		void SetRotation(float RotationVal) { m_Visual.setRotation(RotationVal); }

		virtual void Destroy();

		virtual void OnCollisionEnter(class Entity* Other);
	private:
		sf::Sprite m_Visual;
		std::vector<std::shared_ptr<class EntityComponent>>m_Components;
	};
}