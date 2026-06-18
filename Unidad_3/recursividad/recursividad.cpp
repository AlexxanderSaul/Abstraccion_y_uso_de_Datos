#include "recursividad.h"
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

    std::cout << "Datos guardados" << nombreBase;
}

Recursividad::Recursividad() {
    n = 0;
    operacion = "";
    resultadoTexto = "";
}

void Recursividad::leer() {
    do {
        cout << "Ingresa un numero mayor o igual a 0: ";
        cin >> n;
    } while (n < 0);
}

long long Recursividad::factorial(int x) {
    if (x == 0 || x == 1) return 1;
    return x * factorial(x - 1);
}

long long Recursividad::fibonacci(int x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    return fibonacci(x - 1) + fibonacci(x - 2);
}

void Recursividad::mostrarFactorial() {
    long long resultado = factorial(n);
    operacion = "factorial";
    resultadoTexto = to_string(resultado);
    cout << n << "! = " << resultado << endl;
}

void Recursividad::mostrarFibonacci() {
    operacion = "fibonacci";
    resultadoTexto = "";
    cout << "Serie Fibonacci:\n";
    for (int i = 0; i < n; i++) {
        long long f = fibonacci(i);
        cout << f << " ";
        resultadoTexto += to_string(f);
        if (i + 1 < n) resultadoTexto += " ";
    }
    cout << endl;
}

Registro Recursividad::obtenerDatos() {
    return {{"programa", "recursividad"}, {"numero", to_string(n)}, {"operacion", operacion}, {"resultado", resultadoTexto}};
}

void Recursividad::guardar() {
    guardarArchivos("recursividad", obtenerDatos());
}
