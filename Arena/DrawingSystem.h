#pragma once

class World;
class GraphicContainer;
class DrawingSystem
{
public:
	DrawingSystem(World & p_world, GraphicContainer& p_graphicContainer);
	void Draw();
	// NO DATA, JUST A REFERENCE TO WORLD
private:
	World& m_world;
	GraphicContainer& m_graphicContainer;
};

