#pragma once
#include "Vec2.h"
#include "Flags.h"

#define ENTITY_COUNT 300

// contains all game data in contiguous memory ordered by component.
class World
{
public:
	World();
	~World();
public:
	unsigned int get_empty()
	{
		unsigned int entity;
		for (entity = 0; entity < ENTITY_COUNT; ++entity)
		{
			if (m_mask[entity] == CompMask::NONE)
			{
				return(entity);
			}
		}
		printf("Error!  No more entities left!\n");
		return(ENTITY_COUNT);
	}
private:
public:
	CompMask m_mask[ENTITY_COUNT];
	Vec2<float> m_position[ENTITY_COUNT];
	//Velocity velocity[ENTITY_COUNT];
	//Appearance appearance[ENTITY_COUNT];
	//Combat combat[ENTITY_COUNT];
private:
};

