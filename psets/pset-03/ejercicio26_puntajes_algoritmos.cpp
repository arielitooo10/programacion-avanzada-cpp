// Ejercicio 26: puntajes del concurso (desde cero, algoritmos y lambdas)
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio26 ejercicio26_puntajes_algoritmos.cpp
// Ejecutar: ./ejercicio26
//
// Salida esperada:
// Primer perfecto en la posicion: 1
// Aprobados con 70: 5
// Mejor: 100
// Promedio: 77.375
// Primero bajo 60: 45
// Podio: 100 100 91
// Vacio, mejor: 0
// Vacio, promedio: 0

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int posicionDelPrimerPerfecto(std::vector<int> puntajes) {
    auto it = std::find(puntajes.begin(), puntajes.end(), 100);
    if (it == puntajes.end()) {
        return -1;
    }
    return it - puntajes.begin();
}

int aprobados(std::vector<int> puntajes, int minimo) {
    return std::count_if(puntajes.begin(), puntajes.end(), [minimo](int p) {
        return p >= minimo;
    });
}

int mejor(std::vector<int> puntajes) {
    if (puntajes.empty()) {
        return 0;
    }
    return *std::max_element(puntajes.begin(), puntajes.end());
}

double promedio(std::vector<int> puntajes) {
    if (puntajes.empty()) {
        return 0;
    }
    double suma = std::accumulate(puntajes.begin(), puntajes.end(), 0.0);
    return suma / puntajes.size();
}

int primeroBajo(std::vector<int> puntajes, int limite) {
    auto it = std::find_if(puntajes.begin(), puntajes.end(), [limite](int p) {
        return p < limite;
    });
    if (it == puntajes.end()) {
        return -1;
    }
    return *it;
}

std::vector<int> podio(std::vector<int> puntajes) {
    std::sort(puntajes.begin(), puntajes.end(), [](int a, int b) {
        return a > b;
    });
    if (puntajes.size() > 3) {
        puntajes.resize(3);
    }
    return puntajes;
}

int main() {
    std::vector<int> puntajes = {72, 100, 45, 88, 100, 59, 91, 64};

    std::cout << "Primer perfecto en la posicion: " << posicionDelPrimerPerfecto(puntajes) << std::endl;
    std::cout << "Aprobados con 70: " << aprobados(puntajes, 70) << std::endl;
    std::cout << "Mejor: " << mejor(puntajes) << std::endl;
    std::cout << "Promedio: " << promedio(puntajes) << std::endl;
    std::cout << "Primero bajo 60: " << primeroBajo(puntajes, 60) << std::endl;

    std::vector<int> tres = podio(puntajes);
    std::cout << "Podio:";
    for (int p : tres) {
        std::cout << " " << p;
    }
    std::cout << std::endl;

    std::vector<int> vacio;
    std::cout << "Vacio, mejor: " << mejor(vacio) << std::endl;
    std::cout << "Vacio, promedio: " << promedio(vacio) << std::endl;
    return 0;
}