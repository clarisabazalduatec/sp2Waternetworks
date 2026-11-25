CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2 -Iinclude
SRC = src/main.cpp src/base_A.cpp src/flujo_rutas_B.cpp src/expansion_salidas_C.cpp

red_agua: $(SRC) include/red.h
	$(CXX) $(CXXFLAGS) $(SRC) -o red_agua

clean:
	rm -f red_agua
