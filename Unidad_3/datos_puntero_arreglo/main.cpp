#include <iostream>
#include <limits>
#include <string>
#include "datos_puntero_arreglo.h"

using namespace std;

int pedirEntero(string mensaje) {
    int valor;

    while (true) {
        cout << mensaje;

        if (cin >> valor) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }

        cout << "Entrada invalida. Ingresa un numero.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

char pedirGenero() {
    string texto;

    while (true) {
        cout << "Genero (M/F): ";
        getline(cin, texto);

        if (texto.size() > 0) {
            return texto[0];
        }

        cout << "Entrada invalida.\n";
    }
}

int main() {
    DatosPunteroArreglo d;
    int opcion;
    bool continuar = true;

    do {
        cout << "\nMENU\n";
        cout << "1. Agregar persona\n";
        cout << "2. Mostrar personas\n";
        cout << "3. Verificar si esta vacio\n";
        cout << "4. Verificar si esta lleno\n";
        cout << "5. Mostrar tamano\n";
        cout << "6. Guardar\n";
        cout << "7. Salir\n";
        cout << "Opcion: ";

        if (!(cin >> opcion)) {
            cout << "Opcion invalida\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1: {
                if (d.lleno()) {
                    cout << "No puedes agregar, lista llena\n";
                } else {
                    Persona p;

                    cout << "Nombre: ";
                    getline(cin, p.nombre);

                    cout << "Apellido paterno: ";
                    getline(cin, p.ap);

                    cout << "Apellido materno: ";
                    getline(cin, p.am);

                    p.genero = pedirGenero();
                    p.edad = pedirEntero("Edad: ");

                    if (d.agregarPersona(p)) {
                        cout << "Persona agregada\n";
                    }
                }
                break;
            }

            case 2:
                d.mostrarPersonas();
                break;

            case 3:
                if (d.vacio())
                    cout << "La lista esta vacia\n";
                else
                    cout << "La lista NO esta vacia\n";
                break;

            case 4:
                if (d.lleno())
                    cout << "La lista esta llena\n";
                else
                    cout << "La lista NO esta llena\n";
                break;

            case 5:
                cout << "Tamano actual: " << d.tamanio() << endl;
                break;

            case 6:
                d.guardarArchivos();
                break;

            case 7:
                continuar = false;
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida\n";
        }

    } while (continuar);

    return 0;
}
