/*
 * crianca.h
 */

#ifndef CRIANCA_H_
#define CRIANCA_H_

#include <string>
#include <sstream>
using namespace std;

class Crianca {
	string nome;
	int idade;
public:
	Crianca();
	Crianca(string nome, unsigned idade);
	Crianca(const Crianca& c1);
	string getNome() const;
	unsigned getIdade() const;
	bool operator==(const Crianca& c2) const;
	string escreve() const;
	friend ostream & operator<<(ostream & o, const Crianca & d);
};

#endif /* CRIANCA_H_ */
