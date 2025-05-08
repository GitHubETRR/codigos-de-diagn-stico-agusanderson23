#include <stdio.h>
#include <stdlib.h>

#define MAXNOMBRE 20
#define VALORERROR -1

typedef struct peliculas{
    char nombre[MAXNOMBRE];
    int anio;
    struct peliculas_t *next;
}peliculas_t

peliculas_t *crearPelicula();
void mostrarPeliculas(peliculas_t *lista);
void cantidadPeliculas(peliculas_t *lista);
void menu(peliculas_t *lista)

int main(){
    peliculas_t *listaPeliculas = NULL;
    menu(listaPeliculas);
    return 0;
}
peliculas_t* crearPelicula(){
    peliculas_t *nuevaPeli = (peliculas_t *)malloc(sizeof(peliculas_t));
    if(nuevaPeli == NULL){
        printf("Error al asignar memoria");
        exit(VALORERROR);
    }
    printf("Ingrese el nombre de la pelicula: ");
    scanf("%s", nuevaPeli->nombre);
    printf("\n Ingrese el año de lanzamiento: ");
    scanf("%d", &nuevaPeli->anio);
    nuevaPeli->next = NULL;
    return nuevaPeli;
}
void mostrarPeliculas(peliculas_t *lista){
    if(lista==NULL){
        printf("No hay peliculas almacenadas");
        retrn;
    }
    peliculas_t *actual = lista;
    printf("---- LISTA DE PELICULAS ----");
    while(actual!=NULL){
        printf("Nombre : %s, año: %d\n", actual->nombre, actual->anio);
        actual=actual->next;
    }
    printf("\n");
}

void cantidadPeliculas(peliculas_t *lista){
    int contador = 0;
    pleiculas_t *actual = lista;
    while(actual!=NULL){
        contador++;
        actual=actual->next;
    }
    printf("La cantidad de peliculas almacenadas es: %d", contador);
}

void menu(peliculas_t *lista){
    do{
        int opcion;
        
        printf("---- Almacenamiento de peliculas ----");
        printf("1. Agregar pelicula");
        printf("2. Mostrar peliculas");
        printf("3. Cantidad de peliculas");
        printf("4. Salir");
        scanf("%d", &opcion);
    
        switch(opcion){
            case 1:
            peliculas_t *nuevaPeli = crearPelicula();
            break
        
            case 2:
            mostrarPelicula();
            break
        
            case 3:
            cantidadPeliculas();
            break
        
            case 4:
            printf("Saliendo del programa...\n");
            break
        
            default:
            printf("Opcion no valida");
        }
    }while(opcion != 4);    
}
