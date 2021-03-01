#pragma once
#include "Entity.h"
#include "MovementComp.h"
#include "CollisionComp.h"
class Pipe : public ty::Entity {
public:
	Pipe(class ty::Level* level);
	
	virtual void Tick(float DeltaTime) override;
private:
	ty::CollisionComp* m_CollisionComp;
	ty::MovementComp* MovementComp;
};