#include "merge.h"
#include <iostream>
#include <fstream>

using namespace std;

Merge::Merge() {
    arreglo = nullptr;
    tam = 0;
    archivoLeido = false;
    archivoGrabado = false;
    archivoOrdenado = false;
}

Merge::~Merge() {
    delete[] arreglo;
}

void Merge::leerArchivo() {
    if (archivoLeido) {
        cout << "Ya se leyo el archivo\n";
        return;
    }

    string nombre;
    cout << "Ingrese el nombre del archivo: ";
    cin >> ws;
    getline(cin, nombre);
    nombre += ".txt";

    ifstream archivo(nombre);

    if (!archivo) {
        cout << "No se pudo abrir\n";
        return;
    }

    tam = 0;
    int valor;

    while (archivo >> valor) tam++;

    if (tam == 0) {
        cout << "Archivo vacio\n";
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

    cout << "Archivo leido correctamente\n";
}

void Merge::mostrarArreglo() {
    if (!archivoLeido) {
        cout << "Primero lea archivo\n";
        return;
    }

    for (int i = 0; i < tam; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

void Merge::merge(int inicio, int medio, int fin) {
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;

    int* izq = new int[n1];
    int* der = new int[n2];

    for (int i = 0; i < n1; i++)
        izq[i] = arreglo[inicio + i];

    for (int j = 0; j < n2; j++)
        der[j] = arreglo[medio + 1 + j];

    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) {
        if (izq[i] <= der[j]) {
            arreglo[k++] = izq[i++];
        } else {
            arreglo[k++] = der[j++];
        }
    }

    while (i < n1)
        arreglo[k++] = izq[i++];

    while (j < n2)
        arreglo[k++] = der[j++];

    delete[] izq;
    delete[] der;
}

void Merge::mergeSort(int inicio, int fin) {
    if (inicio < fin) {
        int medio = (inicio + fin) / 2;

        mergeSort(inicio, medio);
        mergeSort(medio + 1, fin);

        merge(inicio, medio, fin);
    }
}

void Merge::ordenarMerge() {
    if (!archivoLeido) {
        cout << "Primero lea archivo\n";
        return;
    }

    if (archivoOrdenado) {
        cout << "Ya se ordeno\n";
        return;
    }

    mergeSort(0, tam - 1);

    archivoOrdenado = true;
    cout << "Ordenado con Merge Sort\n";
}

void Merge::guardarArchivo() {
    if (!archivoLeido) {
        cout << "Primero debe leer un archivo\n";
        return;
    }

    if (!archivoOrdenado) {
        cout << "Primero ordena el archivo\n";
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

    for (int i = 0; i < tam; i++) {
        txt << arreglo[i] << endl;
    }

    csv << "valor\n";
    for (int i = 0; i < tam; i++) {
        csv << arreglo[i] << endl;
    }

    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    xml << "<datos>\n";
    for (int i = 0; i < tam; i++) {
        xml << "  <valor>" << arreglo[i] << "</valor>\n";
    }
    xml << "</datos>\n";

    json << "[\n";
    for (int i = 0; i < tam; i++) {
        json << "  " << arreglo[i];
        if (i < tam - 1) json << ",";
        json << "\n";
    }
    json << "]\n";

    txt.close();
    csv.close();
    xml.close();
    json.close();

    archivoGrabado = true;
    cout << "Archivos guardados\n";
}


bool Merge::salir() {
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

bool Merge::estaLeido() {
    return archivoLeido;
}

bool Merge::estaOrdenado() {
    return archivoOrdenado;
}

bool Merge::estaGuardado() {
    return archivoGrabado;
}
