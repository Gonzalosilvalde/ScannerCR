#include <stdio.h>
#include "archivo4.h"
#include "archivo7.h"



void ordenarBurbuja(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Introduce el número de elementos en el arreglo: ");
    scanf("%d", &n);

    int arr[n];
    printf("Introduce los elementos del arreglo:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    ordenarBurbuja(arr, n);

    printf("Arreglo ordenado en orden ascendente:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

