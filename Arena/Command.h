#pragma once
#include "RNG.h"
#include "World.h"
#include "Window.h"
#include "ray.h"
class Command
{
public:
	virtual ~Command();
	virtual void execute(World& p_world) = 0;
};

class CreateRandomEntityCommand : public Command
{
public:
	void execute(World& p_world) override
	{ 
		unsigned int entity = p_world.get_empty();
		p_world.give_position(entity, ray::GetMouseX(), ray::GetMouseY());
		p_world.give_velocity(entity);
		p_world.give_sprite(entity, (Sprite)RNG::get_randi(0, 3));
	}
};