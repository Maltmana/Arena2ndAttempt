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
	m_graphicContainer.getGraphics().emplace_back(std::make_unique<Graphic>(Sprite::EdgeLord, "assets/EdgeLord.png", 16, 18));
}

void Game::create_test_objects()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			unsigned int entity = m_world.get_empty();
			m_world.give_position(entity, i * 35, j * 35);
			m_world.give_sprite(entity, Sprite::EdgeLord);
		}

	}

}
