/******************************************************************************
** Project Group: Group 6
** Author: Patick Kilgore
** Date: 10 Feb 2017
** Filename: rock.hpp
** Description: Implementation file for the Paper class which inherits from the
**              Tool class. This class models the behavior of paper in the Rock
**              Paper Scissors game by having double strength against rock
**              and half strength against scissors.
******************************************************************************/

#include "paper.hpp"

// default constructor
Paper::Paper()
{
  // Initialize Tool class protected members
  this->strength = 1;
  this->type = 'p';
}

// parameterized constructor
Paper::Paper(int strength) : Tool(strength)
{
  // Initialize Tool class protected members
  this->type = 'p';
}

/**************************************************************************
* fight(Tool* tool):
* Adjusts the strengths of this and tool according to RPS logic, makes the
* strength comparison, and returns whether this paper wins, loses, or
* draws.
**************************************************************************/
Fight Paper::fight(Tool* tool)
{
  Fight fightResult;

  // Store pre-fight strengths so they can be reset after round is over
  int myStrength = this->strength;
  int enemyStrength = tool->getStrength();

  // Adjust strength of the combatants
  if (tool->getType() == 's')
  {
      this->setStrength(myStrength / 2);
      tool->setStrength(enemyStrength * 2);
  }
  if (tool->getType() == 'r')
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
