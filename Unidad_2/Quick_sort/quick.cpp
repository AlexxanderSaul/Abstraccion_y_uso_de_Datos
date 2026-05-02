#include "quick.h"
#include <iostream>
#include <fstream>

using namespace std;

Quick::Quick() {
    arreglo = nullptr;
    tam = 0;
    archivoLeido = false;
    archivoOrdenado = false;
    archivoGrabado = false;
}

Quick::~Quick() {
    delete[] arreglo;
}

int Quick::particion(int inicio, int fin) {
    int pivote = arreglo[fin];
    int i = inicio - 1;

    for (int j = inicio; j < fin; j++) {
        if (arreglo[j] <= pivote) {
            i++;
            swap(arreglo[i], arreglo[j]);
        }
    }

    swap(arreglo[i + 1], arreglo[fin]);
    return i + 1;
}

void Quick::quickSort(int inicio, int fin) {
    if (inicio < fin) {
        int pi = particion(inicio, fin);
        quickSort(inicio, pi - 1);
        quickSort(pi + 1, fin);
    }
}

void Quick::leerArchivo() {
    if (archivoLeido) {
        cout << "El archivo ya fue leido.\n";
        return;
    }

    string nombre;
    cout << "Ingrese el nombre del archivo: ";
    cin >> ws;
    getline(cin, nombre);
    nombre += ".txt";

    ifstream archivo(nombre);

    if (!archivo) {
        cout << "No se pudo abrir.\n";
        return;
    }

    tam = 0;
    int valor;

    while (archivo >> valor) tam++;

    if (tam == 0) {
        cout << "Archivo vacio.\n";
        return;
    }

    archivo.clear();
    archivo.seekg(0);

    delete[] arreglo;
    arreglo = new int[tam];

    for (int i = 0; i < tam; i++) {
        archivo >> arreglo[i];
    }

    archivo.close();

    archivoLeido = true;
    archivoOrdenado = false;
    archivoGrabado = false;

    cout << "Archivo leido correctamente.\n";
}

void Quick::mostrarArreglo() {
    if (!archivoLeido) {
        cout << "Primero lea archivo\n";
        return;
    }

    for (int i = 0; i < tam; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

void Quick::ordenarQuickSort() {
    if (!archivoLeido) {
        cout << "Primero lea archivo\n";
        return;
    }

    if (archivoOrdenado) {
        cout << "Ya esta ordenado\n";
        return;
    }

    quickSort(0, tam - 1);
    archivoOrdenado = true;

    cout << "Ordenado con QuickSort\n";
}

void Quick::guardarArchivo() {
    if (!archivoLeido) {
        cout << "Primero lea archivo\n";
        return;
    }

    if (!archivoOrdenado) {
        cout << "Primero ordena el archivo\n";
        return;
    }

    string nombre;
    cout << "Nombre del archivo: ";
    cin >> ws;
    getline(cin, nombre);
    nombre += ".txt";

    ofstream archivo(nombre);

    if (!archivo) {
        cout << "Error\n";
        return;
    }

    for (int i = 0; i < tam; i++) {
        archivo << arreglo[i] << endl;
    }

    archivo.close();
    archivoGrabado = true;

    cout << "Archivo guardado\n";
}

bool Quick::salir() {
    if (!archivoLeido) {
        cout << "Debe leer archivo\n";
        return false;
    }

    if (!archivoGrabado) {
        cout << "Debe guardar archivo\n";
        return false;
    }

    cout << "Saliendo...\n";
    return true;
}

bool Quick::estaLeido() {
    return archivoLeido;
}

bool Quick::estaOrdenado() {
    return archivoOrdenado;
}

bool Quick::estaGuardado() {
    return archivoGrabado;
}
