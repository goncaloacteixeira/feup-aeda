#include "jogador.h"

void Jogador::adicionaAposta(const Aposta & ap)
{
    apostas.insert(ap);
}

unsigned Jogador::apostasNoNumero(unsigned num) const
{
	int count = 0;
	for (auto &aposta : apostas)
	    if (aposta.contem(num))
	        count++;
	return count;
}

//a alterar
tabHAposta Jogador::apostasPremiadas(const tabHInt & sorteio) const
{
	tabHAposta money;
	return money;
}
