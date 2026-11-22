// Ejercicio 18: Sensor y SensorDeHumedad (desde cero, destructor virtual y unique_ptr)
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio18 ejercicio18_sensor_humedad.cpp
// Ejecutar: ./ejercicio18
//
// Salida esperada:
// Humedad promedio: 71
// Lecturas liberadas
// Sensor apagado
// Fin del programa

#include <iostream>
#include <memory>

class Sensor {
public:
    virtual ~Sensor() {
        std::cout << "Sensor apagado" << std::endl;
    }
    virtual double promedio() {
        return 0;
    }
};

class SensorDeHumedad : public Sensor {
private:
    double* lecturas;
public:
    SensorDeHumedad(double a, double b, double c) {
        lecturas = new double[3];
        lecturas[0] = a;
        lecturas[1] = b;
        lecturas[2] = c;
    }
    ~SensorDeHumedad() {
        delete[] lecturas;
        std::cout << "Lecturas liberadas" << std::endl;
    }
    double promedio() override {
        return (lecturas[0] + lecturas[1] + lecturas[2]) / 3;
    }
};

int main() {
    {
        std::unique_ptr<Sensor> sensor = std::make_unique<SensorDeHumedad>(60, 72, 81);
        std::cout << "Humedad promedio: " << sensor->promedio() << std::endl;
    }
    std::cout << "Fin del programa" << std::endl;
    return 0;
}