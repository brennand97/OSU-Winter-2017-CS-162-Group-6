/******************************************************************************
** Project Group: Group 6
** Author: Patick Kilgore
** Date: 10 Feb 2017
** Filename: rock.hpp
** Description: Header file for the Scissors class which inherits from the Tool
**              class. This class models the behavior of scissors in the Rock
**              Paper Scissors game by having double strength against paper
**              and half strength against rock.
******************************************************************************/

#include "tool.hpp"

class Scissors : public Tool
{
public:
    // default constructor
    Scissors();

    // parameterized constructor
    Scissors(int strength);

    /**************************************************************************
    * fight(Tool* tool):
    * Adjusts the strengths of this and tool according to RPS logic, makes the
    * strength comparison, and returns whether these scissors wins, loses, or
    * draws.
    **************************************************************************/
    Fight fight(Tool* tool);
};
