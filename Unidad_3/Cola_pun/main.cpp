#include <iostream>
#include "cola_pun.h"
using namespace std;

int main() {
    cola_pun c;
    int opcion, valor;
    bool continuar = true;

    do {
        cout << "\nMENU\n";
        cout << "1. Agregar (enq)\n";
        cout << "2. Eliminar (deq)\n";
        cout << "3. Mostrar cola\n";
        cout << "4. Verificar si esta vacia\n";
        cout << "5. Mostrar tamaño\n";
        cout << "6. Guardar\n";
        cout << "7. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Ingresa el valor: ";
                cin >> valor;
                if (c.enq(valor)) cout << "Valor agregado\n";
                break;

            case 2:
                if (c.vacio()) cout << "No puedes eliminar, cola vacia\n";
                else c.deq();
                break;

            case 3:
                c.mos();
                break;

            case 4:
                cout << (c.vacio() ? "La cola esta vacia\n" : "La cola no esta vacia\n");
                break;

            case 5:
                cout << "Tamano actual: " << c.tamanio() << endl;
                break;

            case 6:
                c.guardarArchivo();
                break;

            case 7:
                continuar = false;
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida\n";
        }

    } while(continuar);

    return 0;
}
