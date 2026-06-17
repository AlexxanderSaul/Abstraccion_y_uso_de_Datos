#include "tamanios_datos.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

static string escJson(string s) {
    string r;
    for (char c : s) {
        if (c == '\\') r += "\\\\";
        else if (c == '"') r += "\\\"";
        else if (c == '\n') r += "\\n";
        else r += c;
    }
    return r;
}

static string escXml(string s) {
    string r;
    for (char c : s) {
        if (c == '&') r += "&amp;";
        else if (c == '<') r += "&lt;";
        else if (c == '>') r += "&gt;";
        else if (c == '"') r += "&quot;";
        else r += c;
    }
    return r;
}

TamaniosDatos::TamaniosDatos() { contenido = ""; }

template <typename T>
void agregarTipo(ostringstream& os, const char nombre[]) {
    os << nombre << " -> " << sizeof(T) << " bytes, " << sizeof(T) * 8 << " bits" << endl;
}

void TamaniosDatos::mostrarBasicos() {
    ostringstream os;
    os << "Primeros 8 tipos de datos basicos:\n";
    agregarTipo<char>(os, "char");
    agregarTipo<short>(os, "short");
    agregarTipo<int>(os, "int");
    agregarTipo<long>(os, "long");
    agregarTipo<long long>(os, "long long");
    agregarTipo<float>(os, "float");
    agregarTipo<double>(os, "double");
    agregarTipo<bool>(os, "bool");
    contenido = os.str();
    cout << contenido;
}

bool TamaniosDatos::vacio() { return contenido == ""; }

void TamaniosDatos::guardarArchivos() {
    if (vacio()) mostrarBasicos();
    string nombre;
    cout << "Nombre base del archivo: "; cin >> nombre;

    ofstream txt(nombre + ".txt");
    txt << contenido;

    ofstream csv(nombre + ".csv");
    csv << "tipo,bytes,bits\n";
    csv << "char," << sizeof(char) << "," << sizeof(char) * 8 << "\n";
    csv << "short," << sizeof(short) << "," << sizeof(short) * 8 << "\n";
    csv << "int," << sizeof(int) << "," << sizeof(int) * 8 << "\n";
    csv << "long," << sizeof(long) << "," << sizeof(long) * 8 << "\n";
    csv << "long long," << sizeof(long long) << "," << sizeof(long long) * 8 << "\n";
    csv << "float," << sizeof(float) << "," << sizeof(float) * 8 << "\n";
    csv << "double," << sizeof(double) << "," << sizeof(double) * 8 << "\n";
    csv << "bool," << sizeof(bool) << "," << sizeof(bool) * 8 << "\n";

    ofstream xml(nombre + ".xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    xml << "<tipos>\n";
    xml << "  <tipo nombre=\"char\" bytes=\"" << sizeof(char) << "\" bits=\"" << sizeof(char) * 8 << "\"/>\n";
    xml << "  <tipo nombre=\"short\" bytes=\"" << sizeof(short) << "\" bits=\"" << sizeof(short) * 8 << "\"/>\n";
    xml << "  <tipo nombre=\"int\" bytes=\"" << sizeof(int) << "\" bits=\"" << sizeof(int) * 8 << "\"/>\n";
    xml << "  <tipo nombre=\"long\" bytes=\"" << sizeof(long) << "\" bits=\"" << sizeof(long) * 8 << "\"/>\n";
    xml << "  <tipo nombre=\"long long\" bytes=\"" << sizeof(long long) << "\" bits=\"" << sizeof(long long) * 8 << "\"/>\n";
    xml << "  <tipo nombre=\"float\" bytes=\"" << sizeof(float) << "\" bits=\"" << sizeof(float) * 8 << "\"/>\n";
    xml << "  <tipo nombre=\"double\" bytes=\"" << sizeof(double) << "\" bits=\"" << sizeof(double) * 8 << "\"/>\n";
    xml << "  <tipo nombre=\"bool\" bytes=\"" << sizeof(bool) << "\" bits=\"" << sizeof(bool) * 8 << "\"/>\n";
    xml << "</tipos>\n";

    ofstream json(nombre + ".json");
    json << "{\n  \"tipos\": [\n";
    json << "    {\"nombre\": \"char\", \"bytes\": " << sizeof(char) << ", \"bits\": " << sizeof(char) * 8 << "},\n";
    json << "    {\"nombre\": \"short\", \"bytes\": " << sizeof(short) << ", \"bits\": " << sizeof(short) * 8 << "},\n";
    json << "    {\"nombre\": \"int\", \"bytes\": " << sizeof(int) << ", \"bits\": " << sizeof(int) * 8 << "},\n";
    json << "    {\"nombre\": \"long\", \"bytes\": " << sizeof(long) << ", \"bits\": " << sizeof(long) * 8 << "},\n";
    json << "    {\"nombre\": \"long long\", \"bytes\": " << sizeof(long long) << ", \"bits\": " << sizeof(long long) * 8 << "},\n";
    json << "    {\"nombre\": \"float\", \"bytes\": " << sizeof(float) << ", \"bits\": " << sizeof(float) * 8 << "},\n";
    json << "    {\"nombre\": \"double\", \"bytes\": " << sizeof(double) << ", \"bits\": " << sizeof(double) * 8 << "},\n";
    json << "    {\"nombre\": \"bool\", \"bytes\": " << sizeof(bool) << ", \"bits\": " << sizeof(bool) * 8 << "}\n";
    json << "  ]\n}\n";
    cout << "Archivos guardados\n";
}
