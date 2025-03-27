SOURCE = scannerCR

all: output compile

output:
	mkdir -p output

compile: bison_compile flex_compile link

compile_counter: bison_counter flex_compile link

flex_compile:
	flex $(SOURCE).l
	gcc -g -c lex.yy.c -o lex.yy.o -lfl

bison_compile:
	bison -v -d $(SOURCE).y 
	gcc -g -c $(SOURCE).tab.c -o $(SOURCE).tab.o

bison_counter:
	bison -d $(SOURCE).y -Wcounterexamples
	gcc -g -c $(SOURCE).tab.c -o $(SOURCE).tab.o

link: list.o functions.o lex.yy.o $(SOURCE).tab.o
	gcc -g -o $(SOURCE) list.o functions.o lex.yy.o $(SOURCE).tab.o -L. -lfl -pthread -fopenmp

list.o: list.h list.c
	gcc -g -c list.c -Wall -o list.o

functions.o: functions.h functions.c 
	gcc -g -c functions.c -Wall -o functions.o

clean:
	rm -f $(SOURCE) lex.yy.c $(SOURCE).tab.c $(SOURCE).tab.h *.o $(SOURCE).gv $(SOURCE).output

.PHONY: all compile flex_compile bison_compile link clean compile_counter bison_counter output
