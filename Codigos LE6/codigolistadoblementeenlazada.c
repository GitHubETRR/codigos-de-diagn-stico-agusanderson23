#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CALIFICACIONES 3
#define VALOR_ERROR -1
#define MAX_NOMBRE 20
#define MAX_CURSO 20
#define MAX_ESTADO 20

typedef struct estudiantes{
    char nombre[MAX_NOMBRE];
    float calificaciones[MAX_CALIFICACIONES];
    float promedio;
    char curso[MAX_CURSO];
    char estado[MAX_ESTADO];
    struct estudiantes *next;
    struct estudiantes *back;
}estudiantes_t;

void liberarMemoria(estudiantes_t *inicio);
estudiantes_t *crearEstudiante();
estudiantes_t *agregarEstudiante(estudiantes_t *inicio);
void mostrarEstudiante(estudiantes_t* inicio);
void menu(estudiantes_t *inicio);

int main(){
    estudiantes_t *inicio=NULL;
    menu(inicio);
    return 0;
}

void liberarMemoria(estudiantes_t *inicio){
    if(inicio==NULL){
        printf("No hay estudiantes cargados en la lista \n");
    }
    else{
        estudiantes_t *aux = NULL;
        while(inicio!=NULL){
            aux = inicio;
            inicio=inicio->next;
            free(aux);
        }
        printf("Memoria liberada correctamente \n");
    }
}

estudiantes_t *crearEstudiante(){
    estudiantes_t *nuevoEstudiante = (estudiantes_t *)malloc(sizeof(estudiantes_t));
    if(nuevoEstudiante==NULL){
        printf("Error al asignar memoria \n");
        exit(VALOR_ERROR);
    }
    printf("Ingrese el curso del estudiantes: ");
    scanf("%s", nuevoEstudiante->nombre);
    printf("\n Ingrese el nombre del estudiante: ");
    scanf("%s", nuevoEstudiante->curso);

    float sumaCalificaciones=0.0;
    for(int calificacionIngresada = 0;calificacionIngresada<MAX_CALIFICACIONES; calificacionIngresada++){
        printf("Ingrese la calificaciones %d del estudiantes: ", calificacionIngresada + 1);
        scanf("%f", &nuevoEstudiante[calificacionIngresada]);
        sumaCalificaciones += nuevoEstudiante->calificaciones[calificacionIngresada];
    }
    
    nuevoEstudiante->promedio = sumaCalificaciones / MAX_CALIFICACIONES;
    
    if(nuevoEstudiante->promedio < 7){
        strcpy(nuevoEstudiante->estado, "Desaprobado");
    }
    else{
        if(nuevoEstudiante->promedio >= 7){
            strcpy(nuevoEstudiante->estado, "Aprobado");
        }    
    }
    
    nuevoEstudiante->next=NULL;
    NuevoEstudiante->back=NULL;
    return nuevoEstudiante;
}

estudiantes_t *agregarEstudiante(estudiantes_t *inicio){
    estudiantes_t *nuevoEstudiante = crearEstudiante();
    if(nuevoEstudiantes == NULL){
        return nuevoEstudiante
    }
    else{
        estudiante_t *aux = inicio
        while(aux->next != NULL){
            aux=aux->next;
        }
        aux->next = nuevoEstudiante;
        nuevoEstudiantes->back = aux;
        return inicio;
    }
}

void mostrarEstudiante(estudiantes*t inicio){
    if(inicio==NULL){
        printf("No hay estudiantes cargados en la lista");
    }
    else{
        estudiantes_t *aux = inicio;
        int estudiantes = 1;
        while(aux!=NULL){
            printf("\n Los datos de la %s de %s son: \n", aux->curso, aux->nombre);
            printf("")
        }
    }
}
