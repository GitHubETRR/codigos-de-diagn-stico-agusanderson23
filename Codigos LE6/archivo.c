#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VALOR_ERROR -1
#define MAX_LINEA 100
#define MAX_NOMBRE 100

void llenarArchivo(const char *ptrArchivo);
void leerArchivo(const char *ptrArchivo);

int main(){
    char nombredelArchivo[MAX_NOMBRE];
    strcpy(nombredelArchivo, "texto.txt");
    
    llenarArchivo(nombredelArchivo);
    leerArchivo(nombredelArchivo);
}

void llenarArchivo(const char *ptrArchivo){

    FILE *archivo = fopen(ptrArchivo, "w");
    if(archivo==NULL){
        printf("No se pudo abrir el archivo \n");
        exit(VALOR_ERROR);
    }else{
        int cantidad;
        printf("¿Cuantas lineas desea ingresar? : ");
        scanf("%d", &cantidad);
        getchar();
        
        char linea[MAX_LINEA];
        for(int i = 0; i < cantidad; i++){
            printf("Linea %d : ", i + 1);
            fgets(linea, sizeof(linea), stdin);
            fputs(linea, archivo);
        }
        fclose(archivo);
    }
}

void leerArchivo(const char *ptrArchivo){
    FILE *archivo = fopen(ptrArchivo, "r");
    if(archivo==NULL){
        printf("Error al abrir el archivo");
        exit(VALOR_ERROR);
    }else{
        char linea[MAX_LINEA];
        printf("Contenido del archivo: \n");
        while(fgets(linea, sizeof(linea), archivo)){
            printf("%s", linea);
        }
        fclose(archivo);
    }
}
