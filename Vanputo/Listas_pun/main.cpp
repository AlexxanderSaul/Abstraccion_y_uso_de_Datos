#include <iostream>
#include "lista_pun.h"
using namespace std;

int main() {
    ListaPun l;
    int op, val;

    do {
        cout << "\nMENU\n";
        cout << "1. Insertar\n";
        cout << "2. Eliminar\n";
        cout << "3. Mostrar\n";
        cout << "4. Verificar si esta vacia\n";
        cout << "5. Verificar si esta llena\n";
        cout << "6. Mostrar tamaño\n";
        cout << "7. Salir\n";
        cout << "Opcion: ";
        cin >> op;

        switch (op) {
            case 1:
                cout << "Valor a insertar: ";
                cin >> val;
                l.ins(val);
                break;

            case 2:
                if (l.vacia()) {
                    cout << "La lista esta vacia, no se puede eliminar.\n";
                } else {
                    cout << "Valor a eliminar: ";
                    cin >> val;
                    l.eli(val);
                }
                break;

            case 3:
                l.mos();
                break;

            case 4:
                cout << (l.vacia() ? "Esta vacia\n" : "No esta vacia\n");
                break;

            case 5:
                cout << (l.llena() ? "Esta llena\n" : "No esta llena\n");
                break;

            case 6:
                cout << "Tamaño de la lista: " << l.tam() << endl;
                break;
        }

    } while (op != 7);

    return 0;
}
