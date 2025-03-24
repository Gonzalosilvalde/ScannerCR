SOURCE = scanner

# Default target: compile the project
all: output compile

# Create the output folder if it doesn't exist
output:
	mkdir -p output

# Compile using bison and flex, then link the objects
compile: bison_compile flex_compile link

# Alternative compile target with counter examples from bison
compile_counter: bison_counter flex_compile link

# Generate lexical analyzer and compile it
flex_compile:
	flex $(SOURCE).l
	gcc -g -c lex.yy.c -o lex.yy.o -lfl

# Generate parser with verbose output and compile it
bison_compile:
	bison -v -d $(SOURCE).y 
	gcc -g -c $(SOURCE).tab.c -o $(SOURCE).tab.o

# Generate parser with counter example warnings and compile it
bison_counter:
	bison -d $(SOURCE).y -Wcounterexamples
	gcc -g -c $(SOURCE).tab.c -o $(SOURCE).tab.o

# Link object files to create the final executable
link: list.o lex.yy.o $(SOURCE).tab.o
	gcc -g -o $(SOURCE) list.o lex.yy.o $(SOURCE).tab.o -L. -lfl -pthread -fopenmp

# Compile the list module
list.o: list.h list.c
	gcc -g -c list.c -Wall -o list.o

# Clean up generated files
clean:
	rm -f $(SOURCE) lex.yy.c $(SOURCE).tab.c $(SOURCE).tab.h *.o $(SOURCE).gv $(SOURCE).output

.PHONY: all compile flex_compile bison_compile link clean compile_counter bison_counter output

