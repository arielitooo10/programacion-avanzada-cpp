#include <iostream>
#include <vector>
#include <optional>

class Estadia {
    private:
        int placa;
        int entrada;
        int salida;
    public:
        Estadia(int p, int e, int s) {
            placa = p;
            entrada = e;
            salida = s;
        }

        int getPlaca() const {
            return placa;
        }

        int getEntrada() const {
            return entrada;
        }

        int getSalida() const {
            return salida;
        }
};

class RegistroDelDia {
    private:
        std::vector<Estadia> estadias;
    public:
        void agregar(const Estadia& estadia) {
            estadias.push_back(estadia);
        }

        int cantidad() const {
            return estadias.size();
        }

        std::optional<Estadia> ultimaDe(int placa) const {
            for (int i = estadias.size() - 1; i >= 0; --i) {
                if (estadias[i].getPlaca() == placa) {
                    return estadias[i];
                }
            }
            return std::nullopt;
        }
};

void procesarPlaca(const RegistroDelDia* registro, int placa) {
    std::optional<Estadia> estadia = registro->ultimaDe(placa);
    if (estadia) {
        int minutos = estadia->getSalida() - estadia->getEntrada();
        std::cout << "Placa " << placa << ": " << minutos << " minutos" << std::endl;
    } else {
        std::cout << "Placa " << placa << ": sin registro hoy" << std::endl;
    }
}

int main() {
    RegistroDelDia registro;
    registro.agregar(Estadia(4521, 10, 105));
    registro.agregar(Estadia(7788, 30, 70));
    registro.agregar(Estadia(3011, 60, 270));

    int placas[4] = {4521, 7788, 5555, 3011};
    for (int i = 0; i < 4; i++) {
        procesarPlaca(&registro, placas[i]);
    }

    return 0;
}
