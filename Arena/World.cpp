#include "stdafx.h"
#include "World.h"


World::World()
{
	for (auto& f : m_position)
	{
		std::cout << &f.x << '\n';
	}
}


World::~World()
{
}
