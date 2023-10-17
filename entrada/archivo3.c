#include <stdio.h>
#include "archivo4.h"

// Declaración de la función
void funcion3() {
    printf("Esta es la función 3.\n");
}

int main() {
    printf("Hola desde el archivo3.c\n");
    funcion3(hola); // Llama a la función 3
    return 0;
}
