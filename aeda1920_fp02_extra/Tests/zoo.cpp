#include "zoo.h"
#include <iostream>
#include <sstream>
#include <stdlib.h>
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


/*int Zoo::numVeterinarios() const {
	return veterinarios.size();
}*/

