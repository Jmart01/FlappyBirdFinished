#pragma once
#include "TyrantCore.h"
namespace ty {
	//pure virtual class meaning it is abstract, you cannot create an instance of a pure virtual class.
	class TYRANT_API EntityComponent {
	public:
		EntityComponent(class Entity* entity): m_Entity(entity){}
		//pure virtual, as long as you have 1 in your code then it make that whole class a pure virtual class
		virtual void TickComp(float DeltaTime) = 0;
		class Entity* GetEntity() { return m_Entity; }

	private:
		class Entity* m_Entity;
	};
}