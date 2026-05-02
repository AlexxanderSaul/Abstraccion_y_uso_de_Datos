#include "lista_lib_nd.h"
#include <iostream>
using namespace std;

bool ListaLibNd::ins(Dato d) {

    if (lleno()) {
        cout << "Lista llena\n";
        return false;
    }

    for (auto x : lista) {
        if (x.valor == d.valor) {
            cout << "Ese valor ya esta en la lista\n";
            return false;
        }
    }

    lista.push_back(d);
    return true;
}

void ListaLibNd::eli(int v) {

    if (vacio()) {
        cout << "Lista vacia\n";
        return;
    }

    bool eliminado = false;

    for (auto it = lista.begin(); it != lista.end(); ) {
        if (it->valor == v) {
            it = lista.erase(it);
            eliminado = true;
        } else {
            ++it;
        }
    }

    if (eliminado)
        cout << "Eliminado\n";
    else
        cout << "No encontrado\n";
}

void ListaLibNd::mos() {
    if (vacio()) {
        cout << "Lista vacia\n";
        return;
    }

    for (auto x : lista)
        cout << x.valor << " ";
    cout << endl;
}

bool ListaLibNd::vacio() {
    return lista.empty();
}

bool ListaLibNd::lleno() {
    return lista.size() == MAX;
}

int ListaLibNd::tamanio() {
    return lista.size();
}
