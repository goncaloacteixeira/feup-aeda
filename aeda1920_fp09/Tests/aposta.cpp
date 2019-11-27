#include "aposta.h"
#include <iostream>
#include <sstream>

using namespace std;

bool Aposta::contem(unsigned num) const {
    return !(numeros.find(num) == numeros.end());
}


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
    unsigned count = 0;
    for (auto &num : numeros)
        if (sorteio.find(num) != sorteio.end())
            count++;

    return count;
}





