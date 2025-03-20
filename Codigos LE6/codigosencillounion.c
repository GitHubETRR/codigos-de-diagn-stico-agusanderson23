#include <stdio.h>

typedef union {
    int entero;
    int entero2;
}datosUnion;

int main() {
    datosUnion datos;
    printf("Ingrese un numero entero: ");
    scanf("%d", &datos.entero);
    printf("Variable 1: %d\n", datos.entero);
    printf("Variable 2: %d\n", datos.entero2);
    return 0;
}
