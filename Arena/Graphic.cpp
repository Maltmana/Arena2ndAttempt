#include "stdafx.h"
#include "Graphic.h"

Graphic::Graphic(GraphicType p_graphicType, const char * p_path, int p_spriteWidth, int p_spriteHeight)
	:
	m_graphicType{ p_graphicType },
	m_texture{ ray::LoadTexture(p_path) },
	m_spriteWidth{ p_spriteWidth },
	m_spriteHeight{ p_spriteHeight },
	m_nSpriteCol{ m_texture.width / p_spriteWidth },
	m_nSpriteRow {m_texture.height / p_spriteHeight}
{
}

Graphic::~Graphic()
{
	UnloadTexture(m_texture);
}
