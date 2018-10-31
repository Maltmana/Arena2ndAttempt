#pragma once
#include "World.h"
#include "GraphicContainer.h"

class Game
{
public:
	Game();
	~Game();
	Game(const Game& other) = delete; // copy constructor
	Game(Game&& other) = delete; // move constructor
	Game & operator=(const Game & other) = delete; // copy assignment
	Game & operator=(Game&& other) noexcept = delete; // move assignment
public:
	void loop();
private:
	void update();
	void draw();
	void create_world();
	void load_graphics();
public:
private:
	GraphicContainer m_graphicContainer;
};

