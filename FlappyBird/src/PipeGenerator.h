#pragma once
#include "Entity.h"

class PipeGenerator : public ty::Entity {
public:
	PipeGenerator(class ty::Level* level);
	virtual void Tick(float DeltaTime) override;
private:
	void SpawnPipes();

private:
	float m_SpawnInterval;
	sf::Clock m_SpawnIntervalTimer;
};