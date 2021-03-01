#include "Bird.h"
#include <PhysicsMovementComp.h>
#include <type_traits>
#include <typeinfo>
#include "Coin.h"
#include "Pipe.h"
#include "GameOver.h"
Bird::Bird(ty::Level* level)
	:Entity(level)
{
	SetVisualTexture("bird.png");
	SetPos(GetWindowWidth() / 4, GetWindowHeight() / 2);

	PhysicsComp = ConstructComponent<ty::PhysicsMovementComp>();
	m_CollisionComp = ConstructComponent<ty::CollisionComp>();
}

void Bird::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		PhysicsComp->SetVel(sf::Vector2f(PhysicsComp->GetVel().x, -400.f));
	}
}

void Bird::OnCollisionEnter(ty::Entity* OtherEntity)
{
	if (typeid(*OtherEntity) == typeid(Pipe))
	{
		std::cout << "dont worry capin well buff out those scratches" << std::endl;
		GetApp()->LoadLevel(new GameOver(GetApp()));
	}
	if (typeid(*OtherEntity) == typeid(Coin))
	{
		std::cout << "coin obtained" << std::endl;
		GetApp()->AddScore();
		OtherEntity->Destroy();
	}
}
