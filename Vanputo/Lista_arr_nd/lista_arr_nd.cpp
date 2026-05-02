#include "lista_arr_nd.h"
#include <iostream>
using namespace std;

ListaArrNd::ListaArrNd() {
    tam = 0;
}

bool ListaArrNd::ins(Dato d) {

    if (lleno()) {
        cout << "Lista llena\n";
        return false;
    }

    for (int i = 0; i < tam; i++) {
        if (datos[i].valor == d.valor) {
            cout << "Ese valor ya esta en la lista\n";
            return false;
        }
    }

    datos[tam++] = d;
    return true;
}

void ListaArrNd::eli(int v) {

    if (vacio()) {
        cout << "Lista vacia\n";
        return;
    }

    for (int i = 0; i < tam; i++) {
        if (datos[i].valor == v) {
            for (int j = i; j < tam - 1; j++)
                datos[j] = datos[j + 1];
            tam--;
            cout << "Eliminado\n";
            return;
        }
    }

    cout << "No encontrado\n";
}

void ListaArrNd::mos() {
    if (vacio()) {
        cout << "Lista vacia\n";
        return;
    }

    for (int i = 0; i < tam; i++)
        cout << datos[i].valor << " ";
    cout << endl;
}

bool ListaArrNd::vacio() {
    return tam == 0;
}

bool ListaArrNd::lleno() {
    return tam == MAX;
}

int ListaArrNd::tamanio() {
    return tam;
}
