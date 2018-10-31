#pragma once

#define ENTITY_COUNT 300

// contains all game data in contiguous memory ordered by component.
class World
{
public:
	World();
	~World();
public:
private:
public:
	int mask[ENTITY_COUNT];
	//Position position [ENTITY_COUNT];
	//Velocity velocity[ENTITY_COUNT];
	//Appearance appearance[ENTITY_COUNT];
	//Combat combat[ENTITY_COUNT];
private:
};

