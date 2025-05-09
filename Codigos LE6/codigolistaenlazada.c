#include <stdio.h>
#include <stdlib.h>

#define MAXNOMBRE 20
#define VALORERROR -1

typedef struct peliculas {
    char nombre[MAXNOMBRE];
    int anio;
    struct peliculas *next;
} peliculas_t;

peliculas_t *crearPelicula();
void mostrarPeliculas(peliculas_t *lista);
void cantidadPeliculas(peliculas_t *lista);
void menu(peliculas_t *lista);
void liberarMemoria(peliculas_t *lista);
peliculas_t *agregarPelicula(peliculas_t *lista);

int main() {
    peliculas_t *lista = NULL;
    menu(lista);
    return 0;
}

peliculas_t* crearPelicula() {
    peliculas_t *nuevaPeli = (peliculas_t *)malloc(sizeof(peliculas_t));
    if (nuevaPeli == NULL) {
        printf("Error al asignar memoria\n");
        exit(VALORERROR);
    }
    printf("Ingrese el nombre de la pelicula: ");
    scanf("%s", nuevaPeli->nombre);
    printf("Ingrese el año de lanzamiento: ");
    scanf("%d", &nuevaPeli->anio);
    nuevaPeli->next = NULL;
    return nuevaPeli;
}

void mostrarPeliculas(peliculas_t *lista) {
    if (lista == NULL) {
        printf("No hay peliculas almacenadas.\n");
        return;
    }
    peliculas_t *actual = lista;
    printf("---- LISTA DE PELICULAS ----\n");
    while (actual != NULL) {
        printf("Nombre: %s, Año: %d\n", actual->nombre, actual->anio);
        actual = actual->next;
    }
}

void cantidadPeliculas(peliculas_t *lista) {
    int contador = 0;
    peliculas_t *actual = lista;
    while (actual != NULL) {
        contador++;
        actual = actual->next;
    }
    printf("La cantidad de peliculas almacenadas es: %d\n", contador);
}

void liberarMemoria(peliculas_t *lista) {
    peliculas_t *aux = NULL;
    while (lista != NULL) {
        aux = lista;
        lista = lista->next;
        free(aux);
    }
    printf("Memoria liberada correctamente.\n");
}

peliculas_t *agregarPelicula(peliculas_t *lista) {
    peliculas_t *nuevaPeli = crearPelicula();
    if (lista == NULL) {
        return nuevaPeli;
    } else {
        peliculas_t *aux = lista;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = nuevaPeli;
        return lista;
    }
}

void menu(peliculas_t *lista) {
    int opcion;
    do {
        printf("\n---- Almacenamiento de peliculas ----\n");
        printf("1. Agregar pelicula\n");
        printf("2. Mostrar peliculas\n");
        printf("3. Cantidad de peliculas\n");
        printf("4. Eliminar lista\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                lista = agregarPelicula(lista);
                break;
            case 2:
                mostrarPeliculas(lista);
                break;
            case 3:
                cantidadPeliculas(lista);
                break;
            case 4:
                liberarMemoria(lista);
                lista = NULL;
                break;
            case 5:
                liberarMemoria(lista);
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida\n");
        }
    } while (opcion != 5);
}
