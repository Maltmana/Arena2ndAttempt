#pragma once

namespace CompMask{
	enum CompMask : unsigned int
	{
	None = 0,
	Position = 1 << 0,
	Velocity = 1 << 1,
	Sprite = 1 << 2,
	Selectable = 1 << 3,
	Combat = 1 << 4
	};
}

namespace SysMask {
	enum SysMask : unsigned int
	{
	None = 0,
	Drawable = (CompMask::Sprite | CompMask::Position),
	Velocious = (CompMask::Velocity | CompMask::Position),
	Selectable = (CompMask::Selectable | CompMask::Position)
	};
}