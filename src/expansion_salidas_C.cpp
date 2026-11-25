// =====================================================================
//  expansion_salidas_C.cpp  —  [INTEGRANTE C]  Puntos 7 (expansión) y 8
// =====================================================================
#include "red.h"
#include <fstream>
#include <iomanip>

// ---------------------------------------------------------- Punto 7
std::vector<int> expandirRed(Red& red) {
    std::vector<int> nuevas;
    // TODO: por cada NodoNuevo:
    //  1. asignar un id nuevo (max id + 1), esFuente = false, agregar a red.nodos / red.idx
    //  2. buscar el nodo existente NO fuente más cercano (distancia euclidiana)
    //  3. crear Arista con la capacidad indicada; guardar índice en 'nuevas'
    // Al final: construirAdyacencia(red) y quitar marcas 'cerrada' viejas
    //           (la red se sectoriza de nuevo en main)
    return nuevas;
}

// ---------------------------------------------------------- Punto 8
void escribirSalida(const std::string& archivo, const Red& red, const Resultados& res,
                    const std::vector<int>& aristasNuevas) {
    std::ofstream out(archivo);
    out << std::fixed << std::setprecision(2);

    out << "=== PUNTO 2: Longitud de las tuberias ===\n";
    // TODO: u  v  capacidad  longitud

    out << "\n=== PUNTO 3: Sectorizacion ===\n";
    // TODO: por sector, lista de nodos; luego lista de tuberías cerradas

    out << "\n=== PUNTO 4: Frescura del agua ===\n";
    // TODO: sector | fuente | nodo mas lejano | distancia

    out << "\n=== PUNTO 5: Flujo maximo ===\n";
    // TODO: origen, destino, flujo; por arista "usado de capacidad" (ej. 50 de 200)

    out << "\n=== PUNTO 6: Ruta de muestreo ===\n";
    // TODO: secuencia u -> v (distancia) y total

    if (!aristasNuevas.empty()) {
        out << "\n=== PUNTO 7: Expansion de la red ===\n";
        // TODO: aristas nuevas y su longitud; rutas de los dos ingenieros; mejor oficina
    }
}

// Exporta CSV que lee graficas/graficar.py (nodos.csv, aristas.csv, ruta.csv)
void exportarParaGraficas(const std::string& prefijo, const Red& red, const Resultados& res) {
    // TODO:
    //  <prefijo>_nodos.csv   -> id,x,y,esFuente,sector,esMasLejano
    //  <prefijo>_aristas.csv -> u,v,capacidad,longitud,cerrada,flujo
    //  <prefijo>_ruta.csv    -> orden,u,v,distancia
}
