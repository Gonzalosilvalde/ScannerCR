FUENTE = scanner
PRUEBA = hola.cpp

all: compile run

compile:
	flex $(FUENTE).l
	bison -o $(FUENTE).tab.c $(FUENTE).y -yd
	gcc -o $(FUENTE) lex.yy.c $(FUENTE).tab.c -lfl -ly

compile2:
	flex $(FUENTE).l
	bison -o $(FUENTE).tab.c $(FUENTE).y -yd -v -g
	gcc -o $(FUENTE) lex.yy.c $(FUENTE).tab.c -lfl -ly

run:
	./$(FUENTE) < $(PRUEBA)

run2:
	./$(FUENTE) $(PRUEBA)

clean:
	rm $(FUENTE) lex.yy.c $(FUENTE).tab.c $(FUENTE).tab.h

