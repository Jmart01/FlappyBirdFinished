#include "D:/FlappyBird-main/CMakeFiles/FlappyBird.dir/Debug/cmake_pch.hxx"
#include "PipeGenerator.h"
#include "Level.h"
#include "Pipe.h"
#include <random>
#include "Coin.h"
#include <ctime>
#include <iostream>

PipeGenerator::PipeGenerator(ty::Level* level)
	:Entity(level),m_SpawnInterval(2.f), m_SpawnIntervalTimer()
{
	SetVisibility(false);
	srand(time(nullptr));
}

void PipeGenerator::Tick(float DeltaTime)
{
	Entity::Tick(DeltaTime);
	if (m_SpawnIntervalTimer.getElapsedTime().asSeconds() >= m_SpawnInterval)
	{
		m_SpawnIntervalTimer.restart();
		SpawnPipes();
		m_SpawnInterval = (3+ rand() % (6 - 3))*2;
	}
}

void PipeGenerator::SpawnPipes()
{
	//spawn 2 pipes
	std::shared_ptr<Pipe> TopPipe(new Pipe(GetLevel()));
	std::shared_ptr<Pipe> BtmPipe(new Pipe(GetLevel()));
	std::shared_ptr<Coin> Coin(new Coin(GetLevel()));
	//move to reasonable location
	//add to level
	float PosX = GetWindowWidth();
	TopPipe->SetRotation(180.f);
	float TopPosY = 200 + rand() % (300 - 100);
	TopPipe->SetPos(PosX + TopPipe->GetBounds().width,TopPosY);
	float Gap = 200+ rand()% (600 - 100);
	BtmPipe->SetPos(PosX, TopPipe->GetPositionY() + Gap);
	Coin->SetPos(PosX, Gap);

	GetLevel()->AddEntity(TopPipe);
	GetLevel()->AddEntity(Coin);
	GetLevel()->AddEntity(BtmPipe);
}
