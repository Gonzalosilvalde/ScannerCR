#include <stdio.h>
#include "archivo5.h"
int main() {
    char operador;
    double num1, num2, resultado;

    printf("Introduce el primer número: ");
    scanf("%lf", &num1);

    printf("Introduce el operador (+, -, *, /): ");
    scanf(" %c", &operador);

    printf("Introduce el segundo número: ");
    scanf("%lf", &num2);

    switch (operador) {
        case '+':
            resultado = num1 + num2;
            break;
        case '-':
            resultado = num1 - num2;
            break;
        case '*':
            resultado = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
            } else {
                printf("Error: División por cero no permitida.\n");
                return 1;
            }
            break;
        default:
            printf("Operador no válido.\n");
            return 1;
    }

    printf("Resultado: %.2f\n", resultado);
    return 0;
}

