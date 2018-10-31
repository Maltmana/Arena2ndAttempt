#include "stdafx.h"
#include "Game.h"
#include "ray.h"
#include "Flags.h"



Game::Game()
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

	unsigned int entity;
	for (entity = 0; entity < ENTITY_COUNT; ++entity)
	{
		if ((m_world.m_mask[entity] & CompMask::POSITION) == CompMask::POSITION)
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


	ray::EndDrawing();
}

void Game::load_graphics()
{
	m_graphicContainer.getGraphics().emplace_back(std::make_unique<Graphic>(GraphicType::EdgeLord, "assets/EdgeLord.png", 16, 18));
}

void Game::create_test_objects()
{
	unsigned int entity = m_world.get_empty();
	m_world.m_mask[entity] = CompMask::POSITION;
	m_world.m_position[entity].x = 400.f;
	m_world.m_position[entity].y = 100.f;

	entity = m_world.get_empty();
	m_world.m_mask[entity] = CompMask::POSITION;
	m_world.m_position[entity].x = 400.f;
	m_world.m_position[entity].y = 400.f;

}
