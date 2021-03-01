#include "Entity.h"
#include "EntityComponent.h"
namespace ty {
	Entity::~Entity()
	{
		std::cout << "Entity Destroy" << std::endl;
	}
	void ty::Entity::SetVisualTexture(const std::string& Dir)
	{
		m_Visual.setTexture(LoadTexture(Dir));
	}
	void Entity::HandleInput()
	{

	}
	void Entity::Tick(float DeltaTime)
	{
		TickComponent(DeltaTime);
	}
	void Entity::TickComponent(float DeltaTime)
	{
		for (int i = 0; i < m_Components.size(); ++i)
		{
			m_Components[i]->TickComp(DeltaTime);
		}
	}
	void Entity::SetVisibility(bool Visible)
	{
		if (!Visible)
		{
			m_Visual.setColor(sf::Color::Transparent);
		}
		else
		{
			m_Visual.setColor(sf::Color::White);
		}
		
	}
	void Entity::Destroy()
	{
		GetLevel()->AddPendingKillEntity(this);
	}
	void Entity::OnCollisionEnter(Entity* Other)
	{
	}
}

