/***********************************************************************
 * Program name: CS 162 Group Project}
 * Author:       Brennan Douglas
 * Date:         02/06/2017
 * Description:  This program is a simulation of rock, paper, scissors.
 *               It is the group project for this class.
 * ********************************************************************/

#include <iostream>
#include <string>
#include <chrono>
#include "paper.hpp"
#include "rock.hpp"
#include "scissors.hpp"
#include "RPSGame.hpp"
#include "douglbre_util.hpp"

const int MENU_COUNT = 1;

// This is the main function that will be called on program execution.
// To compile program run "make", then execute the file "main".
int main (int argc, char** argv) {
	
    // Set seed for random function
    std::srand(std::time(0));

    RPSGame* game = new RPSGame();

    // Menu options array
    std::string m_items[MENU_COUNT] = { "Play Game" };

    // Menu callbacks array
    douglbre::v_v_callback m_callbacks[MENU_COUNT] = {

            // Play Game callback
            [&game]() -> void {

                char type;
                char strength;
                Tool* player;

                // Function that validates the user input for the type variable
                auto type_valid = [](char s) -> bool {
                    if (s == 'p' || s == 'r' || s == 's') {
                        return true;
                    } else {
                        std::cout << "  That is not a tool type." << std::endl;
                        return false;
                    }
                };
                // Function that validates the user input for the strength variable
                auto strength_valid = [](char s) -> bool {
                    if (s == 'y' || s == 'n') {
                        return true;
                    } else {
                        std::cout << "Please respond yes, 'y', or no, 'n'." << std::endl;
                        return false;
                    }
                };
				
				// Ask the user for inputs	
                douglbre::user::validate_input<char>("Tool Type (Paper 'p', Rock 'r', Scissors 's'): ", &type, type_valid);
                douglbre::user::validate_input<char>("Would you like to specify a specific strength? (y/n): ", &strength, strength_valid);

				// Initialize player tool without strength
                if (type == 'p') {
                    player = new Paper();
                } else if (type == 's') {
                    player = new Scissors();
                } else if (type == 'r') {
                    player = new Rock();
                }
				
				// For if the user asks for strength
                if (strength == 'y') {

                    int mag_strength = 0;

                    // Function that validates the user input for the strength magnitude
                    auto mag_valid = [](int a) -> bool {
                        if (a > 0) {
                            return true;
                        } else {
                            std::cout << "Strength has to be greater then 0." << std::endl;
                            return false;
                        }
                    };

					// Get the user's respective strengths
                    douglbre::user::validate_input<int>("Magnitude of the tool's strength: ", &mag_strength, mag_valid);

					// Set computer tool within a resonable range of the user's requested strength for fair gameplay
                    game->setTool('c', game->createComputerTool(douglbre::util::rand_clamp(1, mag_strength*2)));
                    
					// Set the players strength to the user's requested strength
					player->setStrength(mag_strength);

                } else {
					
					// Create default strength random computer tool
                    game->setTool('c', game->createComputerTool(1));

                }
				
				// Set the player tool
                game->setTool('h', player);
				
				// Play the game and display the scores
                game->playGame();
                game->printScores();

            }

    };

    // Call menu loop with title and callback arrays
    douglbre::user::menu_loop("Rock, Paper, Scissors", m_items, m_callbacks, MENU_COUNT);

    delete game;

	return 0;
}
