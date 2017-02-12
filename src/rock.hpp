/******************************************************************************
** Project Group: Group 6
** Author: Patick Kilgore
** Date: 10 Feb 2017
** Filename: rock.hpp
** Description: Header file for the Rock class which inherits from the Tool
**              class. This class models the behavior of rock in the Rock
**              Paper Scissors game by having double strength against scissors
**              and half strength against paper.
******************************************************************************/

#include "tool.hpp"

class Rock : public Tool
{
    // default constructor
    Rock();

    // parameterized constructor
    Rock(int strength);

    /**************************************************************************
    * fight(Tool* tool):
    * Adjusts the strengths of this and tool according to RPS logic, makes the
    * strength comparison, and returns whether this rock wins, loses, or draws.
    **************************************************************************/
    Fight fight(Tool* tool);
};
