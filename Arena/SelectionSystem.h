#pragma once
#include "ray.h"
class World;
class SelectionSystem
{
public:
	SelectionSystem(World& p_world);
	~SelectionSystem();
public:
	void update();
private:
	World & m_world;
private:
	float m_mouseX;
	float m_mouseY;
	float m_mouseDownX;
	float m_mouseDownY;
	ray::Rectangle m_selectionRect{ 0,0,0,0 };

};

