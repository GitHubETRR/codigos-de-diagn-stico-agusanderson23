#include <stdio.h>
#define TEMPMAXIN 30
#define TEMPMININ 15
#define TEMPMAXFIN 35
#define TEMPMINFIN 20

void cambiarValor(int *puntero, int nuevoValor) {
    *puntero = nuevoValor;
}

void imprimirTemperaturas(int temperaturaMaxima, int temperaturaMinima) {
    printf("Temperatura máxima: %d°C, Temperatura mínima: %d°C\n", temperaturaMaxima, temperaturaMinima);
}

void actualizarTemperaturas(int *punteroTemperaturaMaxima, int *punteroTemperaturaMinima) {
    cambiarValor(punteroTemperaturaMaxima, TEMPMAXFIN);  
    cambiarValor(punteroTemperaturaMinima, TEMPMINFIN);  
}

int main() {
    int temperaturaMaxima = TEMPMAXIN;
    int temperaturaMinima = TEMPMININ;
    printf("Antes de actualizar las temperaturas:\n");
    imprimirTemperaturas(temperaturaMaxima, temperaturaMinima);
    actualizarTemperaturas(&temperaturaMaxima, &temperaturaMinima);
    printf("Después de actualizar las temperaturas:\n");
    imprimirTemperaturas(temperaturaMaxima, temperaturaMinima);

    return 0;
}