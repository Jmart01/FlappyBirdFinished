#pragma once
#include "PlayBtn.h"
#include "FlappyBirdApp.h"
#include "MainGameLevel.h"
#include <iostream>

PlayBtn::PlayBtn(ty::Level* level)
	:Entity(level)
{
}

void PlayBtn::HandleInput()
{
	GetApp()->ResetScore();
	GetApp()->LoadLevel(new MainGameLevel(GetApp()));
}
