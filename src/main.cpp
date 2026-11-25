// =====================================================================
//  main.cpp  —  Orquesta todo. Uso:  ./red_agua instancias/archivo.txt
//  Corre el análisis ANTES y DESPUÉS de agregar nodos nuevos (punto 8).
// =====================================================================
#include "red.h"
#include <iostream>

static Resultados analizar(Red& red) {
    Resultados res;
    calcularLongitudes(red);        // [A] punto 2
    sectorizar(red, res);           // [A] punto 3
    calcularFrescura(red, res);     // [A] punto 4
    flujoMaximoSectores(red, res);  // [B] punto 5

    std::vector<int> todos;
    for (auto& n : red.nodos) todos.push_back(n.id);
    res.ruta = rutaMuestreo(red, red.oficina, todos);  // [B] punto 6
    return res;
}

static std::string nombreBase(const std::string& ruta) {
    size_t a = ruta.find_last_of("/\\");
    std::string f = (a == std::string::npos) ? ruta : ruta.substr(a + 1);
    size_t b = f.find_last_of('.');
    return (b == std::string::npos) ? f : f.substr(0, b);
}

int main(int argc, char* argv[]) {
    if (argc < 2) { std::cerr << "Uso: " << argv[0] << " <instancia.txt>\n"; return 1; }
    std::string base = nombreBase(argv[1]);

    // ---------- ANTES ----------
    Red red = leerRed(argv[1]);     // [A] punto 1
    Resultados antes = analizar(red);
    escribirSalida("salidas/" + base + "_antes.txt", red, antes, {});   // [C]
    exportarParaGraficas("salidas/" + base + "_antes", red, antes);      // [C]

    // ---------- DESPUÉS ----------
    std::vector<int> nuevas = expandirRed(red);   // [C] punto 7
    Resultados despues = analizar(red);
    rutasDosOficinas(red, despues);               // [B] punto 7 (nueva oficina)
    std::vector<std::pair<int, double>> costos;
    int mejor = mejorUbicacionOficina(red, costos);   // [B]
    std::cout << "Mejor ubicación para la oficina nueva: " << mejor << "\n";

    escribirSalida("salidas/" + base + "_despues.txt", red, despues, nuevas);
    exportarParaGraficas("salidas/" + base + "_despues", red, despues);
    return 0;
}
