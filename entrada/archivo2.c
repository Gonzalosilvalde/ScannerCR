#include <stdio.h>
#include "archivo3.h"
#include "archivo4.h"

// Declaración de la función
void funcion2() {
    printf("Esta es la función 2.\n");
}

int main() {
    printf("Hola desde el archivo2.c\n");
    funcion2(hola); // Llama a la función 2
    return 0;
}
