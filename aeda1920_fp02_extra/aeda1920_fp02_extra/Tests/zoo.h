#ifndef ZOO_H_
#define ZOO_H_

#include "animal.h"
#include <vector>


class Zoo {
	vector<Animal *> animais;
	vector<Veterinario *> veterinarios;
public:
	int numAnimais() const;
	int numVeterinarios() const;
	//completar
};


#endif /* ZOO_H_ */
