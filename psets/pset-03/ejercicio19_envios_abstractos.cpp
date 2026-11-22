// Ejercicio 19: Envio, EnvioNacional y EnvioInternacional (desde cero, clase abstracta)
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio19 ejercicio19_envios_abstractos.cpp
// Ejecutar: ./ejercicio19
//
// Salida esperada:
// Costo: 6.5
// Costo: 12
// Costo: 2
// El mas barato cuesta 6.5

#include <iostream>

class Envio {
public:
    virtual ~Envio() {}
    virtual double costo() = 0;
};

class EnvioNacional : public Envio {
private:
    double pesoKg;
public:
    EnvioNacional(double p) {
        if (p < 0) {
            pesoKg = 0;
        } else {
            pesoKg = p;
        }
    }
    double costo() override {
        return 2 + 1.5 * pesoKg;
    }
};

class EnvioInternacional : public Envio {
private:
    double pesoKg;
public:
    EnvioInternacional(double p) {
        if (p < 0) {
            pesoKg = 0;
        } else {
            pesoKg = p;
        }
    }
    double costo() override {
        return 10 + 4 * pesoKg;
    }
};

void imprimirCosto(Envio* envio) {
    std::cout << "Costo: " << envio->costo() << std::endl;
}

Envio* masBarato(Envio* a, Envio* b) {
    if (b->costo() < a->costo()) {
        return b;
    }
    return a;
}

int main() {
    EnvioNacional nacional(3);
    EnvioInternacional internacional(0.5);
    EnvioNacional invalido(-4);

    imprimirCosto(&nacional);
    imprimirCosto(&internacional);
    imprimirCosto(&invalido);

    Envio* barato = masBarato(&nacional, &internacional);
    std::cout << "El mas barato cuesta " << barato->costo() << std::endl;
    return 0;
}