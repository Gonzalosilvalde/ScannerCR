#include <iostream>

using namespace std;

// Declaración de una clase en C++
class Persona {
public:
    string nombre;
    int edad;
    
    Persona(string _nombre, int _edad) {
        nombre = _nombre;
        edad = _edad;
    }
    
    void saludar() {
        cout << "Hola, mi nombre es " << nombre << " y tengo " << edad << " años." << endl;
    }
};

int main() {
    Persona p("Juan", 30);
    p.saludar();
    
    return 0;
}