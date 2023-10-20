FUENTE = scanner
PRUEBA = archivo4.c

all: compile run

compile: bison_compile flex_compile link

all_counter: compile_counter run

compile_counter: bison_counter flex_compile link

flex_compile:
	flex $(FUENTE).l
	gcc -c  lex.yy.c -o lex.yy.o -lfl

bison_compile:
	bison -d $(FUENTE).y 
	gcc -c  $(FUENTE).tab.c -o $(FUENTE).tab.o

bison_counter:
	bison -d $(FUENTE).y -Wcounterexamples
	gcc -c  $(FUENTE).tab.c -o $(FUENTE).tab.o

link:
	gcc -o  $(FUENTE) list.o lex.yy.o $(FUENTE).tab.o -L. -lfl -ly  -pthread -fopenmp

run:
	./$(FUENTE) $(PRUEBA)

list.o : list.h list.c
	gcc -c list.c -Wall

valgrind: 
	valgrind --leak-check=full --track-origins=yes ./$(FUENTE) $(PRUEBA)

clean:
	rm -f $(FUENTE) lex.yy.c $(FUENTE).tab.c $(FUENTE).tab.h *.o

.PHONY: all compile flex_compile bison_compile link run clean
