#include <stdio.h>
#include <stdlib.h>
struct Nodo {
    int data;
    struct Nodo* siguiente;
};

void agregarNodo(struct Nodo** cabeza, int valor) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->data = valor;
    nuevoNodo->siguiente = *cabeza;
    *cabeza = nuevoNodo;
}

void eliminarNodo(struct Nodo** cabeza, int valor) {
    struct Nodo* temp = *cabeza, *prev;

    if (temp != NULL && temp->data == valor) {
        *cabeza = temp->siguiente;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != valor) {
        prev = temp;
        temp = temp->siguiente;
    }

    if (temp == NULL) return;

    prev->siguiente = temp->siguiente;
    free(temp);
}

void mostrarLista(struct Nodo* nodo) {
    while (nodo != NULL) {
        printf("%d -> ", nodo->data);
        nodo = nodo->siguiente;
    }
    printf("NULL\n");
}

int main() {
    struct Nodo* cabeza = NULL;
    int opcion, valor;

    do {
        printf("\n1. Agregar nodo\n2. Eliminar nodo\n3. Mostrar lista\n4. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("Ingrese el valor a agregar: ");
                scanf("%d", &valor);
                agregarNodo(&cabeza, valor);
                break;
            case 2:
                printf("Ingrese el valor a eliminar: ");
                scanf("%d", &valor);
                eliminarNodo(&cabeza, valor);
                break;
            case 3:
                printf("Lista actual: ");
                mostrarLista(cabeza);
                break;
            case 4:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while(opcion != 4);

    return 0;
}

