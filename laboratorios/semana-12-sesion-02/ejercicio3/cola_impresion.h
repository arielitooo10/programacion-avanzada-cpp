#ifndef COLA_IMPRESION_H
#define COLA_IMPRESION_H

#include <vector>

inline int minutosDeImpresion(int paginas) {
    if (paginas <= 0) {
        return 0;
    }
    return (paginas + 9) / 10;
}

class ColaDeImpresion {
private:
    std::vector<int> trabajos;

public:
    void agregar(int paginas) {
        trabajos.push_back(paginas);
    }

    int cantidad() const {
        return static_cast<int>(trabajos.size());
    }

    int paginasDe(int indice) const {
        return trabajos[indice];
    }

    void dividirGrandes() {
        for (size_t i = 0; i < trabajos.size(); ++i) {
            if (trabajos[i] > 20) {
                int restante = trabajos[i] - 20;
                trabajos[i] = 20;
                trabajos.push_back(restante);
            }
        }
    }

    int minutosTotales() const {
        int total = 0;
        for (int paginas : trabajos) {
            total += minutosDeImpresion(paginas);
        }
        return total;
    }
};

#endif // COLA_IMPRESION_H
