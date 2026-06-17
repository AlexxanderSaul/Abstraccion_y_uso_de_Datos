#include <iostream>
#include "Arbol.h"
using namespace std;

int main() {
    Arbol a;

    // Nodos: paradas de la ruta
    agregarNodo(a, 0, "Casa");
    agregarNodo(a, 1, "Acatitlan");
    agregarNodo(a, 2, "Santa marta");
    agregarNodo(a, 3, "Tepalcates");
    agregarNodo(a, 4, "Metrobus tepalcates");
    agregarNodo(a, 5, "UPIICSA");

    // Rutas / conexionNodo2Nodo
    agregarConexion(a, 0, 1, "Casa-Acatitlan",        10.0f, 10.0f);
    agregarConexion(a, 1, 2, "Acatitlan-Santa marta",  8.0f,  0.0f);
    agregarConexion(a, 2, 3, "Santa marta-Tepalcates",  12.0f,  0.0f);
    agregarConexion(a, 3, 4, "Tepalcates-Metrobus tepalcates",          7.0f,  0.0f);
    agregarConexion(a, 4, 5, "Metrobus tepalcates-UPIICSA",           5.0f,  0.0f);

    int opcion;
    do {
        cout << "\nARBOL\n" << endl;
        cout << "1. Mostrar arbol (nodos, aristas, rutas y recorridos)" << endl;
        cout << "2. Ejecutar Dijkstra" << endl;
        cout << "3. Cargar desde XML" << endl;
        cout << "4. Cargar desde JSON" << endl;
        cout << "5. Guardar archivos" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: mostrarArbol(a); break;
            case 2: {
                int origen;
                cout << "Nodo origen (0=Casa ... 5=UPIICSA): ";
                cin >> origen;
                dijkstra(a, origen);
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
