#include "triangulos.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

static std::string escaparJson(const std::string& texto) {
    std::string r;
    for (char c : texto) {
        if (c == '"') r += "\\\"";
        else if (c == '\\') r += "\\\\";
        else if (c == '\n') r += "\\n";
        else r += c;
    }
    return r;
}

static std::string escaparXml(const std::string& texto) {
    std::string r;
    for (char c : texto) {
        if (c == '&') r += "&amp;";
        else if (c == '<') r += "&lt;";
        else if (c == '>') r += "&gt;";
        else if (c == '"') r += "&quot;";
        else r += c;
    }
    return r;
}

static std::string escaparCsv(const std::string& texto) {
    std::string r = "\"";
    for (char c : texto) {
        if (c == '"') r += "\"\"";
        else r += c;
    }
    r += "\"";
    return r;
}

void guardarArchivos(const std::string& nombreBase, const Registro& datos) {
    std::ofstream txt(nombreBase + ".txt");
    for (const auto& dato : datos) {
        txt << dato.first << ": " << dato.second << "\n";
    }
    txt.close();

    std::ofstream csv(nombreBase + ".csv");
    csv << "campo,valor\n";
    for (const auto& dato : datos) {
        csv << escaparCsv(dato.first) << "," << escaparCsv(dato.second) << "\n";
    }
    csv.close();

    std::ofstream xml(nombreBase + ".xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    xml << "<registro>\n";
    for (const auto& dato : datos) {
        xml << "  <campo nombre=\"" << escaparXml(dato.first) << "\">" << escaparXml(dato.second) << "</campo>\n";
    }
    xml << "</registro>\n";
    xml.close();

    std::ofstream json(nombreBase + ".json");
    json << "{\n";
    for (size_t i = 0; i < datos.size(); i++) {
        json << "  \"" << escaparJson(datos[i].first) << "\": \"" << escaparJson(datos[i].second) << "\"";
        if (i + 1 < datos.size()) json << ",";
        json << "\n";
    }
    json << "}\n";
    json.close();

    std::cout << "Datos guardados" << nombreBase;
}

void guardarDatos(const string& nombreBase, const Registro& datos) {
    guardarArchivos(nombreBase, datos);
}

Sierpinski::Sierpinski() {
    size = 0;
    nivel = 0;
    dibujo = "";
}

void Sierpinski::iniciar() {
    cout << "Nivel del Triangulo de Sierpinski (max 6 recomendado): ";
    cin >> nivel;

    size = pow(2, nivel);
    mat.assign(size, vector<char>(2 * size - 1, ' '));
    dibujar(0, size - 1, size, nivel);

    dibujo = "";
    for (int i = 0; i < size; i++) {
        string linea;
        for (int j = 0; j < 2 * size - 1; j++) {
            cout << mat[i][j];
            linea += mat[i][j];
        }
        cout << endl;
        dibujo += linea + "\n";
    }
}

void Sierpinski::dibujar(int fila, int col, int n, int nivelActual) {
    if (nivelActual == 0) {
        mat[fila][col] = '*';
        return;
    }
    int h = n / 2;
    dibujar(fila, col, h, nivelActual - 1);
    dibujar(fila + h, col - h, h, nivelActual - 1);
    dibujar(fila + h, col + h, h, nivelActual - 1);
}

Registro Sierpinski::obtenerDatos() {
    return {{"programa", "triangulos"}, {"fractal", "Triangulo de Sierpinski"}, {"nivel", to_string(nivel)}, {"dibujo", dibujo}};
}

Cantor::Cantor() {
    nivel = 0;
    dibujo = "";
}

void Cantor::iniciar() {
    cout << "Nivel del Polvo de Cantor (max 5 recomendado): ";
    cin >> nivel;

    int longitud = pow(3, nivel);
    vector<char> linea(longitud, '-');
    dibujo = "";
    dibujar(linea, nivel);
}

void Cantor::dibujar(vector<char> linea, int nivelActual) {
    string texto;
    for (char c : linea) {
        cout << c;
        texto += c;
    }
    cout << endl;
    dibujo += texto + "\n";

    if (nivelActual == 0) return;

    int n = linea.size() / 3;
    vector<char> izquierda(linea.begin(), linea.begin() + n);
    vector<char> derecha(linea.end() - n, linea.end());
    for (int i = n; i < 2 * n; i++) linea[i] = ' ';
    dibujar(izquierda, nivelActual - 1);
    dibujar(derecha, nivelActual - 1);
}

Registro Cantor::obtenerDatos() {
    return {{"programa", "triangulos"}, {"fractal", "Polvo de Cantor"}, {"nivel", to_string(nivel)}, {"dibujo", dibujo}};
}
