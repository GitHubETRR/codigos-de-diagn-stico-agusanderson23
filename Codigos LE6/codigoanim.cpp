#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Animal {
protected:
    string nombre;

public:
    Animal( string& nom) {
        nombre = nom;
    }

    virtual void hablar() {
        cout << nombre << " hace un sonido" << endl;
    }

    virtual string getTipo() {
        return "Animal";
    }

    string getNombre() {
        return nombre;
    }

    virtual ~Animal() {}
};

class Perro : public Animal {
public:
    Perro(string& nom) : Animal(nom) {}

    void hablar() {
        cout << nombre << " dice: ¡Guau!" << endl;
    }

    string getTipo() {
        return "Perro";
    }
};

class Gato : public Animal {
public:
    Gato(string& nom) : Animal(nom) {}

    void hablar(){
        cout << nombre << " dice: ¡Miau!" << endl;
    }

    string getTipo(){
        return "Gato";
    }
};

void mostrarMenu() {
    cout << "\n=== Menú ===\n";
    cout << "1. Agregar Perro\n";
    cout << "2. Agregar Gato\n";
    cout << "3. Mostrar Animales\n";
    cout << "4. Hacerlos hablar\n";
    cout << "5. Salir\n";
    cout << "Opción: ";
}

int main() {
    vector<Animal*> animales;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        string nombre;

        switch (opcion) {
            case 1:
                cout << "Nombre del perro: ";
                cin >> nombre;
                animales.push_back(new Perro(nombre));
                break;

            case 2:
                cout << "Nombre del gato: ";
                cin >> nombre;
                animales.push_back(new Gato(nombre));
                break;

            case 3:
                cout << "\nAnimales:\n";
                for (size_t i = 0; i < animales.size(); ++i) {
                    cout << i + 1 << ". " << animales[i]->getTipo()
                         << ": " << animales[i]->getNombre() << endl;
                }
                break;

            case 4:
                cout << "\nLos animales hablan:\n";
                for (size_t i = 0; i < animales.size(); ++i) {
                    animales[i]->hablar();
                }           
                break;

            case 5:
                cout << "Saliendo\n";
                break;

            default:
                cout << "Error, intente denuevo\n";
        }

    } while (opcion != 5);

    for (Animal* a : animales) {
        delete a;
    }

    return 0;
}
