#include <stdio.h>

void hanoi(int n, char desde, char auxiliar, char hacia) {
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
