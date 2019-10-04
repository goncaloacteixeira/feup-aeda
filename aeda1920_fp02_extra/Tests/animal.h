
#ifndef SRC_ANIMAL_H_
#define SRC_ANIMAL_H_

#include "veterinario.h"
#include <string>
using namespace std;


class Animal {
protected:
	string nome;
	int idade;
	Veterinario *vet;
	static int maisJovem;
public:
	Animal(string nome, int idade);
	virtual ~Animal(){};
	string getNome() const;
	//completar
};


class Cao: public Animal {
	string raca;
public:
	Cao(string nome, int idade, string raca);
	//completar
};


class Voador {
	int velocidade_max;
	int altura_max;
public:
	Voador(int vmax, int amax);
    virtual ~Voador(){};
	//completar
};


class Morcego: public Animal, public Voador {
public:
	Morcego(string nome, int idade, int vmax, int amax);
	//completar
};


#endif /* SRC_ANIMAL_H_ */
