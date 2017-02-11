/******************************************************************************
** Project Group: Group 6
** Author: Patick Kilgore
** Date: 10 Feb 2017
** Filename: rock.hpp
** Description: Header file for the Paper class which inherits from the Tool
**              class. This class models the behavior of paper in the Rock
**              Paper Scissors game by having double strength against rock
**              and half strength against scissors.
******************************************************************************/

#include "tool.hpp"

class Paper : public Tool
{
    // default constructor
    Paper();

    // parameterized constructor
    Paper(int strength);

    /**************************************************************************
    * fight(Tool* tool):
    * Adjusts the strengths of this and tool according to RPS logic, makes the
    * strength comparison, and returns whether this paper wins, loses, or
    * draws.
    **************************************************************************/
    Fight fight(Tool* tool);
};
