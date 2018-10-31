#include "stdafx.h"
#include "Window.h"
#include "ray.h"
int Window::screenHeight = 800;
int Window::screenWidth = 1000;

Window::Window()
{
	ray::InitWindow(screenWidth, screenHeight, "ARENA");
	ray::SetTargetFPS(60);
}

Window::~Window()
{
	ray::CloseWindow();
}