#include "frota.h"
#include <string>

using namespace std;

Frota::Frota() {
    veiculos = {};
}

void Frota::adicionaVeiculo(Veiculo *v1) {
    veiculos.push_back(v1);
}

int Frota::numVeiculos() const {
    return veiculos.size();
}

int Frota::menorAno() const {
    if (veiculos.size() != 0)
    {
        int control = veiculos[0]->getAno();
        for (int i = 0; i < veiculos.size(); i++)
        {
            if (control > veiculos[i]->getAno())
                control = veiculos[i]->getAno();
        }
        return control;
    }
    return 0;
}
