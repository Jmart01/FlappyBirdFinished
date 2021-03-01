#pragma once
#include "MovementComp.h"

namespace ty {
	class TYRANT_API PhysicsMovementComp : public MovementComp
	{
	public:
		PhysicsMovementComp(class Entity* entity) :MovementComp(entity) {}
		virtual void TickComp(float DeltaTime) override;
	private:
		float m_Gravity = 980.f;
	};
}



//need m_Gravity = 980.f;
//vel.x += m_gr * deltatime;

//hw define physics component so that the bird will be falling down like it would in real life