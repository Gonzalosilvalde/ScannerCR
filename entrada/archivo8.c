#include <stdio.h>

#define MAX_PRODUCTOS 100

struct Producto {
    int id;
    char nombre[50];
    int cantidad;
    float precio;
};

void agregarProducto(struct Producto inventario[], int *numProductos) {
    if (*numProductos < MAX_PRODUCTOS) {
        printf("ID del producto: ");
        scanf("%d", &inventario[*numProductos].id);
        printf("Nombre del producto: ");
        scanf("%s", inventario[*numProductos].nombre);
        printf("Cantidad en stock: ");
        scanf("%d", &inventario[*numProductos].cantidad);
        printf("Precio: ");
        scanf("%f", &inventario[*numProductos].precio);

        (*numProductos)++;
        printf("Producto agregado exitosamente.\n");
    } else {
        printf("Inventario lleno, no se puede agregar más productos.\n");
    }
}

void mostrarInventario(struct Producto inventario[], int numProductos) {
    printf("\nInventario:\n");
    for (int i = 0; i < numProductos; i++) {
        printf("ID: %d, Nombre: %s, Cantidad: %d, Precio: %.2f\n",
               inventario[i].id, inventario[i].nombre, inventario[i].cantidad, inventario[i].precio);
    }
}

void buscarProducto(struct Producto inventario[], int numProductos, int id) {
    int encontrado = 0;
    for (int i = 0; i < numProductos; i++) {
        if (inventario[i].id == id) {
            printf("Producto encontrado - ID: %d, Nombre: %s, Cantidad: %d, Precio: %.2f\n",
                   inventario[i].id, inventario[i].nombre, inventario[i].cantidad, inventario[i].precio);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Producto con ID %d no encontrado.\n", id);
    }
}

int main() {
    struct Producto inventario[MAX_PRODUCTOS];
    int numProductos = 0;
    int opcion, id;

    do {
        printf("\nSistema de Gestión de Inventario\n");
        printf("1. Agregar producto\n2. Mostrar inventario\n3. Buscar producto\n4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                agregarProducto(inventario, &numProductos);
                break;
            case 2:
                mostrarInventario(inventario, numProductos);
                break;
            case 3:
                printf("Ingrese el ID del producto a buscar: ");
                scanf("%d", &id);
                buscarProducto(inventario, numProductos, id);
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

