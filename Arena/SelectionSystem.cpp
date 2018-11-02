#include "stdafx.h"
#include "SelectionSystem.h"
#include "World.h"


SelectionSystem::SelectionSystem(World & p_world)
	:
	m_world{p_world}
{
}

SelectionSystem::~SelectionSystem()
{
}

void SelectionSystem::update()
{
	unsigned int entity;

	m_mouseX = { (float)ray::GetMouseX() };
	m_mouseY = { (float)ray::GetMouseY() };

	if (ray::IsMouseButtonPressed(0))
	{
		m_mouseDownX = m_mouseX;
		m_mouseDownY = m_mouseY;
	}

	// move to different non entity related system
	// set the rect to between mouse curr and mouse down
	if (ray::IsMouseButtonDown(0))
	{
		if (m_mouseX - m_mouseDownX <= 0 && m_mouseY - m_mouseDownY <= 0)
		{
			m_selectionRect = { m_mouseX, m_mouseY, m_mouseDownX - m_mouseX ,m_mouseDownY - m_mouseY };
		}
		else if (m_mouseY - m_mouseDownY <= 0)
		{
			m_selectionRect = { m_mouseDownX, m_mouseY, m_mouseX - m_mouseDownX, m_mouseDownY - m_mouseY };
		}
		else if (m_mouseX - m_mouseDownX <= 0)
		{
			m_selectionRect = { m_mouseX, m_mouseDownY, m_mouseDownX - m_mouseX,m_mouseY - m_mouseDownY };
		}
		else
		{
			m_selectionRect = { m_mouseDownX, m_mouseDownY,m_mouseX - m_mouseDownX,m_mouseY - m_mouseDownY };
		}
	}

	ray::DrawRectangleLinesEx(m_selectionRect, 2, GREEN);

	if (ray::IsMouseButtonReleased(0))
	{
		// move to different non entity related system
		for (entity = 0; entity < ENTITY_COUNT; ++entity)
		{
			if ((m_world.m_mask[entity] & (unsigned int)SysMask::Selectable) == SysMask::Selectable)
			{
				if (ray::CheckCollisionPointRec({ m_world.m_position[entity].x, m_world.m_position[entity].y }, m_selectionRect))
				{
					m_world.m_selected[entity] = true;
				}
				// if collides with mouse box.
				// set selected to  true;
			
				// another system:
				// send commands to those selected

				// deselectionsystem
				// if i click then set all selected to false;
			}
		}
	}
}
