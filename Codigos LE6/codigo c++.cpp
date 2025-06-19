#include <iostream>
#include <string>

#define AGREGAR_PER 1
#define MOSTRAR_PER 2
#define SALIR 3

using namespace std;

class persona {
private:
    string nombre;
    int edad;

public:
    void setDatos(string nuevoNombre, int nuevaEdad);
    void getDatos(string& nombreOut, int& edadOut);
    void cargarDatos();
    void mostrarDatos();
};

void menu();

int main() {
    menu();
    return 0;
}


void persona::setDatos(string nuevoNombre, int nuevaEdad) {
    nombre = nuevoNombre;
    edad = nuevaEdad;
}

void persona::getDatos(string& nombreOut, int& edadOut) {
    nombreOut = nombre;
    edadOut = edad;
}

void persona::cargarDatos() {
    string inputNombre;
    int inputEdad;

    cout << "Ingrese el nombre y apellido de la persona: ";
    cin >> inputNombre;
    cout << "Ingrese la edad de la persona: ";
    cin >> inputEdad;

    setDatos(inputNombre, inputEdad);
}

void persona::mostrarDatos() {
    string nombreMostrado;
    int edadMostrada;

    getDatos(nombreMostrado, edadMostrada);

    cout << "\n--- Datos de la persona ---\n";
    cout << "Nombre y apellido: " << nombreMostrado << endl;
    cout << "Edad: " << edadMostrada << endl;
}

void menu() {
    persona Persona;
    int opcion;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Cargar datos de persona\n";
        cout << "2. Mostrar datos de persona\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case AGREGAR_PER:
                Persona.cargarDatos();
                break;

            case MOSTRAR_PER:
                Persona.mostrarDatos();
                break;

            case SALIR:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion no valida, intente nuevamente.\n";
        }
    } while (opcion != 3);
}
