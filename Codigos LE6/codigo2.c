#include <stdio.h>
#define ESTUDIANTES 10
#define CALIFICACIONES 4


void mostrarCalificaciones(float calificaciones[ESTUDIANTES][CALIFICACIONES]);
void ingresarCalificaciones(float calificaciones[ESTUDIANTES][CALIFICACIONES]);
void calcularPromedios(float calificaciones[ESTUDIANTES][CALIFICACIONES]);
void menu(float calificaciones[ESTUDIANTES][CALIFICACIONES]);

int main(){
    float calificaciones[ESTUDIANTES][CALIFICACIONES];
}

void ingresarCalificaciones(float calificaciones[ESTUDIANTES][CALIFICACIONES]){
    for(int ESTUDIANTES = 0; i < ESTUDIANTES; ESTUDIANTES++){
        printf("\nIngresando calificaciones del estudiante %d: \n", i + 1);
        for(int CALIFICACIONES = 0; j < CALIFICACIONES; CALIFICACIONES++){
            printf("Calificacion %d: ", j + 1);
            scanf("%f", &calificaciones[E][j]);
        }
    }
}
void mostrarCalificaciones(float calificaciones[ESTUIDANTES][CALIFICACIONES]){
    printf("\n--- Calificaciones de los estudiantes ---\n");
    for(int i = 0; i < ESTUDIANTES)
    
}