#include "aposta.h"
#include <iostream>
#include <sstream>

using namespace std;

// a alterar
bool Aposta::contem(unsigned num) const
{
	return true;
}

//a alterar

void Aposta::geraAposta(const vector<unsigned> & valores, unsigned n) {
    for (auto &number : valores) {
        if (n == 0) return;
        if (numeros.find(number) == numeros.end()) {
            numeros.insert(number);
            n--;
        }
    }
}

//a alterar
unsigned Aposta::calculaCertos(const tabHInt & sorteio) const
{
    return 0;
}





