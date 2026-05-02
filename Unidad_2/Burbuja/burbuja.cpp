#include "burbuja.h"
#include <iostream>
#include <fstream>

using namespace std;

Burbuja::Burbuja() {
    arreglo = nullptr;
    tam = 0;
    archivoLeido = false;
    archivoGrabado = false;
    archivoOrdenado = false;
}

Burbuja::~Burbuja() {
    delete[] arreglo;
}

void Burbuja::leerArchivo() {
    if (archivoLeido) {
        cout << "Ya se leyo el archivo\n";
        return;
    }

    string nombre;
    cout << "Ingrese el nombre del archivo sin extension: ";
    cin >> ws;
    getline(cin, nombre);
    nombre += ".txt";

    ifstream archivo(nombre);

    if (!archivo) {
        cout << "No se pudo abrir el archivo\n";
        return;
    }

    tam = 0;
    int valor;

    while (archivo >> valor) {
        tam++;
    }

    if (tam == 0) {
        cout << "El archivo esta vacio\n";
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
    archivoGrabado = false;
    archivoOrdenado = false;

    cout << "Archivo leido correctamente. Total: " << tam << endl;
}

void Burbuja::mostrarArreglo() {
    if (!archivoLeido) {
        cout << "Primero debe leer un archivo\n";
        return;
    }

    for (int i = 0; i < tam; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

void Burbuja::ordenarBurbuja() {
    if (!archivoLeido) {
        cout << "Primero debe leer un archivo\n";
        return;
    }

    if (archivoOrdenado) {
        cout << "Ya se ordeno el archivo\n";
        return;
    }

    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                swap(arreglo[j], arreglo[j + 1]);
            }
        }
    }

    archivoOrdenado = true;
    cout << "Ordenado correctamente\n";
}

void Burbuja::guardarArchivo() {
    if (!archivoLeido) {
        cout << "Primero debe leer un archivo\n";
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
        cout << "Error al guardar\n";
        return;
    }

    for (int i = 0; i < tam; i++) {
        archivo << arreglo[i] << " ";
    }

    archivo.close();
    archivoGrabado = true;

    cout << "Archivo guardado\n";
}

bool Burbuja::salir() {
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

bool Burbuja::estaLeido() {
    return archivoLeido;
}

bool Burbuja::estaOrdenado() {
    return archivoOrdenado;
}

bool Burbuja::estaGuardado() {
    return archivoGrabado;
}
