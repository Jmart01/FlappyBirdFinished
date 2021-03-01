#pragma once
#include "Entity.h"
class PlayBtn : public ty::Entity
{
public:
	PlayBtn(class ty::Level* level);
	virtual void HandleInput() override;
};