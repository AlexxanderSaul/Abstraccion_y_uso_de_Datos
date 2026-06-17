#include <iostream>
#include "matrices.h"
using namespace std;

int main() {
    Matrices m;
    int opcion;
    bool continuar = true;

    do {
        cout << "\nMENU\n";
        cout << "1. Ingresar matriz A\n";
        cout << "2. Ingresar matriz B\n";
        cout << "3. Mostrar matriz A\n";
        cout << "4. Mostrar matriz B\n";
        cout << "5. A * constante\n";
        cout << "6. A * B\n";
        cout << "7. Guardar\n";
        cout << "8. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: m.leerMatrizA(); break;
            case 2: m.leerMatrizB(); break;
            case 3: m.mostrarMatrizA(); break;
            case 4: m.mostrarMatrizB(); break;
            case 5: m.multiplicarPorConstante(); break;
            case 6: m.multiplicarMatrices(); break;
            case 7: m.guardarArchivos(); break;
            case 8: continuar = false; cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida\n";
        }
    } while (continuar);

    return 0;
}
