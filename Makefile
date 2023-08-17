FUENTE = scanner
PRUEBA = hola.cpp

all: compile run

compile: flex_compile bison_compile link

flex_compile:
	flex $(FUENTE).l
	gcc -c lex.yy.c -o lex.yy.o

bison_compile:
	bison -d $(FUENTE).y
	gcc -c $(FUENTE).tab.c -o $(FUENTE).tab.o

link:
	gcc -o $(FUENTE) list.o lex.yy.o $(FUENTE).tab.o -L. -lfl -ly -g

run:
	./$(FUENTE) $(PRUEBA)

list.o : list.h list.c
	gcc -c list.c -Wall

clean:
	rm -f $(FUENTE) lex.yy.c $(FUENTE).tab.c $(FUENTE).tab.h *.o

.PHONY: all compile flex_compile bison_compile link run clean
