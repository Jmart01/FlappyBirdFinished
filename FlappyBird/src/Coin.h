#pragma once
#include "Entity.h"
#include "CollisionComp.h"
#include "MovementComp.h"
class Coin : public ty::Entity
{
public:
	Coin(class ty::Level* level);
	virtual void OnCollisionEnter(class ty::Entity* entity) override;
private:
	ty::CollisionComp* m_CollisionComp;
	ty::MovementComp* m_MovementComp;
};