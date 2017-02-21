
CXX = g++

CXXFLAGS = -std=c++0x

#DEBUG flags
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

LDFLAGS =

OBJS = play_game.o tool.o paper.o rock.o scissors.o RPSGame.o douglbre_util.o

SRCS = play_game.cpp tool.cpp paper.cpp rock.cpp scissors.cpp RPSGame.cpp douglbre_util.cpp

HEADERS = douglbre_util.hpp tool.hpp paper.hpp rock.hpp scissors.hpp RPSGame.hpp

EXECUTABLE = main

main: $(OBJS) $(HEADERS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(EXECUTABLE)

$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	rm -f $(OBJS)
	rm -f $(EXECUTABLE)
	@echo All object files and executable removed
