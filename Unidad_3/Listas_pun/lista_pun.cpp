#include "lista_pun.h"
#include <iostream>
#include <fstream>
#include <string>
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

void ListaPun::guardarArchivo() {
    if (vacia()) {
        cout << "No hay datos para guardar\n";
        return;
    }

    string nombre;
    cout << "Nombre base del archivo sin extension: ";
    cin >> ws;
    getline(cin, nombre);

    ofstream txt(nombre + ".txt");
    ofstream csv(nombre + ".csv");
    ofstream xml(nombre + ".xml");
    ofstream json(nombre + ".json");

    if (!txt || !csv || !xml || !json) {
        cout << "Error al guardar archivos\n";
        return;
    }

    Nodo* aux = cabeza;
    while (aux) {
        txt << aux->dato << endl;
        aux = aux->sig;
    }

    csv << "valor\n";
    aux = cabeza;
    while (aux) {
        csv << aux->dato << endl;
        aux = aux->sig;
    }

    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    xml << "<datos>\n";
    aux = cabeza;
    while (aux) {
        xml << "  <valor>" << aux->dato << "</valor>\n";
        aux = aux->sig;
    }
    xml << "</datos>\n";

    json << "[\n";
    aux = cabeza;
    int total = tam();
    int i = 0;
    while (aux) {
        json << "  " << aux->dato;
        if (i < total - 1) json << ",";
        json << "\n";
        aux = aux->sig;
        i++;
    }
    json << "]\n";

    cout << "Archivos guardados\n";
}
