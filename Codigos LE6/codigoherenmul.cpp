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

class Mascota : public virtual SerVivo {
public:
    virtual void mostrarCarino() {
        cout << "La mascota muestra cariño" << endl;
    }
    virtual ~Mascota() {}
};

class Perro : public Animal, public Mascota {
public:
    void hacerSonido() override {
        cout << "El perro dice Guau" << endl;
    }

    void mostrarCarino() override {
        cout << "El perro mueve la cola" << endl;
    }

    void existir() override {
        cout << "El perro vive feliz" << endl;
    }
};

class Gato : public Animal, public Mascota {
public:
    void hacerSonido() override {
        cout << "El gato dice Mia!" << endl;
    }

    void mostrarCarino() override {
        cout << "El gato se frota contra tu pierna" << endl;
    }

    void existir() override {
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
