#include "stdafx.h"
#include "Game.h"
#include "ray.h"
#include "Flags.h"



Game::Game()
	:
	m_drawingSystem{m_world,m_graphicContainer}
{
	load_graphics();
	create_test_objects();
}

Game::~Game()
{
}

void Game::loop()
{
	while (!ray::WindowShouldClose())
	{
		update();
		draw();
	}
}

void Game::update()
{
}

void Game::draw()
{
	ray::BeginDrawing();
	ray::ClearBackground(RAYWHITE);
	m_drawingSystem.Draw();
	ray::EndDrawing();
}

void Game::load_graphics()
{
	m_graphicContainer.getGraphics().emplace_back(std::make_unique<Graphic>(GraphicType::EdgeLord, "assets/EdgeLord.png", 16, 18));
}

void Game::create_test_objects()
{
	unsigned int entity = m_world.get_empty();
	m_world.give_position(entity, 100, 400);

	entity = m_world.get_empty();
	m_world.m_mask[entity] = CompMask::Position;
	m_world.m_position[entity].x = 400.f;
	m_world.m_position[entity].y = 400.f;

}
