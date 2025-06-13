#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 50
#define ARCHIVO "alumnos.txt"

#define OPC_INGRESAR 1
#define OPC_MOSTRAR 2
#define OPC_BORRAR 3
#define OPC_SALIR 4

typedef struct {
    char nombre[MAX_NOMBRE];
    char apellido[MAX_NOMBRE];
    int edad;
    float promedio;
} Estudiante;

void ingresarEstudiantes();
void mostrarEstudiantes();
void borrarArchivo();
void menu();

int main() {
    menu();
    return 0;
}
void menu(){
    int opcion;

    do {
        printf("\n--- MENÚ ---\n");
        printf("%d. Ingresar estudiantes (se agregan al archivo)\n", OPC_INGRESAR);
        printf("%d. Mostrar estudiantes (desde archivo)\n", OPC_MOSTRAR);
        printf("%d. Borrar todo el archivo\n", OPC_BORRAR);
        printf("%d. Salir\n", OPC_SALIR);
        printf("Elegí una opción: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case OPC_INGRESAR:
                ingresarEstudiantes();
                break;
            case OPC_MOSTRAR:
                mostrarEstudiantes();
                break;
            case OPC_BORRAR:
                borrarArchivo();
                break;
            case OPC_SALIR:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción invalida\n");
        }
    } while (opcion != OPC_SALIR);
}

void ingresarEstudiantes() {
    FILE *archivo = fopen(ARCHIVO, "w"); 
    if (archivo == NULL) {
        printf("Error al abrir el archivo para agregar\n");
        return;
    }

    int cantidad;
    printf("¿Cuántos estudiantes queres ingresar?: ");
    scanf("%d", &cantidad);
    getchar();

    Estudiante est;
    for (int i = 0; i < cantidad; i++) {
        printf("\nEstudiante %d\n", i + 1);
        printf("Nombre: ");
        fgets(est.nombre, MAX_NOMBRE, stdin);

        printf("Apellido: ");
        fgets(est.apellido, MAX_NOMBRE, stdin);

        printf("Edad: ");
        scanf("%d", &est.edad);
        getchar();

        printf("Promedio: ");
        scanf("%f", &est.promedio);
        getchar();
        
        fprintf(archivo, "%s %s %d %.2f\n", est.nombre, est.apellido, est.edad, est.promedio);
    }

    fclose(archivo);
    printf("Estudiantes agregados correctamente al archivo '%s'.\n", ARCHIVO);
}

void mostrarEstudiantes() {
    FILE *archivo = fopen(ARCHIVO, "r");
    if (archivo == NULL) {
        printf("No hay estudiantes guardados o no se pudo abrir el archivo\n");
        return;
    }

    Estudiante est;
    int contador = 0;

    printf("\n--- ESTUDIANTES EN EL ARCHIVO ---\n");
    while (fscanf(archivo, "%s %s %d %f",
                  est.nombre, est.apellido, &est.edad, &est.promedio) == 4) {
        contador++;
        printf("%d) %s %s - Edad: %d - Promedio: %.2f\n",
               contador, est.nombre, est.apellido, est.edad, est.promedio);
    }

    if (contador == 0) {
        printf("No hay estudiantes guardados \n");
    }

    fclose(archivo);
}

void borrarArchivo() {
    FILE *archivo = fopen(ARCHIVO, "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para borrar\n");
        return;
    }
    fclose(archivo);
    printf("Archivo '%s' vaciado\n", ARCHIVO);
}
