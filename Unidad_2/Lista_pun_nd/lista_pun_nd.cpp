#include "lista_pun_nd.h"
#include <iostream>
using namespace std;

ListaPunNd::ListaPunNd() {
    cabeza = NULL;
    tam = 0;
}

bool ListaPunNd::ins(Dato d) {

    if (lleno()) {
        cout << "Lista llena\n";
        return false;
    }

    Nodo* aux = cabeza;
    while (aux) {
        if (aux->dato.valor == d.valor) {
            cout << "Ese valor ya esta en la lista\n";
            return false;
        }
        aux = aux->sig;
    }

    Nodo* nuevo = new Nodo{d, NULL};

    if (!cabeza) {
        cabeza = nuevo;
    } else {
        Nodo* aux2 = cabeza;
        while (aux2->sig)
            aux2 = aux2->sig;
        aux2->sig = nuevo;
    }

    tam++;
    return true;
}

void ListaPunNd::eli(int v) {

    if (vacio()) {
        cout << "Lista vacia\n";
        return;
    }

    if (cabeza->dato.valor == v) {
        Nodo* aux = cabeza;
        cabeza = cabeza->sig;
        delete aux;
        tam--;
        cout << "Eliminado\n";
        return;
    }

    Nodo* aux = cabeza;
    while (aux->sig && aux->sig->dato.valor != v)
        aux = aux->sig;

    if (aux->sig) {
        Nodo* temp = aux->sig;
        aux->sig = temp->sig;
        delete temp;
        tam--;
        cout << "Eliminado\n";
    } else {
        cout << "No encontrado\n";
    }
}

void ListaPunNd::mos() {

    if (vacio()) {
        cout << "Lista vacia\n";
        return;
    }

    Nodo* aux = cabeza;
    while (aux) {
        cout << aux->dato.valor << " ";
        aux = aux->sig;
    }
    cout << endl;
}

bool ListaPunNd::vacio() {
    return cabeza == NULL;
}

bool ListaPunNd::lleno() {
    return tam == MAX;
}

int ListaPunNd::tamanio() {
    return tam;
}
