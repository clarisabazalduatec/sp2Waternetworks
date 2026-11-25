// =====================================================================
//  red.h  —  Estructuras compartidas y firmas de TODAS las funciones.
//  Este archivo es el "contrato" del equipo: acordarlo el día 1 y
//  no cambiar firmas sin avisar a los demás.
//
//  Dueños:  [A] = Integrante A   [B] = Integrante B   [C] = Integrante C
// =====================================================================
#pragma once
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <limits>

const double INF = std::numeric_limits<double>::infinity();

// ---------------------------------------------------------------- Datos
struct Nodo {
    int id;
    double x, y;
    bool esFuente;
};

struct Arista {
    int u, v;           // ids de los nodos
    double capacidad;   // diámetro
    double longitud = 0;    // se calcula en el punto 2
    bool cerrada = false;   // se marca en el punto 3
};

struct NodoNuevo {        // sección [NEW]
    double x, y;
    double capacidad;     // diámetro de la tubería para conectarlo
};

struct Red {
    std::vector<Nodo> nodos;
    std::vector<Arista> aristas;
    std::map<int, int> idx;   // id de nodo -> posición en 'nodos'
    // lista de adyacencia: para cada posición de nodo, pares (vecino, índice de arista)
    std::vector<std::vector<std::pair<int, int>>> ady;
    int oficina = -1;         // [OFFICE]
    int oficinaNueva = -1;    // [NEW OFFICE]
    std::vector<NodoNuevo> nuevos;   // [NEW]
};

// ----------------------------------------------------------- Resultados
struct Sector {
    int fuente;                 // id del nodo fuente
    std::vector<int> nodos;     // ids de nodos del sector
    int nodoMasLejano = -1;     // punto 4
    double distMax = 0;         // punto 4
    double flujoMax = 0;        // punto 5
    std::map<int, double> flujoPorArista;  // índice de arista -> flujo usado (punto 5)
};

struct Ruta {
    std::vector<int> secuencia;        // ids de nodos en orden (empieza y termina en oficina)
    std::vector<double> distTramos;    // distancia de cada arista recorrida
    double total = 0;
};

struct Resultados {
    std::vector<Sector> sectores;
    std::vector<int> aristasCerradas;  // índices de aristas
    std::vector<double> distFuente;    // por posición de nodo: distancia a su fuente
    std::vector<int> sectorDe;         // por posición de nodo: índice de sector
    Ruta ruta;                         // punto 6 (una oficina)
    Ruta rutaOf1, rutaOf2;             // punto 7 (dos oficinas / dos ingenieros)
};

// ===================================================== [A] Base + Dijkstra
// Punto 1: leer archivo de instancia (secciones [NODES] [EDGES] [OFFICE] [NEW] [NEW OFFICE])
Red leerRed(const std::string& archivo);
void construirAdyacencia(Red& red);
// Punto 2: longitud euclidiana de cada tubería
void calcularLongitudes(Red& red);
// Dijkstra genérico (multi-origen). Devuelve distancias; 'origenDe' y 'padre' opcionales.
std::vector<double> dijkstra(const Red& red, const std::vector<int>& origenes,
                             std::vector<int>* origenDe = nullptr,
                             std::vector<int>* padre = nullptr,
                             bool ignorarCerradas = false);
// Punto 3: sectorización (Dijkstra multi-fuente + cerrar tuberías entre sectores)
void sectorizar(Red& red, Resultados& res);
// Punto 4: nodo más lejano de cada sector
void calcularFrescura(const Red& red, Resultados& res);

// ===================================================== [B] Flujo + Rutas
// Punto 5: flujo máximo fuente -> nodo más lejano, sólo aristas abiertas del sector
void flujoMaximoSectores(const Red& red, Resultados& res);
// Punto 6: ruta mínima que visita todos los nodos desde 'oficina' y regresa
Ruta rutaMuestreo(const Red& red, int oficina, const std::vector<int>& nodosAVisitar);
// Punto 7 (oficina nueva): repartir nodos entre 2 oficinas y calcular ambas rutas
void rutasDosOficinas(const Red& red, Resultados& res);
// Punto 7 (oficina nueva): evaluar todos los candidatos y devolver el mejor id
int mejorUbicacionOficina(const Red& red, std::vector<std::pair<int, double>>& costos);

// ===================================================== [C] Expansión + Salidas
// Punto 7: conectar cada nodo nuevo al nodo NO fuente más cercano. Devuelve índices de aristas nuevas.
std::vector<int> expandirRed(Red& red);
// Punto 8: escribir archivo de texto con todos los puntos
void escribirSalida(const std::string& archivo, const Red& red, const Resultados& res,
                    const std::vector<int>& aristasNuevas);
// Punto 8: exportar CSV para que graficas/graficar.py dibuje las imágenes
void exportarParaGraficas(const std::string& prefijo, const Red& red, const Resultados& res);

// Helper común (cualquiera puede usarlo)
inline int pos(const Red& red, int id) { return red.idx.at(id); }
