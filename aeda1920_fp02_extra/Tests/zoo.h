#ifndef ZOO_H_
#define ZOO_H_

#include "animal.h"
#include <vector>
#include "veterinario.h"


class Zoo {
	vector<Animal *> animais;
	vector<Veterinario *> veterinarios;
public:
    Zoo();
    void adicionaAnimal(Animal *a1);
	int numAnimais() const;
	int numVeterinarios() const;
	string getInformacao();
	//completar
};


#endif /* ZOO_H_ */
