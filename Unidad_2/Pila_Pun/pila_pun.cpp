#include "pila_pun.h"
#include <iostream>
using namespace std;

pila_pun::pila_pun() {
    tope = NULL;
}

void pila_pun::push(int valor) {
    Nodo* aux = tope;
    while (aux != NULL) {
        if (aux->dato == valor) {
            cout << "Ese valor ya existe en la pila.\n";
            return;
        }
        aux = aux->siguiente;
    }

    Nodo* nuevo = new Nodo();
    if (!nuevo) {
        cout << "Memoria insuficiente\n";
        return;
    }

    nuevo->dato = valor;
    nuevo->siguiente = tope;
    tope = nuevo;

    cout << "Valor insertado correctamente.\n";
}

void pila_pun::pop() {
    if (tope == NULL) {
        cout << "Pila vacia\n";
    } else {
        Nodo* aux = tope;
        cout << "Eliminado: " << aux->dato << endl;
        tope = tope->siguiente;
        delete aux;
    }
}

void pila_pun::mos() {
    if (tope == NULL) {
        cout << "Pila vacia\n";
        return;
    }

    Nodo* aux = tope;
    while (aux != NULL) {
        cout << aux->dato << " ";
        aux = aux->siguiente;
    }
    cout << endl;
}

bool pila_pun::vacia() {
    return tope == NULL;
}

bool pila_pun::llena() {
    Nodo* prueba = new (nothrow) Nodo;
    if (!prueba) return true;
    delete prueba;
    return false;
}

int pila_pun::tam() {
    int c = 0;
    Nodo* aux = tope;
    while (aux != NULL) {
        c++;
        aux = aux->siguiente;
    }
    return c;
}
