#pragma once

enum class Direction
{
	None,
	Up,
	Down,
	Left,
	Right
};

inline std::string toString(Direction direction) 
{
    switch (direction) 
    {
    case Direction::None: return "None";
    case Direction::Up: return "Up";
    case Direction::Down: return "Down";
    case Direction::Left: return "Left";
    case Direction::Right: return "Right";
    default: return "Unknown";
    }
}