#My Name: Jordan Sowell
#My Class: CPSC 1020
#Date: 2/24/2025
#Time: 1 minutes
#Description: Make a file

COMPILER = g++
OPTIONS = -Wall
PROGRAM = main.out



all: $(PROGRAM)
	

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): main.cpp buildResultString.cpp QA.cpp
	$(COMPILER) $(OPTIONS) main.cpp buildResultString.cpp QA.cpp -o $(PROGRAM)

clean:
	rm *.out