#include <stdio.h>
void celsiusToFahrenheitAndKelvin(float celsius) {
    printf("Fahrenheit: %.2f\n", celsius * 9/5 + 32);
    printf("Kelvin: %.2f\n", celsius + 273.15);
}

void fahrenheitToCelsiusAndKelvin(float fahrenheit) {
    printf("Celsius: %.2f\n", (fahrenheit - 32) * 5/9);
    printf("Kelvin: %.2f\n", (fahrenheit - 32) * 5/9 + 273.15);
}

void kelvinToCelsiusAndFahrenheit(float kelvin) {
    printf("Celsius: %.2f\n", kelvin - 273.15);
    printf("Fahrenheit: %.2f\n", (kelvin - 273.15) * 9/5 + 32);
}

int main() {
    int opcion;
    float temperatura;

    printf("Conversor de Temperatura\n");
    printf("1. Celsius a Fahrenheit y Kelvin\n");
    printf("2. Fahrenheit a Celsius y Kelvin\n");
    printf("3. Kelvin a Celsius y Fahrenheit\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);

    printf("Ingrese la temperatura: ");
    scanf("%f", &temperatura);

    switch(opcion) {
        case 1:
            celsiusToFahrenheitAndKelvin(temperatura);
            break;
        case 2:
            fahrenheitToCelsiusAndKelvin(temperatura);
            break;
        case 3:
            kelvinToCelsiusAndFahrenheit(temperatura);
            break;
        default:
            printf("Opción no válida.\n");
    }

    return 0;
}

