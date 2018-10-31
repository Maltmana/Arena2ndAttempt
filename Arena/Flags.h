#pragma once

#define ENABLE_BITMASK_OPERATORS(x) template<> struct EnableBitMaskOperators<x>{  static const bool enable = true;};

template<typename Enum> // enable if
struct EnableBitMaskOperators
{
	static const bool enable = false;
};

// implement bitwise operators for enum class.
template<typename Enum>
typename std::enable_if<EnableBitMaskOperators<Enum>::enable, Enum>::type operator |(Enum lhs, Enum rhs) // enable if
{
	static_assert(std::is_enum<Enum>::value, "template parameter is not an enum type"); // throw if type entered isn't an enum

	using underlying = typename std::underlying_type<Enum>::type; // sugar
	return static_cast<Enum> (static_cast<underlying>(lhs) | static_cast<underlying>(rhs));
}

// implement bitwise operators for enum class.
template<typename Enum>
typename std::enable_if<EnableBitMaskOperators<Enum>::enable, Enum>::type operator &(Enum lhs, Enum rhs) // enable if
{
	static_assert(std::is_enum<Enum>::value, "template parameter is not an enum type"); // throw if type entered isn't an enum

	using underlying = typename std::underlying_type<Enum>::type; // sugar
	return static_cast<Enum> (static_cast<underlying>(lhs) & static_cast<underlying>(rhs));
}

const enum class CompMask
{
	NONE = 0,
	Position = 1 << 0,
	Velocity = 1 << 1,
	Appearance = 1 << 2,
	Combat = 1 << 3
};
ENABLE_BITMASK_OPERATORS(CompMask);

const enum class SysMask
{
	None = 0,
	Graphics = (int)CompMask::Position | (int)CompMask::Appearance
};
ENABLE_BITMASK_OPERATORS(SysMask);