#include <stdio.h>
#define MAXESTUDIANTES 2
#define MAXCALIFICACIONES 4
#define OPCION1 '1'
#define OPCION2 '2'
#define OPCION3 '3'
#define OPCION4 '4'

void mostrarCalificaciones(float totalCalificaciones[MAXESTUDIANTES][MAXCALIFICACIONES], int calificacionesIngresadas[MAXESTUDIANTES]);
void ingresarCalificaciones(float totalCalificaciones[MAXESTUDIANTES][MAXCALIFICACIONES], int calificacionesIngresadas[MAXESTUDIANTES]);
void calcularPromedios(float totalCalificaciones[MAXESTUDIANTES][MAXCALIFICACIONES], int calificacionesIngresadas[MAXESTUDIANTES]);
void mostrarMenu(float totalCalificaciones[MAXESTUDIANTES][MAXCALIFICACIONES], int calificacionesIngresadas[MAXESTUDIANTES]);

int main(){
    float totalCalificaciones[MAXESTUDIANTES][MAXCALIFICACIONES] = {0};
    int calificacionesIngresadas[MAXESTUDIANTES] = {0};
    mostrarMenu(totalCalificaciones, calificacionesIngresadas);
    return 0;
}

void ingresarCalificaciones(float totalCalificaciones[MAXESTUDIANTES][MAXCALIFICACIONES], int calificacionesIngresadas[MAXESTUDIANTES]){
    for(int estudiantes = 0; estudiantes < MAXESTUDIANTES; estudiantes++){
        printf("\nIngresando calificaciones del estudiante %d: \n", estudiantes + 1);
        for(int calificaciones = 0; calificaciones < MAXCALIFICACIONES; calificaciones++){
            float nota;
            do{
                printf("Calificacion %d (entre 0 y 10): ", calificaciones + 1);
                scanf("%f", &nota);
                if(nota < 0 || nota > 10){
                    printf("Error: la nota debe ser entre 0 y 10. Intente nuevamente\n");
                }
            }while(nota < 0 || nota > 10);
            totalCalificaciones[estudiantes][calificaciones] = nota;
        }calificacionesIngresadas[estudiantes] = 1;
    }
}
void mostrarCalificaciones(float totalCalificaciones[MAXESTUDIANTES][MAXCALIFICACIONES], int calificacionesIngresadas[MAXESTUDIANTES]){
    printf("\n--- Calificaciones de los estudiantes ---\n");
    for(int estudiantes = 0; estudiantes < MAXESTUDIANTES; estudiantes++){
        if(calificacionesIngresadas[estudiantes] == 0){
            printf("El estudiante %d no tiene calificaciones ingresadas. \n", estudiantes + 1);
        } else{
            printf("Estudiante : %d \n", estudiantes + 1);
            for(int calificaciones = 0; calificaciones < MAXCALIFICACIONES; calificaciones++){
                printf(" %.2f", totalCalificaciones[estudiantes][calificaciones]);
            }
        printf("\n");
        }

    }
}
void calcularPromedios(float totalCalificaciones[MAXESTUDIANTES][MAXCALIFICACIONES], int calificacionesIngresadas[MAXESTUDIANTES]){
    printf("\n--- Promedio de los estudiantes ---\n");
    for(int estudiantes = 0; estudiantes < MAXESTUDIANTES; estudiantes++){
        if(calificacionesIngresadas[estudiantes] == 0){
            printf("El estudiante %d no tiene calificaciones ingresadas. \n", estudiantes + 1);
        }else{
            float sumaCalificaciones = 0;
            for(int calificaciones = 0; calificaciones < MAXCALIFICACIONES; calificaciones++){
                sumaCalificaciones += totalCalificaciones[estudiantes][calificaciones];
        }
        float promedioCalificaciones = sumaCalificaciones / MAXCALIFICACIONES;
        printf("Estudiante %d - Promedio : %.2f \n", estudiantes + 1, promedioCalificaciones);    
        }
    }
}
void mostrarMenu(float totalCalificaciones[MAXESTUDIANTES][MAXCALIFICACIONES], int calificacionesIngresadas[MAXESTUDIANTES]){
    char opcion;
    
    do{
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Ingresar calificaciones\n");
        printf("2. Mostrar calificaciones\n");
        printf("3. Calcular promedios\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion : ");
        scanf(" %c", &opcion);
        
        switch(opcion){
            case OPCION1:
                ingresarCalificaciones(totalCalificaciones, calificacionesIngresadas);
                break;
            case OPCION2:
                mostrarCalificaciones(totalCalificaciones, calificacionesIngresadas);
                break;
            case OPCION3:
                calcularPromedios(totalCalificaciones, calificacionesIngresadas);
                break;
            case OPCION4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no validad, intente nuevamente\n");
        }while (getchar() != '\n');
    }while(opcion !=OPCION4);
}