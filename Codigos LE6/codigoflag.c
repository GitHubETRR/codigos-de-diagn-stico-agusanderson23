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
    } bits;
    char valor;
};

void mostrarBits(union flag bandera);

int main() {
    union flag bandera;
    
    printf("Ingrese un valor (0-255): ");
    scanf("%d", &bandera.valor);
    
    mostrarBits(bandera);
    
    return 0;
}
void mostrarBits(union flag bandera) {
    printf("Estado de los bits: %d%d%d%d%d%d%d%d\n",
           bandera.bits.bit7, bandera.bits.bit6, bandera.bits.bit5, bandera.bits.bit4,
           bandera.bits.bit3, bandera.bits.bit2, bandera.bits.bit1, bandera.bits.bit0);
}