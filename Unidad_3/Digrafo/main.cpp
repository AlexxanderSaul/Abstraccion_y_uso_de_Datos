#include <iostream>
#include "digrafo.h"
using namespace std;

int main() {
    Digrafo g;


    int opcion;
    do {
        cout << "\nDIGRAFO\n";
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
