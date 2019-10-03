#ifndef FROTA_H_
#define FROTA_H_

#include <vector>
#include "veiculo.h"
using namespace std;

class Frota {
	vector<Veiculo *> veiculos;
public:
	friend ostream & operator<<(ostream & o, const Frota & f);
};

#endif /*FROTA_H_*/
