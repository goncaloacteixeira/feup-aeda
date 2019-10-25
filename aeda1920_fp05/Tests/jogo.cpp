/*
 * jogo.cpp
 */

#include "jogo.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


unsigned int Jogo::numPalavras(string frase)
{
  if ( frase.length() == 0 ) return 0;

  unsigned n=1;
  size_t pos = frase.find(' ');
  while (pos != string::npos) {
    frase = frase.substr(pos+1);
    pos = frase.find(' ');
    n++;
  }
  return n;
}

Jogo::Jogo()
{
    this->criancas= {};
}

Jogo::Jogo(list<Crianca>& lc2)
{
    this->criancas = lc2;
}

void Jogo::insereCrianca(const Crianca &c1)
{
    criancas.push_back(c1);
}

list<Crianca> Jogo::getCriancasJogo() const
{
    return criancas;
}

string Jogo::escreve() const
{
    string res = "";
    for (_List_const_iterator<Crianca> it = criancas.begin(); it != criancas.end(); it++)
    {
        res += it->escreve() + "\n";
    }
    return res;
}

Crianca& Jogo::perdeJogo(string frase)
{
    Crianca *c1;
    unsigned int length = numPalavras(frase);
    if (length == 0) {
        *c1 = criancas.front();
        criancas.erase(criancas.begin());
        return *c1;
    }
    int index;
    if (length > criancas.size())
    {
        index = length % criancas.size();
    }
    else
    {
        index = length - 1;
    }
    list<Crianca>::iterator it = criancas.begin();
    advance(it, index);
    criancas.erase(it);
    return *it;
}

list<Crianca>& Jogo::inverte()
{
    criancas.reverse();
    return criancas;
}

// a implementar
list<Crianca> Jogo::divide(unsigned id)
{
    list<Crianca> nc;
    for (Crianca crianca : criancas) {
        if (crianca.getIdade() > id)
            nc.push_back(crianca);
    }
    return nc;
}

void Jogo::setCriancasJogo(const list<Crianca>& l1)
{
    this->criancas = l1;
}

bool Jogo::operator==(Jogo& j2)
{
	if (this->criancas == j2.criancas)
	    return true;
	return false;
}

list<Crianca> Jogo::baralha() const
{

}
