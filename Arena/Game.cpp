#include "stdafx.h"
#include "Game.h"
#include "ray.h"
#include "Flags.h"



Game::Game()
	:
	m_commandHandler{ m_world },
	m_drawingSystem{m_world,m_graphicContainer},
	m_velocitySystem{m_world}
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
	m_commandHandler.update();
	m_velocitySystem.update();
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
	m_graphicContainer.getGraphics().emplace_back(std::make_unique<Graphic>(Sprite::NobleFemale, "assets/NobleFemale.png", 16, 18));
	m_graphicContainer.getGraphics().emplace_back(std::make_unique<Graphic>(Sprite::NobleMale, "assets/NobleMale.png", 16, 18));
	m_graphicContainer.getGraphics().emplace_back(std::make_unique<Graphic>(Sprite::Satyr, "assets/Satyr.png", 16, 18));
}

void Game::create_test_objects()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (j%2)
			{
				unsigned int entity = m_world.get_empty();
				m_world.give_position(entity, i * 35 + 300, j * 35 + 300);
				m_world.give_velocity(entity, -i * 0.1, -j * 0.1);
				m_world.give_sprite(entity, (Sprite)RNG::get_randi(0, 3));
			}
			else
			{
				unsigned int entity = m_world.get_empty();
				m_world.give_position(entity, i * 35 + 300, j * 35 + 300);
				m_world.give_sprite(entity, (Sprite)RNG::get_randi(0, 3));
			}

		}

	}
}
