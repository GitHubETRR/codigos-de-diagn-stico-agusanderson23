#include <stdio.h>
#define NOMBREJUGADOR 20
#define OPCION1 '1'
#define OPCION2 '2'
#define OPCION3 '3'
#define EXISTEJUGADOR 1


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
void menu();

int main(){
    menu();
    return 0;
}
void menu(){
    futbolista_t jugador;
    char opcion;
    int jugadorCreado = 0;
    
    do{
        printf("\n--- MENU ---\n");
        printf("1. Agregar futbolista\n");
        printf("2. Mostrar futbolista\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%c", &opcion);
        
        switch (opcion){
            case OPCION1:
                jugador = crearFutbolista();
                jugadorCreado = EXISTEJUGADOR;
                break;
            case OPCION2:
                if (jugadorCreado == EXISTEJUGADOR){
                    mostrarFutbolista(jugador);
                } else{
                    printf("Primero debes agregar un futbolista\n");
                }break;
            case OPCION3:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no valida, intente nuevamente\n");
        }
        while (getchar() != '\n'); //Limpiar buffer
    } while (opcion != OPCION3);
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
    if (jugador.minutosJugados == 0){ // Evitar division por cero
        return 0;
    }
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