#pragma once
#include "Command.h"
#include "ray.h"
#include "World.h"
#include "stdafx.h"

class CommandHandler
{
public:
	CommandHandler(World& p_world);
	void update();
private:
	World & m_world;
	Command * m_spacebar;
};

