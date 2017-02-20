
/******************************************************************************
** Project Group: Group 6
** Author: Aaron Johnson
** Date: 19 Feb 2017
** Filename: tool.cpp
** Description: Implementation file for the Tool class. It contains default
				behavior that will be inherited by classes derived from Tool.
******************************************************************************/
#include "tool.hpp"

//Default constructor
Tool::Tool()
{
	this->strength = 1;
}

//Parameterized constructor
Tool::Tool(int strength)
{
	this->strength = strength;
}

//Destructor
Tool::~Tool()
{
}

void Tool::setStrength(int strength)
{
	this->strength = strength;
}

int Tool::getStrength() const
{
		return this->strength;
}

char Tool::getType() const
{
		return this->type;
}
