#include "herencia_sobreescritura.h"
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
    n = 0;
    resultado = 0;
    operacion = "";
}

void Calculadora::leer() {
    do {
        cout << "Cuantos numeros usaremos: ";
        cin >> n;
    } while (n < 1 || n > 100);

    for (int i = 0; i < n; i++) {
        cout << "Ingresa el numero " << i + 1 << ": ";
        cin >> num[i];
    }
}

void Calculadora::sum() {
    resultado = 0;
    for (int i = 0; i < n; i++) resultado += num[i];
    operacion = "suma_n_numeros";
    cout << "Resultado: " << resultado << endl;
}

void Calculadora::res() {
    resultado = num[0];
    for (int i = 1; i < n; i++) resultado -= num[i];
    operacion = "resta_n_numeros";
    cout << "Resultado: " << resultado << endl;
}

void Calculadora::mult() {
    resultado = 1;
    for (int i = 0; i < n; i++) resultado *= num[i];
    operacion = "multiplicacion_n_numeros";
    cout << "Resultado: " << resultado << endl;
}

bool Calculadora::div() {
    resultado = num[0];
    for (int i = 1; i < n; i++) {
        if (num[i] == 0) {
            cout << "Error: division entre 0\n";
            return false;
        }
        resultado /= num[i];
    }
    operacion = "division_n_numeros";
    cout << "Resultado: " << resultado << endl;
    return true;
}

void CalculadoraNueva::mult(int a, int b) {
    int r = 0;
    for (int i = 0; i < b; i++) r += a;
    resultado = r;
    operacion = "multiplicacion_por_sumas_sucesivas";
    cout << "Resultado: " << r << endl;
}

bool CalculadoraNueva::div(int a, int b) {
    if (b == 0) {
        cout << "Error: division entre 0\n";
        return false;
    }
    int contador = 0;
    int temp = a;
    while (temp >= b) {
        temp -= b;
        contador++;
    }
    resultado = contador;
    operacion = "division_por_restas_sucesivas";
    cout << "Resultado: " << contador << endl;
    return true;
}

void CalculadoraNueva::potencia(int a, int b) {
    int r = 1;
    for (int i = 0; i < b; i++) r *= a;
    resultado = r;
    operacion = "potencia";
    cout << "Resultado: " << r << endl;
}

string Calculadora::numerosComoTexto() {
    string texto;
    for (int i = 0; i < n; i++) {
        texto += to_string(num[i]);
        if (i + 1 < n) texto += " ";
    }
    return texto;
}

Registro Calculadora::obtenerDatos() {
    return {{"programa", "herencia_sobreescritura"}, {"numeros", numerosComoTexto()}, {"operacion", operacion}, {"resultado", to_string(resultado)}};
}

void Calculadora::guardar() {
    guardarArchivos("herencia_sobreescritura", obtenerDatos());
}
