#include <stdio.h>
#include "archivo1.h"
#include "archivo2.h"
#include "archivo3.h"
#include "archivo4.h"



struct Persona {
    char nombre;
    int edad;
    float altura;
    };
void hanoi(int n, char desde, char auxiliar, char hacia) {
    struct Persona {
    char nombre;
    int edad;
    float altura;
    };
    if (n == 1) {
        printf("Mueva el disco 1 desde el poste %c hacia el poste %c\n", desde, hacia);
        return;
    }
    printf("aqui1");
    hanoi(n - 1, desde, hacia, auxiliar);
    printf("Mueva el disco %d desde el poste %c hacia el poste %c\n", n, desde, hacia);
    hanoi(n - 1, auxiliar, desde, hacia);
}

int main() {
    int n;
    
    printf("Ingrese el número de discos: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("El número de discos debe ser mayor que 0.\n");
        return 1;
    }

    hanoi(n, 'A', 'B', 'C');
    
    return 0;
}
