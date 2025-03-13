#include <stdio.h>
#define NOMBREJUGADOR 20


typedef struct{
    int minutosJugados;
    int goles;
    int asistencias;
    float promedio;
    char nombre[NOMBREJUGADOR];
} futbolista_t;

futbolista_t crearFutbolista();
float calcularPromedio(futbolista_t jugador);
void mostrarFutbolista(futbolista_t jugador);

int main(){
    printf("Bienvenido a la lista del equipo, ingrese los datos del futbolista\n");
    futbolista_t jugador = crearFutbolista();
    calcularPromedio(jugador);
    mostrarFutbolista(jugador);
}
futbolista_t crearFutbolista(){
    futbolista_t jugador;
    printf("Ingrese los minutos jugados del futbolista : ");
    scanf("%d", &jugador.minutosJugados);
    printf("Ingrese los goles del futbolista : ");
    scanf("%d", &jugador.goles);
    printf("Ingrese las asistencias del futbolista : ");
    scanf("%d", &jugador.asistencias);
    printf("Ingrese el nombre del futbolista : ");
    scanf("%s", jugador.nombre);
    jugador.promedio = calcularPromedio(jugador);
    return jugador;
}
float calcularPromedio(futbolista_t jugador){
    float promedio;
    promedio = ((float)(jugador.goles + jugador.asistencias)) / jugador.minutosJugados;
    return promedio;
}
void mostrarFutbolista(futbolista_t jugador){
    printf("Los datos del futbolista son : \n");
    printf("Nombre : %s \n", jugador.nombre);
    printf("Goles : %d \n", jugador.goles);
    printf("Asistencias : %d \n", jugador.asistencias);
    printf("Minutos jugados : %d \n", jugador.minutosJugados);
    printf("Goles y asistencias por partido : %f", jugador.promedio);
}