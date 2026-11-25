// =====================================================================
//  base_A.cpp  —  [INTEGRANTE A]  Puntos 1, 2, 3 y 4
//  Prioridad: leerRed + calcularLongitudes + dijkstra el PRIMER día,
//  porque B y C dependen de ellos.
// =====================================================================
#include "red.h"
#include <fstream>
#include <sstream>
#include <queue>
#include <cmath>
#include <iostream>

// ---------------------------------------------------------- Punto 1
Red leerRed(const std::string& archivo) {
    Red red;
    std::ifstream in(archivo);
    if (!in) { std::cerr << "No se pudo abrir " << archivo << "\n"; return red; }

    std::string linea, seccion;
    while (std::getline(in, linea)) {
        if (linea.empty()) continue;
        if (linea[0] == '[') { seccion = linea; continue; }   // ej. "[NODES]"
        std::istringstream ss(linea);

        // TODO: revisar el formato exacto en los archivos de Teams
        //       (¿separado por espacios o comas?, ¿líneas de encabezado?)
        if (seccion == "[NODES]") {
            // TODO: leer id x y esFuente -> red.nodos.push_back(...); red.idx[id] = ...
        } else if (seccion == "[EDGES]") {
            // TODO: leer u v capacidad -> red.aristas.push_back(...)
        } else if (seccion == "[OFFICE]") {
            // TODO: red.oficina
        } else if (seccion == "[NEW]") {
            // TODO: x y capacidad -> red.nuevos.push_back(...)
        } else if (seccion == "[NEW OFFICE]") {
            // TODO: red.oficinaNueva
        }
        // La primera línea (num. nodos y aristas) llega con seccion == "" -> se puede ignorar/validar
    }
    construirAdyacencia(red);
    return red;
}

void construirAdyacencia(Red& red) {
    red.ady.assign(red.nodos.size(), {});
    // TODO: por cada arista i: ady[pos(u)].push_back({pos(v), i}) y viceversa (no dirigido)
}

// ---------------------------------------------------------- Punto 2
void calcularLongitudes(Red& red) {
    // TODO: longitud = sqrt((x1-x2)^2 + (y1-y2)^2)
}

// ------------------------------------------------- Dijkstra (base de 3, 4, 6, 7)
std::vector<double> dijkstra(const Red& red, const std::vector<int>& origenes,
                             std::vector<int>* origenDe, std::vector<int>* padre,
                             bool ignorarCerradas) {
    int n = red.nodos.size();
    std::vector<double> dist(n, INF);
    // TODO:
    //  - priority_queue<pair<double,int>, vector<...>, greater<...>>
    //  - meter TODOS los orígenes con dist 0 (multi-fuente)
    //  - si origenDe != nullptr, propagar de qué origen viene cada nodo
    //  - si padre != nullptr, guardar el predecesor (para reconstruir caminos)
    //  - si ignorarCerradas, saltar aristas con cerrada == true
    return dist;
}

// ---------------------------------------------------------- Punto 3
void sectorizar(Red& red, Resultados& res) {
    // TODO:
    //  1. origenes = posiciones de nodos con esFuente
    //  2. dijkstra multi-fuente -> res.distFuente y origenDe
    //  3. crear un Sector por fuente y asignar cada nodo a res.sectorDe
    //  4. toda arista cuyos extremos estén en sectores distintos -> cerrada = true,
    //     agregarla a res.aristasCerradas
}

// ---------------------------------------------------------- Punto 4
void calcularFrescura(const Red& red, Resultados& res) {
    // TODO: por sector, el nodo con mayor res.distFuente -> nodoMasLejano, distMax
}
