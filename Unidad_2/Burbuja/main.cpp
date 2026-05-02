#include <iostream>
#include <locale>
#include "burbuja.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "");

    Burbuja obj;

    int opcion;
    bool continuar = true;

    do {
        cout << "\nMENU\n";
        cout << "1. Leer archivo\n";
        cout << "2. Ordenar (Burbuja)\n";
        cout << "3. Guardar archivo\n";
        cout << "4. Mostrar\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {

            case 1:
                if (obj.estaLeido()) {
                    cout << "El archivo ya fue leido\n";
                } else {
                    obj.leerArchivo();
                }
                break;

            case 2:
                if (!obj.estaLeido()) {
                    cout << "Primero debes leer el archivo\n";
                } else if (obj.estaOrdenado()) {
                    cout << "El archivo ya esta ordenado\n";
                } else {
                    obj.ordenarBurbuja();
                }
                break;

            case 3:
                if (!obj.estaLeido()) {
                    cout << "Primero debes leer el archivo\n";
                } else if (!obj.estaOrdenado()) {
                    cout << "Debes ordenar antes de guardar\n";
                } else {
                    obj.guardarArchivo();
                }
                break;

            case 4:
                if (!obj.estaLeido()) {
                    cout << "Primero debes leer el archivo\n";
                } else {
                    obj.mostrarArreglo();
                }
                break;

            case 5:
                if (!obj.estaLeido()) {
                    cout << "Debes leer el archivo antes de salir\n";
                } else if (!obj.salir()) {
                    cout << "Debes guardar antes de salir\n";
                } else {
                    continuar = false;
                }
                break;

            default:
                cout << "Opcion invalida\n";
        }

    } while (continuar);

    return 0;
}
