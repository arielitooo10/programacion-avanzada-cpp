// Ejercicio 30: la Tienda del campus (desde cero, integrador del PSet)
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio30 ejercicio30_tienda_integrador.cpp
// Ejecutar: ./ejercicio30
//
// Salida esperada:
// No se agrego: codigo repetido
// No se agrego: precio no positivo
// Productos: 3
// Total: 16.5
// Cuestan menos de 7: 2
// Mas caro: 205
// Precio del 310: 6
// Precio del 999: no existe
// Mayor precio final: 8

#include <algorithm>
#include <iostream>
#include <memory>
#include <numeric>
#include <optional>
#include <stdexcept>
#include <utility>
#include <vector>

class Producto {
private:
    int codigo;
    double precio;
public:
    void setDatos(int c, double p) {
        codigo = c;
        precio = p;
    }
    int getCodigo() {
        return codigo;
    }
    double getPrecio() {
        return precio;
    }
    virtual ~Producto() {}
    virtual double precioFinal() = 0;
};

class ProductoNormal : public Producto {
public:
    ProductoNormal(int codigo, double precio) {
        setDatos(codigo, precio);
    }
    double precioFinal() override {
        return getPrecio();
    }
};

class ProductoEnOferta : public Producto {
private:
    double porcentaje;
public:
    ProductoEnOferta(int codigo, double precio, double p) {
        setDatos(codigo, precio);
        porcentaje = p;
    }
    double precioFinal() override {
        return getPrecio() * (1 - porcentaje / 100);
    }
};

class ProductoPorPeso : public Producto {
private:
    double kilos;
public:
    ProductoPorPeso(int codigo, double precioPorKilo, double k) {
        setDatos(codigo, precioPorKilo);
        kilos = k;
    }
    double precioFinal() override {
        return getPrecio() * kilos;
    }
};

template <typename T>
T mayorDe(std::vector<T> valores) {
    if (valores.empty()) {
        return T();
    }
    return *std::max_element(valores.begin(), valores.end());
}

class Tienda {
private:
    std::vector<std::unique_ptr<Producto>> productos;
public:
    void agregar(std::unique_ptr<Producto> producto) {
        if (producto->getPrecio() <= 0) {
            throw std::invalid_argument("precio no positivo");
        }
        for (int i = 0; i < static_cast<int>(productos.size()); i++) {
            if (productos[i]->getCodigo() == producto->getCodigo()) {
                throw std::invalid_argument("codigo repetido");
            }
        }
        productos.push_back(std::move(producto));
    }
    int cantidad() {
        return productos.size();
    }
    std::optional<double> precioDe(int codigo) {
        for (int i = 0; i < static_cast<int>(productos.size()); i++) {
            if (productos[i]->getCodigo() == codigo) {
                return productos[i]->precioFinal();
            }
        }
        return std::nullopt;
    }
    std::vector<double> preciosFinales() {
        std::vector<double> precios;
        for (int i = 0; i < static_cast<int>(productos.size()); i++) {
            precios.push_back(productos[i]->precioFinal());
        }
        return precios;
    }
    double total() {
        std::vector<double> precios = preciosFinales();
        return std::accumulate(precios.begin(), precios.end(), 0.0);
    }
    int cuantosBajo(double limite) {
        std::vector<double> precios = preciosFinales();
        return std::count_if(precios.begin(), precios.end(), [limite](double p) {
            return p < limite;
        });
    }
    std::optional<int> codigoMasCaro() {
        if (productos.empty()) {
            return std::nullopt;
        }
        int mejor = 0;
        for (int i = 1; i < static_cast<int>(productos.size()); i++) {
            if (productos[i]->precioFinal() > productos[mejor]->precioFinal()) {
                mejor = i;
            }
        }
        return productos[mejor]->getCodigo();
    }
};

int main() {
    Tienda tienda;

    try {
        tienda.agregar(std::make_unique<ProductoNormal>(101, 2.5));
    } catch (const std::invalid_argument& e) {
        std::cout << "No se agrego: " << e.what() << std::endl;
    }
    try {
        tienda.agregar(std::make_unique<ProductoEnOferta>(205, 10, 20));
    } catch (const std::invalid_argument& e) {
        std::cout << "No se agrego: " << e.what() << std::endl;
    }
    try {
        tienda.agregar(std::make_unique<ProductoPorPeso>(310, 4, 1.5));
    } catch (const std::invalid_argument& e) {
        std::cout << "No se agrego: " << e.what() << std::endl;
    }
    try {
        tienda.agregar(std::make_unique<ProductoNormal>(101, 3));
    } catch (const std::invalid_argument& e) {
        std::cout << "No se agrego: " << e.what() << std::endl;
    }
    try {
        tienda.agregar(std::make_unique<ProductoNormal>(400, 0));
    } catch (const std::invalid_argument& e) {
        std::cout << "No se agrego: " << e.what() << std::endl;
    }

    std::cout << "Productos: " << tienda.cantidad() << std::endl;
    std::cout << "Total: " << tienda.total() << std::endl;
    std::cout << "Cuestan menos de 7: " << tienda.cuantosBajo(7) << std::endl;
    std::cout << "Mas caro: " << *tienda.codigoMasCaro() << std::endl;
    std::cout << "Precio del 310: " << tienda.precioDe(310).value_or(0) << std::endl;

    std::optional<double> p999 = tienda.precioDe(999);
    if (p999.has_value()) {
        std::cout << "Precio del 999: " << *p999 << std::endl;
    } else {
        std::cout << "Precio del 999: no existe" << std::endl;
    }

    std::cout << "Mayor precio final: " << mayorDe(tienda.preciosFinales()) << std::endl;
    return 0;
}