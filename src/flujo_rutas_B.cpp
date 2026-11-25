// =====================================================================
//  flujo_rutas_B.cpp  —  [INTEGRANTE B]  Puntos 5, 6 y oficina nueva (7)
//  Mientras A termina dijkstra, se puede probar con un grafo pequeño a mano.
// =====================================================================
#include "red.h"
#include <queue>
#include <algorithm>

// ---------------------------------------------------------- Punto 5
// Sugerencia: Edmonds-Karp (BFS) sobre matriz/lista de capacidades residuales.
// Tubería NO dirigida: capacidad c en ambos sentidos.
static double edmondsKarp(int n, std::vector<std::vector<double>>& cap, int s, int t) {
    double flujo = 0;
    // TODO: mientras BFS encuentre camino s->t con capacidad residual > 0:
    //         cuello de botella, actualizar residuales, sumar a flujo
    return flujo;
}

void flujoMaximoSectores(const Red& red, Resultados& res) {
    for (auto& sec : res.sectores) {
        // TODO:
        //  1. construir 'cap' sólo con aristas abiertas cuyos dos extremos estén en el sector
        //  2. s = fuente, t = nodoMasLejano
        //  3. sec.flujoMax = edmondsKarp(...)
        //  4. flujo usado por arista = cap original - residual -> sec.flujoPorArista
        //     (para reportar "50 de 200")
        (void)sec;
    }
}

// ---------------------------------------------------------- Punto 6
// Es un TSP sobre el grafo de calles. Enfoque sugerido:
//  1. Dijkstra desde cada nodo a visitar -> matriz de distancias mínimas (cierre métrico)
//  2. Heurística: vecino más cercano desde la oficina + mejora 2-opt
//  3. Expandir cada salto con los padres de Dijkstra para obtener la secuencia
//     real de nodos y la distancia de cada arista recorrida
Ruta rutaMuestreo(const Red& red, int oficina, const std::vector<int>& nodosAVisitar) {
    Ruta r;
    // TODO
    return r;
}

// --------------------------------------------- Punto 7: oficina nueva
void rutasDosOficinas(const Red& red, Resultados& res) {
    // TODO:
    //  1. dijkstra desde oficina y desde oficinaNueva
    //  2. cada nodo va con la oficina más cercana (por red)
    //  3. res.rutaOf1 = rutaMuestreo(red, red.oficina, grupo1)
    //     res.rutaOf2 = rutaMuestreo(red, red.oficinaNueva, grupo2)
}

int mejorUbicacionOficina(const Red& red, std::vector<std::pair<int, double>>& costos) {
    // TODO: probar cada nodo como oficina nueva y medir un criterio, p. ej.:
    //   - minimizar la ruta más larga de los dos ingenieros (balance de carga), o
    //   - minimizar la suma de ambas rutas
    // Documentar en el reporte qué criterio se eligió y por qué.
    return red.oficinaNueva;
}
