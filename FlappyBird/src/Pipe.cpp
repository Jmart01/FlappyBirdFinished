#include "D:/FlappyBird-main/CMakeFiles/FlappyBird.dir/Debug/cmake_pch.hxx"
#include "Pipe.h"

Pipe::Pipe(ty::Level* level)
	:Entity(level)
{
	SetVisualTexture("Pipe.png");
	MovementComp = ConstructComponent<ty::MovementComp>();
	MovementComp->SetVel(sf::Vector2f(-80.f, 0.f));
	m_CollisionComp = ConstructComponent<ty::CollisionComp>();
}

void Pipe::Tick(float DeltaTime)
{
	Entity::Tick(DeltaTime);
	if (GetPositionX() < -GetBounds().width)
	{
		Destroy();
	}
}
