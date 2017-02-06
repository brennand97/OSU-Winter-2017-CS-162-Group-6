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
- scissors.hpp
- scissors.cpp
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
   - **Rock()** -- Default constructor, will call **Tool()**
   - **Rock(int strength)** -- Strength constructor, will call **Tool(strength)**
   - **int fight(Tool\* tool)** -- Override the abstract **fight** function for Rock. Rock's strength should be doubled when fighting Scissor, or halved when fighting Paper.
   
###Paper (Derived from **Tool**)
 - Public Members
   - **Paper()** -- Default constructor, will call **Tool()**
   - **Paper(int strength)** -- Strength constructor, will call **Tool(strength)**
   - **int fight(Tool\* tool)** -- Override the abstract **fight** function for Paper. Paper's strength should be doubled when fighting Rock, or halved when fighting Scissor.

###Scissor (Derived from **Tool**)
 - Public Members
   - **Scissor()** -- Default constructor, will call **Tool()**
   - **Scissor(int strength)** -- Strength constructor, will call **Tool(strength)**
   - **int fight(Tool\* tool)** -- Override the abstract **fight** function for Scissor. Scissor's strength should be doubled when fighting Paper, or halved when fighting Rock.
