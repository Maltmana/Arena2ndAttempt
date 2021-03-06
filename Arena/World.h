#pragma once
#include "Vec2.h"
#include "Flags.h"
#include "Sprite.h"

#define ENTITY_COUNT 1000

// contains all game data in contiguous memory ordered by component and some functions to manage it.
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
	void give_velocity(unsigned int entity, float x = 0, float y = 0);
	void toggle_selectable(unsigned int entity);
private:
public:
	// components
	unsigned int m_mask[ENTITY_COUNT];
	Vec2<float> m_position[ENTITY_COUNT];
	Vec2<float> m_velocity[ENTITY_COUNT];
	Sprite m_sprite[ENTITY_COUNT];
	bool m_selected[ENTITY_COUNT]; // TODO turn this into bit field save space.
	//Combat combat[ENTITY_COUNT];
private:
};

