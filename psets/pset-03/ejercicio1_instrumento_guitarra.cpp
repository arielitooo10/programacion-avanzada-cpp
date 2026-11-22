class Guitarra : public Instrumento {
private:
    int cuerdas;
public:
    Guitarra(int c) {
        cuerdas = c;
    }
    int notasPorMinuto() override {
        return cuerdas * 20;
    }
    int volumen() {
        return 8;
    }
};

class Bateria : public Instrumento {
private:
    int tambores;
public:
    Bateria(int t) {
        tambores = t;
    }
    int notasPorMinuto() override {
        return tambores * 30;
    }
};