/******************************************************************************
** Project Group: Group 6
** Author: Aaron Johnson
** Date: 19 Feb 2017
** Filename: tool.hpp
** Description: Header file for the Tool class. The tool class contains
				the the parent behavior for tools. It contains the parent tool
				class that can be used to make a rock, paper, scissors game.
				This is a pure abstract class and cannot be instantiated 
				on its own.
******************************************************************************/
#ifndef TOOL_HPP
#define TOOL_HPP

enum Fight {WIN, LOSE, DRAW};

class Tool
{
protected:
	int strength;
	char type;

public:
	Tool();
	Tool(int strength);
	virtual ~Tool();
	void setStrength(int strength);
	int getStrength() const;
	char getType() const;
	virtual Fight fight(Tool *tool) = 0; //pure abstract function. Cannot instantiate tools by themselves.
};
#endif
