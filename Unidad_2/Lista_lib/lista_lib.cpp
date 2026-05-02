#include "lista_lib.h"
#include <iostream>
using namespace std;

bool ListaLib::ins(int v) {

    if (lleno()) {
        cout << "Lista llena\n";
        return false;
    }

    for (int x : lista) {
        if (x == v) {
            cout << "Ese valor ya esta en la lista\n";
            return false;
        }
    }

    lista.push_back(v);
    return true;
}

void ListaLib::eli(int v) {

    if (vacio()) {
        cout << "Lista vacia\n";
        return;
    }

    int antes = lista.size();
    lista.remove(v);

    if (lista.size() < antes)
        cout << "Eliminado\n";
    else
        cout << "No encontrado\n";
}

void ListaLib::mos() {
    if (vacio()) {
        cout << "Lista vacia\n";
        return;
    }

    for (int x : lista)
        cout << x << " ";
    cout << endl;
}

bool ListaLib::vacio() {
    return lista.empty();
}

bool ListaLib::lleno() {
    return lista.size() == MAX;
}

int ListaLib::tamanio() {
    return lista.size();
}
