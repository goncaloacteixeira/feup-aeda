#ifndef FROTA_H_
#define FROTA_H_

#include <vector>
#include "veiculo.h"
using namespace std;

class Frota {
	vector<Veiculo *> veiculos;
public:
    Frota();
    void adicionaVeiculo(Veiculo *v1);
	friend ostream & operator<<(ostream & o, const Frota & f);
    int numVeiculos() const;
	int menorAno() const;
    float totalImposto() const;

    vector<Veiculo *> operator () (int anoM) const;
};

#endif /*FROTA_H_*/
