/******************************************************************************
** Project Group: Group 6
** Author: Patick Kilgore
** Date: 10 Feb 2017
** Filename: rock.hpp
** Description: Implementation file for the Scissors class which inherits from
**              the Tool class. This class models the behavior of scissors in
**              the Rock Paper Scissors game by having double strength against
**              paper and half strength against rock.
******************************************************************************/

#include "scissors.hpp"

// Default constructor
Scissors::Scissors()
{
    // Initialize Tool class protected members
    this->strength = 1;
    this->type = 's';
}

// Parameterized constructor
Scissors::Scissors(int strength) : Tool(strength)
{
    // Initialize Tool class protected members
    this->type = 's';
}

/**************************************************************************
* fight(Tool* tool):
* Adjusts the strengths of this and tool according to RPS logic, makes the
* strength comparison, and returns whether these scissors wins, loses, or
* draws.
**************************************************************************/
Fight Scissors::fight(Tool* tool)
{
    Fight fightResult;

    // Store pre-fight strengths so they can be reset after round is over
    int myStrength = this->strength;
    int enemyStrength = tool->getStrength();

    // Adjust strength of the combatants
    if (tool->getType() == 'r')
    {
        this->setStrength(myStrength / 2);
        tool->setStrength(enemyStrength * 2);
    }
    if (tool->getType() == 'p')
    {
        this->setStrength(myStrength * 2);
        tool->setStrength(enemyStrength / 2);
    }

    // Compare strengths to determine the winner
    if (this->getStrength() > tool->getStrength())
    {
        fightResult = WIN;
    }
    else if (this->getStrength() < tool->getStrength())
    {
        fightResult = LOSE;
    }
    else
    {
        fightResult = DRAW;
    }

    // Round is over, restore strengths
    this->setStrength(myStrength);
    tool->setStrength(enemyStrength);

    return fightResult;
}
