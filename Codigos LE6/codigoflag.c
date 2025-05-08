#include <stdio.h>

union flag {
    struct bits {
        unsigned int bit0 : 1;
        unsigned int bit1 : 1;
        unsigned int bit2 : 1;
        unsigned int bit3 : 1;
        unsigned int bit4 : 1;
        unsigned int bit5 : 1;
        unsigned int bit6 : 1;
        unsigned int bit7 : 1;
    }bits;
    char valor;
};

void mostrarBits(union flag *ptr);

int main() {
    union flag bandera;
    union flag *ptr = &bandera; 

    printf("Ingrese un valor (0-255): ");
    scanf("%d", &ptr->valor);  

    mostrarBits(ptr);

    return 0;
}

void mostrarBits(union flag *ptr) {
    printf("Estado de los bits: %d%d%d%d%d%d%d%d\n",
           ptr->bits.bit7, ptr->bits.bit6, ptr->bits.bit5, ptr->bits.bit4,
           ptr->bits.bit3, ptr->bits.bit2, ptr->bits.bit1, ptr->bits.bit0);
}
