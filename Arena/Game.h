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
	void create_test_objects();
public:
private:
	GraphicContainer m_graphicContainer;
	World m_world;
};

//_TO_PREVENT_A_THIRD_ATTEMPT:
// dont add new stuff until the old stuff is clean and perfect and modeled and understood! and DECOUPLED!!
// always be able to remove code easily and still continue. with just a few comment outs. decoupling is for your brain not for the compiler
// stick to 100 lines per class
// NEXT_TO_DO
// make 2 characters with different positions and draw both.