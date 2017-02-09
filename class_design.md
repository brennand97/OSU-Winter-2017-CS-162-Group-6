# Class Design
This will be the design we follow while building this project.

##Files
- main.cpp
- tool.hpp
- tool.cpp
- rock.hpp
- rock.cpp
- paper.hpp
- paper.cpp
- scissor.hpp
- scissor.cpp
- RPSGame.hpp
- RPSGame.cpp

##Classes
###Tool (Abstract)
- Private Members
  - **int strength** -- This will represent the strength of the tool and will be used to determine who wins a fight.
  - **char type** -- This field can be checked to see if a tool is a rock **'_r_'**, a paper **'_p_'**, or scissors **'_s_'**.
- Public Members
  - **Tool()** -- Default constructor, will set **strength** to 1.
  - **Tool(int strength)** -- Strength constructor, will set **this->strength** to **strength**.
  - **virtual ~Tool()** -- Virtual deconstructor, so dervived class can create their own deconstructors properly.
  - **void setStrength(int strength)** -- Will set **this->strength** to **strength**.
  - **virtual int fight(Tool\* tool) = 0** -- This abstract method will be overriden by derived classes.
    - In the requirments it says this should be a bool, but it also says another method of conveing losing or winning is acceptable.  So here returning of +1 will convey a win, 0 will convey a tie, and -1 will convey a lose.
    
###Rock (Derived from **Tool**)
 - Public Members
   - **Rock()** -- Default constructor, will set type, **'*r*'**, and call **Tool()**
   - **Rock(int strength)** -- Strength constructor, will set type, **'*r*'**, and call **Tool(strength)**
   - **int fight(Tool\* tool)** -- Override the abstract **fight** function for Rock. Rock's strength should be doubled when fighting Scissor, or halved when fighting Paper.
   
###Paper (Derived from **Tool**)
 - Public Members
   - **Paper()** -- Default constructor, will set type, **'*p*'**, and call **Tool()**
   - **Paper(int strength)** -- Strength constructor, will set type, **'*p*'**, and call **Tool(strength)**
   - **int fight(Tool\* tool)** -- Override the abstract **fight** function for Paper. Paper's strength should be doubled when fighting Rock, or halved when fighting Scissor.

###Scissor (Derived from **Tool**)
 - Public Members
   - **Scissor()** -- Default constructor, will set type, **'*s*'**, and call **Tool()**
   - **Scissor(int strength)** -- Strength constructor, will set type, **'*s*'**, and call **Tool(strength)**
   - **int fight(Tool\* tool)** -- Override the abstract **fight** function for Scissor. Scissor's strength should be doubled when fighting Paper, or halved when fighting Rock.
   
###RPSGame
  - Private Members
    - **int human_wins** -- Counter for the number of times the human won the game.
    - **int computer_wins** -- Counter for the number of times the computer won the game.
    - **int ties** -- Counter for the number of games that resulted in ties.
    - **Tool\* human** -- The pointer to the current human tool.
    - **Tool\* computer** -- The pointer to the current computer tool.
  - Public Members
    - **void setTool(char player, Tool\* tool)** -- This function will set the player's tools.
      - The player variable will contain a **'*h*'** for human or a **'*c*'** for computer.  Then the current corresponding tool will need to be deleted from memory and the new tool given to the corresponding variable.
    - **char playGame()** -- This function will enact a game between the current player and computer tools.
      - It will increment the correct counter internally then return **'*h*'** for human win, **'*c*'** for computer win, or **'*t*'** for tie.
    - **Tool\* createComputerTool()** -- Will return a new computer tool.
      - This will be called to create a random or calculated computer tool before a new round is played.  This can either be done in the main function then set using the setTool method, or can be called at the beginning of the playGame method.
