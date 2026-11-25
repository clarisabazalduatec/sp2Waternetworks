# [INTEGRANTE C] Gráficas del punto 8 a partir de los CSV que exporta el programa C++.
# Uso: python graficas/graficar.py salidas/<instancia>_antes
# Requiere: pip install matplotlib pandas
import sys
import pandas as pd
import matplotlib.pyplot as plt

prefijo = sys.argv[1]
nodos = pd.read_csv(f"{prefijo}_nodos.csv")
aristas = pd.read_csv(f"{prefijo}_aristas.csv")
ruta = pd.read_csv(f"{prefijo}_ruta.csv")

def grafica_a():
    """a) Nodos, conexiones, longitudes y capacidades."""
    # TODO: dibujar aristas (grosor ~ capacidad), etiqueta "long / cap" a la mitad
    pass

def grafica_b():
    """b) Fuentes, nodos más lejanos y sectores (color por sector, cerradas punteadas)."""
    # TODO
    pass

def grafica_c():
    """c) Recorrido del punto 6 con longitudes y total en el título."""
    # TODO
    pass

def grafica_e():
    """e) Red actualizada con los nodos nuevos resaltados (correr con el prefijo _despues)."""
    # TODO
    pass

for f in (grafica_a, grafica_b, grafica_c, grafica_e):
    f()
    # plt.savefig(f"{prefijo}_{f.__name__}.png", dpi=150); plt.close()
