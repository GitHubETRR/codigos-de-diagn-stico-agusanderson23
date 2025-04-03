#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 30
#define SALIR 1

typedef struct{
    int alumnos;
    char modalidad[CANT];
    char materias[CANT];
    curso_t *next;
}curso_t;

void imprimirCurso(curso_t *lista);
curso_t * agregarCurso(curso_t * lista);
int salir();
void liberar(curso_t * colegio);

int main(){
    curso_t *colegio=NULL;
    do{
        colegio=agregarCurso(colegio);
    }while(salir()!=SALIR);
    imprimirCurso(colegio);
    liberar(colegio);
    return 0;
}

void imprimirCurso(curso_t *lista){
    while(lista!=NULL){
        printf("Cantidad de alumnos : %d\n", lista->alumnos);
        printf("Modalidad : %s\n", lista->modalidad);
        printf("Materias : %s\n", lista->materias);
        lista=lista->next;
    }
}

curso_t * agregarCurso(curso_t * lista){
    curso_t *cur_ptr=(curso_t*)malloc(sizeof(curso_t));
    cur_ptr->next=lista;
    printf("Ingrese la cantidad de alumnos : ");
    scanf("%d", &cur_ptr->alumnos);
    printf("\n");
    printf("Ingrese la modalidad del curso : ");
    scanf("%s", cur_ptr->modalidad);
    printf("\n");
    printf("Ingrese las materias del curso : ");
    scanf("%s", cur_ptr->materias);
    printf("\n");
    lista=cur_ptr;
    printf("Curso creado correctamente");
    return lista;
}

int salir (void){
    int salir=0;
    printf("Desea agrega un curso mas?\n");
    printf("0 para si %d para no\n", SALIR);
    scanf("%d",&salir);
    return salir;
}

void liberar (curso_t * lista){
    curso_t *aux;
     while(lista!=NULL){
        aux=lista;
        lista=lista->next;
        free(aux);
    }
}