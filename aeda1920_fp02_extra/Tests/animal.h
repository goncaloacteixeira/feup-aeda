
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
	static int getMaisJovem();
	virtual bool eJovem();
	void setVet(Veterinario *vet);
	Veterinario getVet();
	// virtual ~Animal(){};
	string getNome() const;
	virtual string getInformacao();
	//completar
};


class Cao: public Animal {
	string raca;
public:
	Cao(string nome, int idade, string raca);
	bool eJovem();
    string getInformacao();
	//completar
};


class Voador {
	int velocidade_max;
	int altura_max;
public:
	Voador(int vmax, int amax);
	int getVmax();
	int getAmax();
    // virtual ~Voador(){};
	//completar
};


class Morcego: public Animal, public Voador {
public:
	Morcego(string nome, int idade, int vmax, int amax);
    bool eJovem();
    string getInformacao();
    //completar
};


#endif /* SRC_ANIMAL_H_ */
