#include <iostream>
#include "digrafo.h"
using namespace std;

int main() {
    Digrafo g;

    // Nodos
    agregarNodo(g, 0, "Casa");
    agregarNodo(g, 1, "Acatitlan");
    agregarNodo(g, 2, "Santa marta");
    agregarNodo(g, 3, "Tepalcates");
    agregarNodo(g, 4, "Metrobus Tepalcates");
    agregarNodo(g, 5, "UPIICSA");

    // Rutas DIRIGIDAS: solo van en un sentido (de casa a la escuela)
    agregarConexion(g, 0, 1, "Casa-Acatitlan",        10.0f, 10.0f);
    agregarConexion(g, 1, 2, "Acatitlan-Santa marta",  8.0f,  0.0f);
    agregarConexion(g, 2, 3, "Santa marta-Tepalcates",  12.0f,  0.0f);
    agregarConexion(g, 3, 4, "Tepalcates-Metrobus Tepalcates",          7.0f,  0.0f);
    agregarConexion(g, 4, 5, "Metrobus Tepalcates-UPIICSA",           5.0f,  0.0f);

    int opcion;
    do {
        cout << "\nDIGRAFO\n" << endl;
        cout << "1. Mostrar digrafo" << endl;
        cout << "2. Ejecutar Dijkstra" << endl;
        cout << "3. Cargar desde XML" << endl;
        cout << "4. Cargar desde JSON" << endl;
        cout << "5. Guardar archivos" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: mostrarDigrafo(g); break;
            case 2: {
                int origen;
                cout << "Nodo origen (0=Casa, 5=UPIICSA): ";
                cin >> origen;
                dijkstra(g, origen);
                break;
            }
            case 3: { string f; cout << "Archivo XML: "; cin >> f; leerDesdeXML(g, f); break; }
            case 4: { string f; cout << "Archivo JSON: "; cin >> f; leerDesdeJSON(g, f); break; }
            case 5: guardarSalidas(g); break;
            case 0: cout << "Saliendo..." << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);

    return 0;
}
