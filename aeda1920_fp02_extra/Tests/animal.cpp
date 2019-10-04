#include "animal.h"
#include <vector>

using namespace std;

/*
 * Classe Animal
 */

int Animal::maisJovem = 1000000;

Animal::Animal(string nome, int idade) {
    this->nome = nome;
    this->idade = idade;

    this->vet = nullptr;

    if (idade <= maisJovem)
        maisJovem = idade;
}

int Animal::getMaisJovem() {
    return maisJovem;
}

bool Animal::eJovem() {
    return false;
}

string Animal::getNome() const {
    return nome;
}


string Animal::getInformacao() {
    if (vet != nullptr)
    {
        return nome + ", " + to_string(idade) + ", " + vet->getNome() + ", " + to_string(vet->getCod());
    }
    return nome + ", " + to_string(idade);
}

/*
 * Classe Cao
 */

Cao::Cao(string nome, int idade, string raca) : Animal(nome, idade){
    this->raca = raca;
}

bool Cao::eJovem() {
    if (idade < 5)
        return true;
    return  false;
}

string Cao::getInformacao() {
    return Animal::getInformacao() + ", " + raca;
}

/*
 * Classe Voador
 */

Voador::Voador(int vmax, int amax) {
    this->velocidade_max = vmax;
    this->altura_max = amax;
}

int Voador::getVmax() {
    return velocidade_max;
}

int Voador::getAmax() {
    return altura_max;
}

/*
 * Classe Morcego
 */

Morcego::Morcego(string nome, int idade, int vmax, int amax) : Animal(nome, idade), Voador(vmax, amax){
    // nothing to be done here
}

bool Morcego::eJovem() {
    if (idade < 4)
        return true;
    return  false;
}

string Morcego::getInformacao() {
    return Animal::getInformacao() + ", " + to_string(this->getVmax()) + ", " + to_string(this->getAmax());
}


