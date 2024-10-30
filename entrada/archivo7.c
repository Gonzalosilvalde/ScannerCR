#include <stdio.h>
#include "archivo8.h"

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int numero;
    printf("Ingrese un número para calcular su factorial: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("No existe factorial para números negativos.\n");
    } else {
        printf("El factorial de %d es %llu\n", numero, factorial(numero));
    }

    return 0;
}

