#include "tool.hpp"

Tool::Tool()
{
	this->strength = 1;
}

Tool::Tool(int strength)
{
	this->strength = strength;
}

Tool::~Tool()
{
}

void Tool::setStrength(int strength)
{
	this->strength = strength;
}