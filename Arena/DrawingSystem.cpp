#include "stdafx.h"
#include "DrawingSystem.h"
#include "World.h"
#include "GraphicContainer.h"

DrawingSystem::DrawingSystem(World & p_world, GraphicContainer& p_graphicContainer)
	:
	m_world{p_world},
	m_graphicContainer{p_graphicContainer}
{
}

void DrawingSystem::Draw()
{
	unsigned int entity;
	for (entity = 0; entity < ENTITY_COUNT; ++entity)
	{
		if ((m_world.m_mask[entity] & (unsigned int)SysMask::Drawable) == SysMask::Drawable)
		{
			for (auto & graphic : m_graphicContainer.getGraphics())
			{
				if (m_world.m_sprite[entity] == graphic->m_sprite)
				{
					ray::Rectangle sourceRec = { 0, 0, (float)graphic->m_spriteWidth, (float)graphic->m_spriteHeight };
					ray::Rectangle destRec = { m_world.m_position[entity].x ,m_world.m_position[entity].y, (float)graphic->m_spriteWidth, (float)graphic->m_spriteHeight };
					ray::Vector2 origin = { 0,0 };
					ray::DrawTexturePro(graphic.get()->m_texture, sourceRec, destRec, { 0.0,0.0 }, 0.0, WHITE);
				}
			}
		}
	}
}
