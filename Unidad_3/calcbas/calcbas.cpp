#include "calcbas.h"
#include <iostream>
#include <fstream>
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

    std::cout << "Datos guardados en " << nombreBase << ".txt, .csv, .xml y .json\n";
}

Calculadora::Calculadora() {
    a = 0;
    b = 0;
    resultado = 0;
    operacion = "";
}

void Calculadora::leer() {
    cout << "Ingresa el primer numero: ";
    cin >> a;
    cout << "Ingresa el segundo numero: ";
    cin >> b;
}

bool Calculadora::operar(int opcion) {
    switch (opcion) {
        case 1: operacion = "suma"; resultado = a + b; return true;
        case 2: operacion = "resta"; resultado = a - b; return true;
        case 3: operacion = "multiplicacion"; resultado = a * b; return true;
        case 4:
            if (b == 0) {
                cout << "No se puede dividir entre 0\n";
                return false;
            }
            operacion = "division"; resultado = a / b; return true;
        default:
            cout << "Opcion no valida\n";
            return false;
    }
}

void Calculadora::mostrar() {
    cout << "Resultado: " << resultado << endl;
}

Registro Calculadora::obtenerDatos() {
    return {{"programa", "calcbas"}, {"numero1", to_string(a)}, {"numero2", to_string(b)}, {"operacion", operacion}, {"resultado", to_string(resultado)}};
}

void Calculadora::guardar() {
    guardarArchivos("calcbas", obtenerDatos());
}
