#include <iostream>

class Rectangulo {
private:
    double base = 0.0;
    double altura = 0.0;

public:
    double getBase() const { return base; }
    double getAltura() const { return altura; }

    bool setBase(double nuevaBase) {
        if (nuevaBase > 0.0) {
            base = nuevaBase;
            return true;
        }
        return false;
    }

    bool setAltura(double nuevaAltura) {
        if (nuevaAltura > 0.0) {
            altura = nuevaAltura;
            return true;
        }
        return false;
    }

    double area() const {
        return base * altura;
    }

    double perimetro() const {
        return 2.0 * (base + altura);
    }
};

int main() {
    Rectangulo r;
    r.setBase(10.0);
    r.setAltura(5.0);

    std::cout << "Area: " << r.area() << ", Perimetro: " << r.perimetro() << std::endl;

    bool aceptado = r.setBase(-3.0);
    std::cout << "setBase(-3) rechazado: " << (!aceptado ? "true" : "false")
              << ", base sigue en: " << r.getBase() << std::endl;

    r.setBase(20.0);
    r.setAltura(10.0);
    std::cout << "Area: " << r.area() << ", Perimetro: " << r.perimetro() << std::endl;

    return 0;
}