#include "stdafx.h"
#include "VelocitySystem.h"
#include "flags.h"

VelocitySystem::VelocitySystem(World & p_world)
	:
	m_world{p_world}
{
}

VelocitySystem::~VelocitySystem()
{
}

void VelocitySystem::update()
{
	unsigned int entity;
	for (entity = 0; entity < ENTITY_COUNT; ++entity)
	{
		if ((m_world.m_mask[entity] & (unsigned int)SysMask::Velocious) == SysMask::Velocious)
		{
			m_world.m_position[entity].x -= m_world.m_velocity[entity].x;
			m_world.m_position[entity].y -= m_world.m_velocity[entity].y;
		}
	}
}
