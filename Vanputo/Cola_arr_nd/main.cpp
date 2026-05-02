#include <iostream>
#include "cola_arr_nd.h"
using namespace std;

int main() {
    cola_arr_nd c;
    int opcion;
    bool continuar = true;

    do {
        cout << "\nMENU\n";
        cout << "1. Agregar (enq)\n";
        cout << "2. Eliminar (deq)\n";
        cout << "3. Mostrar cola\n";
        cout << "4. Verificar si esta vacia\n";
        cout << "5. Verificar si esta llena\n";
        cout << "6. Mostrar tamaño\n";
        cout << "7. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {

            case 1:
                if (c.lleno()) {
                    cout << "No puedes agregar, cola llena\n";
                } else {
                    Dato d;
                    cout << "Ingresa el valor: ";
                    cin >> d.valor;

                    if (c.enq(d)) {
                        cout << "Valor agregado\n";
                    }
                }
                break;

            case 2:
                if (c.vacio()) {
                    cout << "No puedes eliminar, cola vacia\n";
                } else {
                    c.deq();
                }
                break;

            case 3:
                if (c.vacio()) {
                    cout << "Cola vacia\n";
                } else {
                    c.mos();
                }
                break;

            case 4:
                if (c.vacio())
                    cout << "La cola esta vacia\n";
                else
                    cout << "La cola no esta vacia\n";
                break;

            case 5:
                if (c.lleno())
                    cout << "La cola esta llena\n";
                else
                    cout << "La cola no esta llena\n";
                break;

            case 6:
                cout << "Tamano actual: " << c.tamanio() << endl;
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
