#ifndef JOGADOR_H_
#define JOGADOR_H_

#include "aposta.h"
#include <string>
#include <utility>

using namespace std;

//a alterar
struct apostaHash
{
	int operator() (const Aposta & ap) const
	{
		return ap.getNumeros().size();
	}
	
	bool operator() (const Aposta & ap1, const Aposta & ap2) const
	{
	    for (auto &number : ap1.getNumeros())
	        if (!ap2.contem(number))
	            return false;
	    return true;
	}
};



typedef unordered_set<Aposta, apostaHash, apostaHash> tabHAposta;

class Jogador
{
	tabHAposta apostas;
	string nome;
public:
	Jogador(string nm="anonimo") { nome=nm; }
	void adicionaAposta(const Aposta & ap);
	unsigned apostasNoNumero(unsigned num) const;
	tabHAposta apostasPremiadas(const tabHInt & sorteio) const;
	unsigned getNumApostas() const { return apostas.size(); }
};

#endif /*JOGADOR1_H_*/
