#include "matrices.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Matrices::Matrices() {
    filasA = columnasA = filasB = columnasB = 0;
    matrizALeida = false;
    matrizBLeida = false;
}

void Matrices::leerMatrizA() {
    cout << "Filas de A (max 10): "; cin >> filasA;
    cout << "Columnas de A (max 10): "; cin >> columnasA;

    if (filasA <= 0 || filasA > 10 || columnasA <= 0 || columnasA > 10) {
        cout << "Tamano invalido\n";
        filasA = columnasA = 0;
        return;
    }

    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasA; j++) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }
    matrizALeida = true;
}

void Matrices::leerMatrizB() {
    cout << "Filas de B (max 10): "; cin >> filasB;
    cout << "Columnas de B (max 10): "; cin >> columnasB;

    if (filasB <= 0 || filasB > 10 || columnasB <= 0 || columnasB > 10) {
        cout << "Tamano invalido\n";
        filasB = columnasB = 0;
        return;
    }

    for (int i = 0; i < filasB; i++) {
        for (int j = 0; j < columnasB; j++) {
            cout << "B[" << i << "][" << j << "]: ";
            cin >> B[i][j];
        }
    }
    matrizBLeida = true;
}

void Matrices::mostrarMatrizA() {
    if (!matrizALeida) { cout << "Primero ingrese la matriz A\n"; return; }
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasA; j++) cout << A[i][j] << "\t";
        cout << endl;
    }
}

void Matrices::mostrarMatrizB() {
    if (!matrizBLeida) { cout << "Primero ingrese la matriz B\n"; return; }
    for (int i = 0; i < filasB; i++) {
        for (int j = 0; j < columnasB; j++) cout << B[i][j] << "\t";
        cout << endl;
    }
}

void Matrices::multiplicarPorConstante() {
    if (!matrizALeida) { cout << "Primero ingrese la matriz A\n"; return; }
    double c;
    cout << "Constante: "; cin >> c;
    cout << "Resultado A * " << c << ":\n";
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasA; j++) cout << A[i][j] * c << "\t";
        cout << endl;
    }
}

void Matrices::multiplicarMatrices() {
    if (!matrizALeida || !matrizBLeida) { cout << "Primero ingrese A y B\n"; return; }
    if (columnasA != filasB) { cout << "No se puede multiplicar. Columnas de A debe ser igual a filas de B\n"; return; }

    double R[10][10] = {0};
    for (int i = 0; i < filasA; i++)
        for (int j = 0; j < columnasB; j++)
            for (int k = 0; k < columnasA; k++)
                R[i][j] += A[i][k] * B[k][j];

    cout << "Resultado A * B:\n";
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) cout << R[i][j] << "\t";
        cout << endl;
    }
}

bool Matrices::existeA() { return matrizALeida; }
bool Matrices::existeB() { return matrizBLeida; }

void Matrices::guardarArchivos() {
    if (!matrizALeida && !matrizBLeida) {
        cout << "Primero ingrese al menos una matriz\n";
        return;
    }

    string nombre;
    cout << "Nombre base del archivo: "; cin >> nombre;

    ofstream txt(nombre + ".txt");
    txt << "Matriz A:\n";
    if (matrizALeida) {
        for (int i = 0; i < filasA; i++) { for (int j = 0; j < columnasA; j++) txt << A[i][j] << " "; txt << "\n"; }
    } else txt << "No ingresada\n";
    txt << "Matriz B:\n";
    if (matrizBLeida) {
        for (int i = 0; i < filasB; i++) { for (int j = 0; j < columnasB; j++) txt << B[i][j] << " "; txt << "\n"; }
    } else txt << "No ingresada\n";

    ofstream csv(nombre + ".csv");
    csv << "matriz,fila,columna,valor\n";
    if (matrizALeida) for (int i = 0; i < filasA; i++) for (int j = 0; j < columnasA; j++) csv << "A," << i << "," << j << "," << A[i][j] << "\n";
    if (matrizBLeida) for (int i = 0; i < filasB; i++) for (int j = 0; j < columnasB; j++) csv << "B," << i << "," << j << "," << B[i][j] << "\n";

    ofstream xml(nombre + ".xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    xml << "<matrices>\n";
    if (matrizALeida) {
        xml << "  <matriz nombre=\"A\" filas=\"" << filasA << "\" columnas=\"" << columnasA << "\">\n";
        for (int i = 0; i < filasA; i++) { xml << "    <fila>"; for (int j = 0; j < columnasA; j++) xml << "<valor>" << A[i][j] << "</valor>"; xml << "</fila>\n"; }
        xml << "  </matriz>\n";
    }
    if (matrizBLeida) {
        xml << "  <matriz nombre=\"B\" filas=\"" << filasB << "\" columnas=\"" << columnasB << "\">\n";
        for (int i = 0; i < filasB; i++) { xml << "    <fila>"; for (int j = 0; j < columnasB; j++) xml << "<valor>" << B[i][j] << "</valor>"; xml << "</fila>\n"; }
        xml << "  </matriz>\n";
    }
    xml << "</matrices>\n";

    ofstream json(nombre + ".json");
    json << "{\n";
    json << "  \"A\": ";
    if (matrizALeida) {
        json << "[";
        for (int i = 0; i < filasA; i++) { json << "["; for (int j = 0; j < columnasA; j++) { json << A[i][j]; if (j < columnasA - 1) json << ", "; } json << "]"; if (i < filasA - 1) json << ", "; }
        json << "]";
    } else json << "null";
    json << ",\n  \"B\": ";
    if (matrizBLeida) {
        json << "[";
        for (int i = 0; i < filasB; i++) { json << "["; for (int j = 0; j < columnasB; j++) { json << B[i][j]; if (j < columnasB - 1) json << ", "; } json << "]"; if (i < filasB - 1) json << ", "; }
        json << "]";
    } else json << "null";
    json << "\n}\n";

    cout << "Archivos guardados\n";
}
