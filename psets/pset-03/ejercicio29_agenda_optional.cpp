// Ejercicio 29: AgendaDelConsultorio (desde cero, std::optional)
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio29 ejercicio29_agenda_optional.cpp
// Ejecutar: ./ejercicio29
//
// Salida esperada:
// Paciente 501: 8
// Paciente 502: 9
// Paciente 503: 16
// Paciente 504: 17
// Paciente 504 otra vez: sin hora
// A las 9: 502
// A las 12: 0
// Nadie a las 13
// Paciente 505: 8

#include <iostream>
#include <map>
#include <optional>

class AgendaDelConsultorio {
private:
    std::map<int, int> pacientePorHora;
public:
    std::optional<int> pacienteEn(int hora) {
        auto it = pacientePorHora.find(hora);
        if (it == pacientePorHora.end()) {
            return std::nullopt;
        }
        return it->second;
    }
    std::optional<int> primeraLibreDesde(int hora) {
        if (hora < 8) {
            hora = 8;
        }
        for (int h = hora; h <= 17; h++) {
            if (pacientePorHora.count(h) == 0) {
                return h;
            }
        }
        return std::nullopt;
    }
    std::optional<int> agendar(int paciente, int desde) {
        std::optional<int> hora = primeraLibreDesde(desde);
        if (!hora.has_value()) {
            return std::nullopt;
        }
        pacientePorHora[*hora] = paciente;
        return hora;
    }
    bool cancelar(int hora) {
        return pacientePorHora.erase(hora) > 0;
    }
};

void imprimirHora(const char* texto, std::optional<int> hora) {
    std::cout << texto;
    if (hora.has_value()) {
        std::cout << *hora << std::endl;
    } else {
        std::cout << "sin hora" << std::endl;
    }
}

int main() {
    AgendaDelConsultorio agenda;

    imprimirHora("Paciente 501: ", agenda.agendar(501, 8));
    imprimirHora("Paciente 502: ", agenda.agendar(502, 8));
    imprimirHora("Paciente 503: ", agenda.agendar(503, 16));
    imprimirHora("Paciente 504: ", agenda.agendar(504, 16));
    imprimirHora("Paciente 504 otra vez: ", agenda.agendar(504, 16));

    std::cout << "A las 9: " << *agenda.pacienteEn(9) << std::endl;
    std::cout << "A las 12: " << agenda.pacienteEn(12).value_or(0) << std::endl;

    try {
        std::cout << "A las 13: " << agenda.pacienteEn(13).value() << std::endl;
    } catch (const std::bad_optional_access& e) {
        std::cout << "Nadie a las 13" << std::endl;
    }

    agenda.cancelar(8);
    imprimirHora("Paciente 505: ", agenda.agendar(505, 7));
    return 0;
}