#include <iostream>
#include "promedio_puntero.h"
using namespace std;

int main() {
    PromedioPuntero p;
    int opcion;
    bool continuar = true;

    do {
        cout << "\nMENU\n";
        cout << "1. Ingresar 5 numeros\n";
        cout << "2. Mostrar datos\n";
        cout << "3. Mostrar suma\n";
        cout << "4. Mostrar promedio/media\n";
        cout << "5. Mostrar maximo\n";
        cout << "6. Mostrar minimo\n";
        cout << "7. Guardar\n";
        cout << "8. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: p.leerDatos(); break;
            case 2: p.mostrarDatos(); break;
            case 3: if (p.estaVacio()) cout << "Primero ingrese los datos\n"; else cout << "Suma: " << p.suma() << endl; break;
            case 4: if (p.estaVacio()) cout << "Primero ingrese los datos\n"; else cout << "Promedio/media: " << p.promedio() << endl; break;
            case 5: if (p.estaVacio()) cout << "Primero ingrese los datos\n"; else cout << "Maximo: " << p.maximo() << endl; break;
            case 6: if (p.estaVacio()) cout << "Primero ingrese los datos\n"; else cout << "Minimo: " << p.minimo() << endl; break;
            case 7: p.guardarArchivos(); break;
            case 8: continuar = false; cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida\n";
        }
    } while (continuar);

    return 0;
}
