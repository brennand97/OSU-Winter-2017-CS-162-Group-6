/***********************************************************************
 * Program name: CS 162 Group Project}
 * Author:       Brennan Douglas
 * Date:         02/06/2017
 * Description:  This program is a simulation of rock, paper, scissors.
 *               It is the group project for this class.
 * ********************************************************************/

#include <iostream>
#include <string>
#include "menu_library/douglbre_util.hpp"

const int MENU_COUNT = 1;

// This is the main function that will be called on program execution.
// To compile program run "make", then execute the file "main".
int main (int argc, char** argv) {

    // Menu options array
    std::string m_items[MENU_COUNT] = { "titles" };

    // Menu callbacks array
    douglbre::v_v_callback m_callbacks[MENU_COUNT] = {

            // callback
            []() -> void {

                std::string name = "";

                // Function that validates the user input for a string
                auto string_valid = [](std::string s) -> bool {
                    return true;
                };
				
                douglbre::user::validate_input<std::string>("  Name: ", &name, string_valid);

            }

    };

    // Call menu loop with title and callback arrays
    douglbre::user::menu_loop("DEMO", m_items, m_callbacks, MENU_COUNT);


	return 0;
}
