#pragma once
#include "World.h"
class VelocitySystem
{
public:
	VelocitySystem(World & p_world);
	~VelocitySystem();
public:
	void update();
private:
public:
private:
	World & m_world;
};

