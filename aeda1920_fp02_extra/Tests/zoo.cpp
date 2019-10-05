#include "zoo.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

/*
 * Classe Zoo
 */

Zoo::Zoo() {
    animais = {};
}

int Zoo::numAnimais() const {
    return animais.size();
}

void Zoo::adicionaAnimal(Animal *a1) {
    animais.push_back(a1);
}

string Zoo::getInformacao() {
    if (this->numAnimais() != 0)
    {
        string output = "\n" + animais[0]->getInformacao();
        for (int i = 1; i < this->numAnimais(); i++)
        {
             output += "\n" + animais[i]->getInformacao();
        }
        return output;
    }
    return "no animals to show info\n";
}

bool Zoo::animalJovem(string nomeA) {
    if (this->numAnimais() == 0)
        return false;

    for (int i = 0; i < this->numAnimais(); i++) {
        if (this->animais[i]->getNome() == nomeA) {
            if (this->animais[i]->eJovem())
                return true;
        }
    }
    return false;
}

void Zoo::atribuirVeterinarios() {
    if (animais.size() <= veterinarios.size()) {
        for (int i = 0; i < animais.size(); i++)
            animais[i]->setVet(veterinarios[i]);
    } else{
        for (int i = 0; i < veterinarios.size(); i++)
            animais[i]->setVet(veterinarios[i]);
    }
}

void Zoo::alocaVeterinarios(ifstream &isV) {
    string line;
    vector<string> info;
    while(getline(isV, line))
        info.push_back(line);

    for (int i = 0; i < info.size()/2; i++)
    {
        int cod;
        istringstream(info[2*i+1]) >> cod;
        Veterinario* vet = new Veterinario(info[2*i], cod);
        this->veterinarios.push_back(vet);
    }
    this->atribuirVeterinarios();
}

int Zoo::numVeterinarios() const {
    return veterinarios.size();
}

bool Zoo::removeVeterinario(string nomeV) {
    bool flag = false;

    if (this->numVeterinarios() != 0) {
        for (int i = 0; i < this->numVeterinarios(); i++) {
            if (this->veterinarios[i]->getNome() == nomeV) {
                flag = true;
                this->veterinarios.erase(this->veterinarios.begin() + i);
                break;
            }
        }
        this->atribuirVeterinarios();
    }
    return flag;
}

bool Zoo::operator<(Zoo &zoo2) const {
    if (this->numAnimais() == 0)
        return true;

    if (zoo2.numAnimais() == 0)
        return false;

    int idades1, idades2 = 0;

    for (int i = 0; i < this->numAnimais(); i++)
        idades1 += this->animais[i]->getIdade();

    for (int i = 0; i < zoo2.numAnimais(); i++)
        idades2 += zoo2.animais[i]->getIdade();

    if (idades1 < idades2)
        return true;
    else
        return false;
}


