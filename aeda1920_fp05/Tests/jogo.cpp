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

// a implementar
Jogo::Jogo()
{
}

// a implementar
Jogo::Jogo(list<Crianca>& lc2)
{
}

// a implementar
void Jogo::insereCrianca(const Crianca &c1)
{
}

// a implementar
list<Crianca> Jogo::getCriancasJogo() const
{
    list<Crianca> res;
    return res;
}

// a implementar
string Jogo::escreve() const
{
    string res;
    return res;
}

// a implementar
Crianca& Jogo::perdeJogo(string frase)
{
    Crianca *c1 = new Crianca();
    return *c1;
}

// a implementar
list<Crianca>& Jogo::inverte()
{
    return criancas;
}

// a implementar
list<Crianca> Jogo::divide(unsigned id)
{
    list<Crianca> res;
    return res;
}

// a implementar
void Jogo::setCriancasJogo(const list<Crianca>& l1)
{
}

// a implementar
bool Jogo::operator==(Jogo& j2)
{
	return true;
}

// a implementar
list<Crianca> Jogo::baralha() const
{
    list<Crianca> res;
    return res;
}
