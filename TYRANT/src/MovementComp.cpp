#include "MovementComp.h"
#include "Entity.h"
#include "PhysicsMovementComp.h"
void ty::MovementComp::TickComp(float DeltaTime)
{
	GetEntity()->Move(GetVel()*DeltaTime);
}
