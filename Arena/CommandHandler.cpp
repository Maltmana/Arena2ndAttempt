#include "stdafx.h"
#include "CommandHandler.h"

CommandHandler::CommandHandler(World& p_world)
	:
	m_world{p_world},
	m_spacebar {new CreateRandomEntity}
{
}

void CommandHandler::update()
{
	if (ray::IsKeyReleased(KEY_SPACE)) { m_spacebar->execute(m_world); };
}
