#pragma once
// std
// lib
#include "ray.h"
// non-system
#include "stdafx.h"
#include "GraphicType.h"
// system

/* Holds loaded texture with data connected to that texture. */
class Graphic
{
public:
	Graphic(GraphicType p_graphicType, const char * p_path, int p_spriteWidth, int p_spriteHeight);
	~Graphic();
public:
private:
public:
	// objects
	ray::Texture2D const m_texture;
	// primitives 
	GraphicType m_graphicType;
	int const m_spriteWidth;
	int const m_spriteHeight;
	int const m_nSpriteCol;
	int const m_nSpriteRow;
private:
};