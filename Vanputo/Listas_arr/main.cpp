#include <iostream>
#include "lista_arr.h"
using namespace std;

int main() {
    ListaArr l;
    int opcion, valor;
    bool continuar = true;

    do {
        cout << "\nMENU\n";
        cout << "1. Agregar\n";
        cout << "2. Eliminar\n";
        cout << "3. Mostrar la lista\n";
        cout << "4. Verificar si esta vacio\n";
        cout << "5. Verificar si esta lleno\n";
        cout << "6. Mostrar tamaño\n";
        cout << "7. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {

            case 1:
                if (l.lleno()) {
                    cout << "No puedes agregar, lista llena\n";
                } else {
                    cout << "Valor: ";
                    cin >> valor;
                    l.ins(valor);
                }
                break;

            case 2:
                if (l.vacio()) {
                    cout << "No puedes eliminar, lista vacia\n";
                } else {
                    cout << "Valor a eliminar: ";
                    cin >> valor;
                    l.eli(valor);
                }
                break;

            case 3:
                if (l.vacio()) {
                    cout << "Lista vacia\n";
                } else {
                    l.mos();
                }
                break;

            case 4:
                if (l.vacio())
                    cout << "La lista esta vacia\n";
                else
                    cout << "La lista no esta vacia\n";
                break;

            case 5:
                if (l.lleno())
                    cout << "La lista esta llena\n";
                else
                    cout << "La lista no esta llena\n";
                break;

            case 6:
                cout << "Tamano actual: " << l.tamanio() << endl;
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
