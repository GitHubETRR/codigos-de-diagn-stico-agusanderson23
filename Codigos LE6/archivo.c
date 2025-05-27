#include <stdio.h>
#include <stdlib.h>

#define VALOR_ERROR -1
#define MAX_CHAR 100

void llenarArchivo();
void leerArchivo();

int main(){
    char linea1[MAX_CHAR];
    char linea2[MAX_CHAR];
}

void llenarArchivo(){

    FILE *archivo
    archivo=fopen("datos.txt", "w");
    if(archivo==NULL){
        printf("No se pudo abrir el archivo \n");
        exit(VALOR_ERROR);
    }else{
        printf("Ingrese lo que desea guardar en la linea 1 del archivo \n");
        scanf("%s", linea1);
        printf("Ingrese lo que desea guardar en la linea 2 del archivo\n");
        scanf("%s", linea2);
        
        fprintf(archivo, "%s \n %s", linea1, linea2);
        
    }
}
