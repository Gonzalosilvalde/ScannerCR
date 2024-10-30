FUENTE = scanner
PRUEBA = archivo1.c

all: compile run

compile: bison_compile flex_compile link

all_counter: compile_counter run

compile_counter: bison_counter flex_compile link

flex_compile:
	flex $(FUENTE).l
	gcc -g -c lex.yy.c -o lex.yy.o -lfl

bison_compile:
	bison -v -d $(FUENTE).y 
	gcc -g -c $(FUENTE).tab.c -o $(FUENTE).tab.o

bison_counter:
	bison -d $(FUENTE).y -Wcounterexamples
	gcc -g -c $(FUENTE).tab.c -o $(FUENTE).tab.o

link: list.o lex.yy.o $(FUENTE).tab.o
	gcc -g -o $(FUENTE) list.o lex.yy.o $(FUENTE).tab.o -L. -lfl -pthread -fopenmp

run:
	./$(FUENTE) $(PRUEBA)

list.o : list.h list.c
	gcc -g -c list.c -Wall -o list.o

valgrind: 
	valgrind --leak-check=full --track-origins=yes ./$(FUENTE) $(PRUEBA) > fallos.txt 2>&1

debug: all
	gdb ./$(FUENTE)

clean:
	rm -f $(FUENTE) lex.yy.c $(FUENTE).tab.c $(FUENTE).tab.h *.o $(FUENTE).gv $(FUENTE).output

.PHONY: all compile flex_compile bison_compile link run clean debug

