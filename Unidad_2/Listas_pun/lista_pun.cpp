#include "lista_pun.h"
#include <iostream>
using namespace std;

ListaPun::ListaPun() {
    cabeza = NULL;
}

void ListaPun::ins(int v) {
    Nodo* aux = cabeza;

    while (aux) {
        if (aux->dato == v) {
            cout << "Ese valor ya existe en la lista.\n";
            return;
        }
        aux = aux->sig;
    }

    Nodo* nuevo = new Nodo{v, NULL};

    if (!cabeza) {
        cabeza = nuevo;
    } else {
        Nodo* temp = cabeza;
        while (temp->sig) temp = temp->sig;
        temp->sig = nuevo;
    }

    cout << "Valor insertado correctamente.\n";
}

void ListaPun::eli(int v) {
    if (!cabeza) return;

    if (cabeza->dato == v) {
        Nodo* aux = cabeza;
        cabeza = cabeza->sig;
        delete aux;
        cout << "Valor eliminado.\n";
        return;
    }

    Nodo* aux = cabeza;
    while (aux->sig && aux->sig->dato != v)
        aux = aux->sig;

    if (aux->sig) {
        Nodo* temp = aux->sig;
        aux->sig = temp->sig;
        delete temp;
        cout << "Valor eliminado.\n";
    } else {
        cout << "El valor no existe en la lista.\n";
    }
}

void ListaPun::mos() {
    if (!cabeza) {
        cout << "Lista vacia.\n";
        return;
    }

    Nodo* aux = cabeza;
    while (aux) {
        cout << aux->dato << " ";
        aux = aux->sig;
    }
    cout << endl;
}

bool ListaPun::vacia() {
    return cabeza == NULL;
}

bool ListaPun::llena() {
    Nodo* prueba = new (nothrow) Nodo;
    if (!prueba) return true;
    delete prueba;
    return false;
}

int ListaPun::tam() {
    int c = 0;
    Nodo* aux = cabeza;
    while (aux) {
        c++;
        aux = aux->sig;
    }
    return c;
}
