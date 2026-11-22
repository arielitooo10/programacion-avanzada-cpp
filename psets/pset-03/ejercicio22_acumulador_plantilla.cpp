// Ejercicio 22: Acumulador<T> (desde cero, plantilla de clase)
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio22 ejercicio22_acumulador_plantilla.cpp
// Ejecutar: ./ejercicio22
//
// Salida esperada:
// Goles: 8 en 4 partidos, maximo 5, promedio 2
// Diferencias: total -6.75, maximo -1.25
// Despues de reiniciar: 0 partidos, promedio 0

#include <iostream>

template <typename T>
class Acumulador {
private:
    T total;
    T maximo;
    int cantidad;
public:
    Acumulador() {
        total = T();
        maximo = T();
        cantidad = 0;
    }
    void agregar(T valor) {
        total = total + valor;
        if (cantidad == 0 || valor > maximo) {
            maximo = valor;
        }
        cantidad++;
    }
    T getTotal() {
        return total;
    }
    T getMaximo() {
        return maximo;
    }
    int getCantidad() {
        return cantidad;
    }
    double promedio() {
        if (cantidad == 0) {
            return 0;
        }
        return static_cast<double>(total) / cantidad;
    }
    void reiniciar() {
        total = T();
        maximo = T();
        cantidad = 0;
    }
};

int main() {
    Acumulador<int> goles;
    goles.agregar(2);
    goles.agregar(0);
    goles.agregar(5);
    goles.agregar(1);
    std::cout << "Goles: " << goles.getTotal() << " en " << goles.getCantidad()
              << " partidos, maximo " << goles.getMaximo()
              << ", promedio " << goles.promedio() << std::endl;

    Acumulador<double> vueltas;
    vueltas.agregar(-3.5);
    vueltas.agregar(-1.25);
    vueltas.agregar(-2.0);
    std::cout << "Diferencias: total " << vueltas.getTotal()
              << ", maximo " << vueltas.getMaximo() << std::endl;

    goles.reiniciar();
    std::cout << "Despues de reiniciar: " << goles.getCantidad()
              << " partidos, promedio " << goles.promedio() << std::endl;
    return 0;
}