#include "frota.h"
#include <string>
#include <iostream>

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

ostream &operator<<(ostream &o, const Frota &f) {
    if (f.numVeiculos() == 0)
    {
        cout << "no veicles to show\n";
    }
    else
    {
        for (int i = 0; i < f.numVeiculos(); i++)
        {
            f.veiculos[i]->info();
            (i != f.numVeiculos() -1) ? cout << "-----\n" : cout << "";
        }
    }
}

vector<Veiculo *> Frota::operator()(int anoM) const {
    vector<Veiculo *> veicM;

    if (this->numVeiculos() != 0)
    {
        for (int i = 0; i < this->numVeiculos(); i++)
        {
            if (this->veiculos[i]->getAno() == anoM)
                veicM.push_back(this->veiculos[i]);
        }
    }
    else
    {
        cerr << "no veicles available";
        return {};
    }
    return  veicM;
}

float Frota::totalImposto() const {
    float imposto = 0;

    if (this->numVeiculos() != 0)
    {
        for (int i = 0; i < this->numVeiculos(); i++)
        {
            imposto += this->veiculos[i]->calcImposto();
        }
    }
    return imposto;
}


