#include "lista_arr.h"
#include <iostream>
using namespace std;

ListaArr::ListaArr() {
    tam = 0;
}

void ListaArr::ins(int v) {
    if (lleno()) {
        cout << "Lista llena\n";
        return;
    }
    datos[tam++] = v;
}

void ListaArr::eli(int v) {
    if (vacio()) {
        cout << "Lista vacia\n";
        return;
    }

    for (int i = 0; i < tam; i++) {
        if (datos[i] == v) {
            for (int j = i; j < tam - 1; j++)
                datos[j] = datos[j + 1];
            tam--;
            cout << "Eliminado\n";
            return;
        }
    }
    cout << "No encontrado\n";
}

void ListaArr::mos() {
    if (vacio()) {
        cout << "Lista vacia\n";
        return;
    }

    for (int i = 0; i < tam; i++)
        cout << datos[i] << " ";
    cout << endl;
}

bool ListaArr::vacio() {
    return tam == 0;
}

bool ListaArr::lleno() {
    return tam == MAX;
}

int ListaArr::tamanio() {
    return tam;
}
