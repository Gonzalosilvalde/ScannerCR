FUENTE = scanner
PRUEBA = hola.cpp

all: compile run

compile:
	flex $(FUENTE).l
	bison -o $(FUENTE).tab.c $(FUENTE).y -yd --report=all -v
	gcc -o $(FUENTE) list.o lex.yy.c $(FUENTE).tab.c -lfl -ly -g



run:
	./$(FUENTE) $(PRUEBA) 

run2:
	./$(FUENTE) $(PRUEBA)

list.o : list.h list.c
	gcc -c list.c -Wall

clean:
	rm $(FUENTE) lex.yy.c $(FUENTE).tab.c $(FUENTE).tab.h

