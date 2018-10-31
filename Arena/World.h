#pragma once
#include "Vec2.h"
#include "Flags.h"
#include "Sprite.h"

#define ENTITY_COUNT 1000

// contains all game data in contiguous memory ordered by component.
class World
{
public:
	World();
	~World();
public:
	// entity functions
	unsigned int get_empty();
	// component functions
	void give_position(unsigned int entity, float x, float y);
	void give_sprite(unsigned int entity, Sprite sprite);
private:
public:
	CompMask m_mask[ENTITY_COUNT];
	Vec2<float> m_position[ENTITY_COUNT];
	//Velocity velocity[ENTITY_COUNT];
	Sprite m_sprite[ENTITY_COUNT];
	//Combat combat[ENTITY_COUNT];
private:
};

