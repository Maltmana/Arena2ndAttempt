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
		if ((m_world.m_mask[entity] & CompMask::Position) == CompMask::Position)
		{
			for (auto & graphic : m_graphicContainer.getGraphics())
			{
				ray::Rectangle sourceRec = { 0, 0, (float)graphic->m_spriteWidth, (float)graphic->m_spriteHeight };


				// NOTE: Destination rectangle (screen rectangle where drawing part of texture)
				ray::Rectangle destRec = { m_world.m_position[entity].x ,m_world.m_position[entity].y, (float)graphic->m_spriteWidth, (float)graphic->m_spriteHeight };
				// NOTE: Origin of the texture (rotation/scale point), it's relative to destination rectangle size
				ray::Vector2 origin = { 0,0 };
				ray::DrawTexturePro(graphic.get()->m_texture, sourceRec, destRec, { 0.0,0.0 }, 0.0, WHITE);
			}
		}
	}
}
