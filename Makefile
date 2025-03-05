#My Name: Jordan Sowell
#My Class: CPSC 1020
#Date: 2/24/2025

COMPILER = g++
OPTIONS = -Wall
PROGRAM = main.out



all: $(PROGRAM)
	

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): main.cpp BuildResultString.cpp QA.cpp
	$(COMPILER) $(OPTIONS) main.cpp BuildResultString.cpp QA.cpp -o $(PROGRAM)

clean:
	rm *.out