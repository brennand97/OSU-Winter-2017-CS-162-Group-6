/*********************************************
 * Project Group: Group 6
 * Author: Alan Macabuhay
 * Date: 2/12/17
 * Filename: RPSGame.hpp
 * Description: Header file for class RPSGame.
 **********************************************/

#ifndef RPSGAME_HPP
#define RPSGAME_HPP

#include "tool.hpp"

// The purpose of this class is to hold all the values required to run a rock paper sisscors game.
class RPSGame {
private:
	int human_wins;		//counter for number of human wins
	int computer_wins;	//counter for number of computer wins
	int ties;		//counter for number of ties
	Tool *human = nullptr;		//pointer for current human tool
	Tool *computer = nullptr;		//pointer for current computer tool

public:
	RPSGame();
	~RPSGame();
	void setTool(char player, Tool *tool);
	char playGame();
	Tool *createComputerTool(int strength);
	void printScores();
};

#endif
