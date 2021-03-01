#include "Coin.h"
#include "Bird.h"
#include <iostream>

Coin::Coin(ty::Level* level)
	:Entity(level)
{
	SetVisualTexture("PlatinumMedal.PNG");
	m_MovementComp = ConstructComponent<ty::MovementComp>();
	m_MovementComp->SetVel(sf::Vector2f(-80.f, 0.f));

	m_CollisionComp = ConstructComponent<ty::CollisionComp>();
}

void Coin::OnCollisionEnter(ty::Entity* OtherEntity)
{

}
