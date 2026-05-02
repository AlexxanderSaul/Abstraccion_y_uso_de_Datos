#include <iostream>
#include <locale>
#include "quick.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "");

    Quick q;

    int opcion;
    bool continuar = true;

    do {
        cout << "\nMENU\n";
        cout << "1. Leer archivo\n";
        cout << "2. Ordenar (QuickSort)\n";
        cout << "3. Guardar archivo\n";
        cout << "4. Mostrar\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {

            case 1:
                if (q.estaLeido()) {
                    cout << "El archivo ya fue leido\n";
                } else {
                    q.leerArchivo();
                }
                break;

            case 2:
                if (!q.estaLeido()) {
                    cout << "Primero debes leer el archivo\n";
                } else if (q.estaOrdenado()) {
                    cout << "El archivo ya esta ordenado\n";
                } else {
                    q.ordenarQuickSort();
                }
                break;

            case 3:
                if (!q.estaLeido()) {
                    cout << "Primero debes leer el archivo\n";
                } else if (!q.estaOrdenado()) {
                    cout << "Debes ordenar antes de guardar\n";
                } else {
                    q.guardarArchivo();
                }
                break;

            case 4:
                if (!q.estaLeido()) {
                    cout << "Primero debes leer el archivo\n";
                } else {
                    q.mostrarArreglo();
                }
                break;

            case 5:
                if (!q.estaLeido()) {
                    cout << "Debes leer el archivo antes de salir\n";
                } else if (!q.salir()) {
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
