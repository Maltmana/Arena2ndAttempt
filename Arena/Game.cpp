#include "stdafx.h"
#include "Game.h"
#include "ray.h"



Game::Game()
{
	create_world();
	load_graphics();
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
	for (auto & graphic : m_graphicContainer.getGraphics())
	{
		ray::Rectangle sourceRec = { 0, 0, (float)graphic->m_spriteWidth, (float)graphic->m_spriteHeight };


		// NOTE: Destination rectangle (screen rectangle where drawing part of texture)
		ray::Rectangle destRec = { 100,100, (float)graphic->m_spriteWidth, (float)graphic->m_spriteHeight };
		// NOTE: Origin of the texture (rotation/scale point), it's relative to destination rectangle size
		ray::Vector2 origin = { 0,0 };
		ray::DrawTexturePro(graphic.get()->m_texture, sourceRec, destRec, { 0.0,0.0 }, 0.0, WHITE);
	}
	ray::EndDrawing();
}

void Game::create_world()
{
}

void Game::load_graphics()
{
	m_graphicContainer.getGraphics().emplace_back(std::make_unique<Graphic>(GraphicType::EdgeLord, "assets/EdgeLord.png", 16, 18));
}