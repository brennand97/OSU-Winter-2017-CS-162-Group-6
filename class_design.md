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
