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
	bool animalJovem(string nomeA);
    void alocaVeterinarios(ifstream &isV);
    void atribuirVeterinarios();
    bool removeVeterinario(string nomeV);

    bool operator < (Zoo& zoo2) const;
};


#endif /* ZOO_H_ */
