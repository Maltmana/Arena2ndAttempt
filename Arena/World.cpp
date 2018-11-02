#include "stdafx.h"
#include "World.h"


World::World()
{
}


World::~World()
{
}

unsigned int World::get_empty()
{
	unsigned int entity;
	for (entity = 0; entity < ENTITY_COUNT; ++entity)
	{
		if (m_mask[entity] == CompMask::None)
		{
			return(entity);
		}
	}
	printf("Error!  No more entities left!\n");
	return(ENTITY_COUNT);
}

void World::give_position(unsigned int entity, float x, float y)
{
	m_position[entity].x = { x };
	m_position[entity].y = { y };
	m_mask[entity] |= CompMask::Position;
}

void World::give_velocity(unsigned int entity, float x, float y)
{
	assert((m_mask[entity] & CompMask::Position) == CompMask::Position);
	m_velocity[entity].x = { x };
	m_velocity[entity].y = { y };
	m_mask[entity] |= CompMask::Velocity;

}

void World::toggle_selectable(unsigned int entity)
{
	assert((m_mask[entity] & CompMask::Position) == CompMask::Position);
	m_selected[entity] = false;
	m_mask[entity] |= CompMask::Selectable;
}

void World::give_sprite(unsigned int entity, Sprite sprite)
{
	assert((m_mask[entity] & CompMask::Position) == CompMask::Position);
	m_sprite[entity]={ sprite };
	m_mask[entity] |= CompMask::Sprite;
}
