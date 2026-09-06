// Ejercicio 13: Ascensor (desde cero)
// 
// Este ejercicio no trae código de partida: escribe tú el archivo
// completo, incluyendo los #include y el main().
// 
// Diseña una class Ascensor con dos atributos privados, pisoMinimo y
// pisoMaximo (enteros). Agrega:
// - Un setter que devuelva bool, setRangoPisos(int minimo, int
//   maximo), que valide un invariante conjunto entre los dos: mínimo
//   debe ser mayor o igual a -2 (hasta 2 sótanos), máximo menor o igual
//   a 50, y mínimo estrictamente menor que máximo. Si el invariante se
//   rompe, no modifica ningún atributo y devuelve false; si es válido,
//   asigna los dos juntos y devuelve true.
// - Los getters getPisoMinimo() y getPisoMaximo().
// 
// Tu main() debe:
// 1. Crear un Ascensor.
// 2. Intentar setRangoPisos(-1, 20) (válido) e imprimir el resultado y
//   los dos valores actuales.
// 3. Intentar setRangoPisos(30, 10) (inválido, mínimo no es menor que
//   máximo) e imprimir el resultado y los dos valores actuales (que no
//   debieron cambiar).
// 
// Salida esperada, exactamente:
// Rango aceptado (-1 a 20): true
// Minimo: -1
// Maximo: 20
// Rango aceptado (30 a 10): false
// Minimo: -1
// Maximo: 20
// 
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio13_ascensor.cpp -o bin/ejercicio13
// Ejecutar:  ./bin/ejercicio13

#include <iostream>

class Ascensor {
private:
    int pisoMinimo;
    int pisoMaximo;

public:
    bool setRangoPisos(int minimo, int maximo) {
        if (minimo >= -2 && maximo <= 50 && minimo < maximo) {
            pisoMinimo = minimo;
            pisoMaximo = maximo;
            return true;
        }
        return false;
    }

    int getPisoMinimo() const {
        return pisoMinimo;
    }

    int getPisoMaximo() const {
        return pisoMaximo;
    }
};

int main() {
    // 1. Crear un Ascensor.
    Ascensor asc;

    // 2. Intentar setRangoPisos(-1, 20) (válido)...
    bool r1 = asc.setRangoPisos(-1, 20);
    std::cout << std::boolalpha;
    std::cout << "Rango aceptado (-1 a 20): " << r1 << "\n";
    std::cout << "Minimo: " << asc.getPisoMinimo() << "\n";
    std::cout << "Maximo: " << asc.getPisoMaximo() << "\n";

    // 3. Intentar setRangoPisos(30, 10) (inválido)...
    bool r2 = asc.setRangoPisos(30, 10);
    std::cout << "Rango aceptado (30 a 10): " << r2 << "\n";
    std::cout << "Minimo: " << asc.getPisoMinimo() << "\n";
    std::cout << "Maximo: " << asc.getPisoMaximo() << "\n";

    return 0;
}

