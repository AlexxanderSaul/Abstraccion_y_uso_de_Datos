#include <iostream>
#include "pila.h"
using namespace std;

int main() {
    pila_arr p;
    int op, val;

    do {
        cout << "\nMenu\n";
        cout << "1. Push (Insertar)\n";
        cout << "2. Pop (Eliminar)\n";
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
                p.push(val);
                break;

            case 2:
                if (p.vacia()) {
                    cout << "La pila esta vacia, no se puede eliminar.\n";
                } else {
                    p.pop();
                }
                break;

            case 3:
                p.mos();
                break;

            case 4:
                cout << (p.vacia() ? "Esta vacia\n" : "No esta vacia\n");
                break;

            case 5:
                cout << (p.llena() ? "Esta llena\n" : "No esta llena\n");
                break;

            case 6:
                cout << "Tamaño de la pila: " << p.tam() << endl;
                break;
        }

    } while (op != 7);

    return 0;
}
