#pragma once

namespace CompMask{
	enum CompMask
	{
	None = 0,
	Position = 1 << 0,
	Velocity = 1 << 1,
	Sprite = 1 << 2,
	Combat = 1 << 3
	};
}

namespace SysMask {
	enum SysMask
	{
	None = 0,
	Drawable = (CompMask::Sprite | CompMask::Position)
	};
}