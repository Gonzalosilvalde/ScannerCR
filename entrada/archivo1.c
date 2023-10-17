#include <stdio.h>
#include "archivo2.h"
#include "archivo3.h"
#include "archivo4.h"

// Declaración de la función
void funcion1() {
    printf("Esta es la función 1.\n");
}

int main() {
    printf("Hola desde el archivo1.c\n");
    funcion1(); // Llama a la función 1
    return 0;
}
