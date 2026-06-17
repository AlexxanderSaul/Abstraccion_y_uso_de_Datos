#include <iostream>
#include "tamanios_datos.h"
using namespace std;

int main() {
    TamaniosDatos t;
    int opcion;
    bool continuar = true;

    do {
        cout << "\nMENU\n";
        cout << "1. Mostrar memoria de los primeros 8 tipos de datos\n";
        cout << "2. Guardar\n";
        cout << "3. Salir\n";
        cout << "Opcion: "; cin >> opcion;

        switch (opcion) {
            case 1: t.mostrarBasicos(); break;
            case 2: t.guardarArchivos(); break;
            case 3: continuar = false; cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida\n";
        }
    } while (continuar);

    return 0;
}
