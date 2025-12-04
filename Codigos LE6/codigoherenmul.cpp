#include <iostream>
using namespace std;


class SerVivo {
public:
    virtual void existir() {
        cout << "El ser vivo existe." << endl;
    }
    virtual ~SerVivo() {}
};


class Animal : public virtual SerVivo {
public:
    virtual void hacerSonido() {
        cout << "El animal hace un sonido" << endl;
    }
    virtual ~Animal() {}
};

class Mascota : public SerVivo {
public:
    virtual void mostrarCarino() {
        cout << "La mascota muestra cariño" << endl;
    }
    virtual ~Mascota() {}
};

class Perro : public Animal, public Mascota {
public:
    void hacerSonido(){
        cout << "El perro dice Guau" << endl;
    }

    void mostrarCarino(){
        cout << "El perro mueve la cola" << endl;
    }

    void existir(){
        cout << "El perro vive feliz" << endl;
    }
};

class Gato : public Animal, public Mascota {
public:
    void hacerSonido(){
        cout << "El gato dice Mia!" << endl;
    }

    void mostrarCarino(){
        cout << "El gato se frota contra tu pierna" << endl;
    }

    void existir() {
        cout << "El gato vive tranquilo" << endl;
    }
};

int main() {
    SerVivo* miAnimal1 = new Perro();
    SerVivo* miAnimal2 = new Gato();

    miAnimal1->existir();
    miAnimal2->existir();

    delete miAnimal1;
    delete miAnimal2;

    return 0;
}
