#include "veterinario.h"
#include <sstream>

using namespace std;

string Veterinario::getNome() const {
	return nome;
}

long Veterinario::getCod() const {
    return codOrdem;
}

Veterinario::Veterinario(string nome, int cod) {
    this->nome = nome;
    this->codOrdem = cod;
}



