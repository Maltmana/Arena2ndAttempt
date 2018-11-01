#pragma once
#include "World.h"
#include "GraphicContainer.h"
#include "RNG.h"
#include "CommandHandler.h"

// Systems
#include "DrawingSystem.h"
#include "VelocitySystem.h"

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
	void load_graphics();
	void create_test_objects();
public:
private:
	// Supers
	CommandHandler m_commandHandler;
	GraphicContainer m_graphicContainer;
	World m_world;
	// Systems
	DrawingSystem m_drawingSystem;
	VelocitySystem m_velocitySystem;
};

//_TO_PREVENT_A_THIRD_ATTEMPT:
// dont add new stuff until the old stuff is clean and perfect and modeled and understood! and DECOUPLED!!
// perfect, understand, move on
// always be able to remove code easily and still continue. with just a few comment outs. decoupling is for your brain not for the compiler
// stick to 100 lines per class
// code so that you can have an item and a building and a dude and an effect... not just creature huge class.
// when refactoring start with the top of the pyramid, those things with least dependencies, then work down. otherwise a stone will fall on your head!
// be able to comment things out and remove them with a single comment out.
// NEXT_TO_DO
// User input so can create a man at a click.