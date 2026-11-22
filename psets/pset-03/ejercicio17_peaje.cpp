// Ejercicio 17: Vehiculo, Camion y Bus en el peaje (desde cero, arreglo de punteros a la base)
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio17 ejercicio17_peaje.cpp
// Ejecutar: ./ejercicio17
//
// Salida esperada:
// Vehiculo 0 paga: 1
// Vehiculo 1 paga: 8
// Vehiculo 2 paga: 4
// Vehiculo 3 paga: 2
// Recaudacion: 15

#include <iostream>

class Vehiculo {
private:
    double tarifaBase;
public:
    Vehiculo() {
        tarifaBase = 0;
    }
    void setTarifaBase(double t) {
        tarifaBase = t;
    }
    double getTarifaBase() {
        return tarifaBase;
    }
    virtual ~Vehiculo() {}
    virtual double peaje() {
        return tarifaBase;
    }
};

class Camion : public Vehiculo {
private:
    int ejes;
public:
    Camion(double tarifa, int e) {
        setTarifaBase(tarifa);
        ejes = e;
    }
    double peaje() override {
        return getTarifaBase() + 1.5 * ejes;
    }
};

class Bus : public Vehiculo {
private:
    int pasajeros;
public:
    Bus(double tarifa, int p) {
        setTarifaBase(tarifa);
        pasajeros = p;
    }
    double peaje() override {
        if (pasajeros > 30) {
            return getTarifaBase() * 2;
        }
        return getTarifaBase();
    }
};

double recaudacion(Vehiculo* fila[], int cantidad) {
    double total = 0;
    for (int i = 0; i < cantidad; i++) {
        total += fila[i]->peaje();
    }
    return total;
}

int main() {
    Vehiculo comun;
    comun.setTarifaBase(1);
    Camion camion(2, 4);
    Bus busLleno(2, 45);
    Bus busVacio(2, 12);

    Vehiculo* fila[4] = {&comun, &camion, &busLleno, &busVacio};
    for (int i = 0; i < 4; i++) {
        std::cout << "Vehiculo " << i << " paga: " << fila[i]->peaje() << std::endl;
    }
    std::cout << "Recaudacion: " << recaudacion(fila, 4) << std::endl;
    return 0;
}