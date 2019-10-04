#include "zoo.h"
#include <iostream>
#include <sstream>
#include <stdlib.h>
using namespace std;

/*
 * Classe Zoo
 */

int Zoo::numAnimais() const {
	return animais.size();
}

int Zoo::numVeterinarios() const {
	return veterinarios.size();
}

