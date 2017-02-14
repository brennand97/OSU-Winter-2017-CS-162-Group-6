/*****************************************************
 * Project Group: Group 6
 * Filename: RPSGame.cpp
 * Date: 2/12/17
 * Description: Implementation file of RPSGame class
 *****************************************************/
#include "RPSGame.hpp"
#include "tool.hpp"
#include "rock.hpp"
#include "paper.hpp"
#include "scissors.hpp"
#include <iostream>

using std::cout;
using std::endl;

RPSGame::RPSGame()
{
	human_wins = 0;
	computer_wins = 0;
	ties = 0;
}

RPSGame::~RPSGame() {
	delete human;
	delete computer;
}

void RPSGame::setTool(char player, Tool *tool)
{
	if( player == 'h' ) {
		delete human;
		human = tool;
	} else if ( player == 'c' ) {
		delete computer;
		computer = tool;
	}
}


Tool* RPSGame::createComputerTool(int strength)
{
	//get a random number between 1-3
	int c = rand() % 3 + 1;

	if(c == 1)
	{
		return new Rock(strength);
	}
	if(c == 2)
	{
		return new Paper(strength);
	}	
	if(c == 3)
	{
		return new Scissors(strength);
	}

	return nullptr;
}

char RPSGame::playGame()
{
	Fight result;

	//call human fight method with computer's tool as parameter
	result = human->fight(computer);

	if(result == WIN)
	{
		cout << "Human wins" << endl;
		human_wins++;
		return 'h';
	}	
	else if(result == LOSE)
	{
		cout << "Computer wins" << endl;
		computer_wins++;
		return 'c';
	}
	else
	{
		cout << "It's a tie" << endl;
		ties++;
		return 't';
	}
	
}

void RPSGame::printScores() {

	cout << "  Human Wins:    " << this->human_wins << endl;
	cout << "  Computer Wins: " << this->computer_wins << endl;
	cout << "  Ties:          " << this->ties << endl;

}
