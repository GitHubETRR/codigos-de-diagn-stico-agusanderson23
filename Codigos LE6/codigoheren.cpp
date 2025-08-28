#include <iostream>
using namespace std;

class Animal {
public:
    virtual void hacerSonido() {
        cout << "El animal hace un sonido." << endl;
    }
    virtual ~Animal() {} 
};

class Perro : public Animal {
public:
    void hacerSonido() override {
        cout << "El perro dice: ¡Guau!" << endl;
    }
};


class Gato : public Animal {
public:
    void hacerSonido() override {
        cout << "El gato dice: ¡Miau!" << endl;
    }
};

int main() {

    Animal* miAnimal1 = new Perro();
    Animal* miAnimal2 = new Gato();

    miAnimal1->hacerSonido();
    miAnimal2->hacerSonido(); 

    delete miAnimal1;
    delete miAnimal2;

    return 0;
}
