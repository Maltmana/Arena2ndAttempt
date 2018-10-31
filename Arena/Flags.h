#pragma once

enum class Component
{
	NONE = 0,
	POSITION = 1 << 0,
	VELOCITY = 1 << 1,
	APPEARANCE = 1 << 2,
	COMBAT = 1 << 3
};