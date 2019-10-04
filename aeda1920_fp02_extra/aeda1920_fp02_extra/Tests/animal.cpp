
#include "animal.h"
#include <sstream>
using namespace std;

/*
 * Classe Animal
 */

int Animal::maisJovem = 100000;

Animal::Animal(string nome, int idade) {
    this->nome = nome;
    this->idade = idade;
    if (idade <= maisJovem) {
        maisJovem = idade;
    }
}

int Animal::getMaisJovem() {
    return maisJovem;
}

bool Animal::eJovem() {
    return 0;
}


Cao::Cao(string nome, int idade, string raca) : Animal(nome, idade){
    this->raca = raca;
}

bool Cao::eJovem() {
    if (idade < 5) {
        return true;
    } return false;
}


Voador::Voador(int vmax, int amax) {
    this->velocidade_max = vmax;
    this->altura_max = amax;
}

Morcego::Morcego(string nome, int idade, int vmax, int amax) : Animal(nome, idade), Voador(vmax, amax) {
    // nothing to be done here
}

bool Morcego::eJovem() {
    if (idade < 4) {
        return true;
    } return false;
}

string Animal::getNome() const {
	return nome;
}