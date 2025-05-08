#include <stdio.h>

void cambiarValor(int *puntero, int nuevoValor) {
    *puntero = nuevoValor;
}

void mostrarTemperaturas(int temperaturaMaxima, int temperaturaMinima) {
    printf("Temperatura máxima: %d°C, Temperatura mínima: %d°C\n", temperaturaMaxima, temperaturaMinima);
}

void actualizarTemperaturas(int *punteroTemperaturaMaxima, int *punteroTemperaturaMinima, int nuevaMaxima, int nuevaMinima) {
    cambiarValor(punteroTemperaturaMaxima, nuevaMaxima);  
    cambiarValor(punteroTemperaturaMinima, nuevaMinima);  
}

void ingresarTemperaturas(int *temperaturaMaxima, int *temperaturaMinima, int *temperaturaMaximaFinal, int *temperaturaMinimaFinal) {
    printf("Ingrese la temperatura máxima inicial: ");
    scanf("%d", temperaturaMaxima);
    printf("Ingrese la temperatura mínima inicial: ");
    scanf("%d", temperaturaMinima);

    printf("Ingrese la temperatura máxima final: ");
    scanf("%d", temperaturaMaximaFinal);
    printf("Ingrese la temperatura mínima final: ");
    scanf("%d", temperaturaMinimaFinal);
}

int main() {
    int temperaturaMaxima, temperaturaMinima;
    int temperaturaMaximaFinal, temperaturaMinimaFinal;

    ingresarTemperaturas(&temperaturaMaxima, &temperaturaMinima, &temperaturaMaximaFinal, &temperaturaMinimaFinal);

    printf("Antes de actualizar las temperaturas:\n");
    mostrarTemperaturas(temperaturaMaxima, temperaturaMinima);

    actualizarTemperaturas(&temperaturaMaxima, &temperaturaMinima, temperaturaMaximaFinal, temperaturaMinimaFinal);

    printf("Después de actualizar las temperaturas:\n");
    mostrarTemperaturas(temperaturaMaxima, temperaturaMinima);

    return 0;
}
