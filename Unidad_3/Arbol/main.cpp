#include <iostream>
#include "Arbol.h"
using namespace std;

int main() {
    Arbol a;

    int opcion;
    do {
        cout << "\nArbol\n";
        cout << "1. Mostrar arbol (nodos, aristas, rutas y recorridos)" << endl;
        cout << "2. Buscar nodo por ID" << endl;
        cout << "3. Cargar desde XML" << endl;
        cout << "4. Cargar desde JSON" << endl;
        cout << "5. Guardar archivos" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: mostrarArbol(a); break;
            case 2: {
                int id;
                cout << "Ingrese el ID a buscar: ";
                cin >> id;
                busquedaBinaria(a.raiz, id);
                break;
            }
            case 3: { string f; cout << "Archivo XML: "; cin >> f; leerDesdeXML(a, f); break; }
            case 4: { string f; cout << "Archivo JSON: "; cin >> f; leerDesdeJSON(a, f); break; }
            case 5: guardarSalidas(a); break;
            case 0: cout << "Saliendo..." << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);

    return 0;
}
