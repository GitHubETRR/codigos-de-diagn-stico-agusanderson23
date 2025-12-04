#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string ARCHIVO = "datos.txt";

void agregar() {
    ofstream f(ARCHIVO, ios::app); 
    if (!f.is_open()) {
        cout << "Error abriendo archivo.\n";
        return;
    }

    string nombre;
    int edad;

    cout << "Nombre: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Edad: ";
    cin >> edad;

    f << nombre << ";" << edad << "\n";
    f.close();

    cout << "Guardado\n";
}

void mostrar() {
    ifstream f(ARCHIVO);
    if (!f.is_open()) {
        cout << "No hay archivo todavia\n";
        return;
    }

    string linea;
    cout << "Contenido del archivo\n";
    while (getline(f, linea)) {
        cout << linea << endl;
    }
    f.close();
}

int main() {
    int opcion;

    do {
        cout << "\n MENU \n";
        cout << "1 - Agregar estudiante\n";
        cout << "2 - Mostrar archivo\n";
        cout << "3 - Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) agregar();
        else if (opcion == 2) mostrar();

    } while (opcion != 3);

    return 0;
}
