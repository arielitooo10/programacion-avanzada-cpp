// Ejercicio 21: plantillas de funcion (desde cero)
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio21 ejercicio21_plantillas_menor_suma.cpp
// Ejecutar: ./ejercicio21
//
// Salida esperada:
// Menor de 14, 9 y 30: 9
// Menor de 0.75, 1.5 y 0.25: 0.25
// Menor de q, c y x: c
// Suma de enteros: 108
// Suma de decimales: 4
// Intercambio de enteros: 7 3
// Intercambio de decimales: 9.5 1.5
// Menor de 5, 2.5 y 4: 2.5

#include <iostream>

template <typename T>
T menorDeTres(T a, T b, T c) {
    T menor = a;
    if (b < menor) {
        menor = b;
    }
    if (c < menor) {
        menor = c;
    }
    return menor;
}

template <typename T>
T sumarArreglo(T valores[], int cantidad) {
    if (cantidad == 0) {
        return T();
    }
    T suma = valores[0];
    for (int i = 1; i < cantidad; i++) {
        suma = suma + valores[i];
    }
    return suma;
}

template <typename T>
void intercambiar(T* a, T* b) {
    T temporal = *a;
    *a = *b;
    *b = temporal;
}

int main() {
    std::cout << "Menor de 14, 9 y 30: " << menorDeTres(14, 9, 30) << std::endl;
    std::cout << "Menor de 0.75, 1.5 y 0.25: " << menorDeTres(0.75, 1.5, 0.25) << std::endl;
    std::cout << "Menor de q, c y x: " << menorDeTres('q', 'c', 'x') << std::endl;

    int enteros[6] = {4, 8, 15, 16, 23, 42};
    std::cout << "Suma de enteros: " << sumarArreglo(enteros, 6) << std::endl;
    double decimales[3] = {1.5, 2.25, 0.25};
    std::cout << "Suma de decimales: " << sumarArreglo(decimales, 3) << std::endl;

    int x = 3;
    int y = 7;
    intercambiar(&x, &y);
    std::cout << "Intercambio de enteros: " << x << " " << y << std::endl;

    double p = 1.5;
    double q = 9.5;
    intercambiar(&p, &q);
    std::cout << "Intercambio de decimales: " << p << " " << q << std::endl;

    std::cout << "Menor de 5, 2.5 y 4: " << menorDeTres<double>(5, 2.5, 4) << std::endl;
    return 0;
}