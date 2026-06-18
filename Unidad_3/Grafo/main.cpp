#include <iostream>
#include "Lib_grafo.h"
using namespace std;

int main() {
    Grafo g;

    int opcion;
    do {
        cout << "\nGrafo\n";
        cout << "1. Mostrar grafo" << endl;
        cout << "2. Ejecutar Dijkstra" << endl;
        cout << "3. Cargar desde XML" << endl;
        cout << "4. Cargar desde JSON" << endl;
        cout << "5. Guardar archivos" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarGrafo(g);
                break;
            case 2: {
                int origen;
                cout << "Nodo origen (0=Casa, 5=UPIICSA): ";
                cin >> origen;
                dijkstra(g, origen);
                break;
            }
            case 3: {
                string archivo;
                cout << "Nombre del archivo XML: ";
                cin >> archivo;
                leerDesdeXML(g, archivo);
                break;
            }
            case 4: {
                string archivo;
                cout << "Nombre del archivo JSON: ";
                cin >> archivo;
                leerDesdeJSON(g, archivo);
                break;
            }
            case 5:
                guardarSalidas(g);
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);

    return 0;
}
