#
# Makefile for a CS 360 lab or programming assignment.
# Do not modify this file!!!
#

CXXFLAGS = -g -Wall

SRC = Sorter.cpp
OBJ = $(SRC:.cpp=.o)
EXE = $(SRC:.cpp=.exe)

$(EXE) : clean $(OBJ)
	$(CXX) -o $@ $(OBJ) -lm

# This is just a dummy target to force other targets
# to always be out of date.
nonexistent :

# Remove generated files.
clean : 
	rm -f *.o *.exe
