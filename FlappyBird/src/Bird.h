#pragma once
#include "Entity.h"
#include "PhysicsMovementComp.h"
#include "CollisionComp.h"
class Bird : public ty::Entity
{
public:
	Bird(class ty::Level* level);
	virtual void HandleInput() override;
	virtual void OnCollisionEnter(class ty::Entity* OtherEntity) override;
private:
	ty::PhysicsMovementComp* PhysicsComp;
	ty::CollisionComp* m_CollisionComp;
};