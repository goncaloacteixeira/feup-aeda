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

tabHAposta Jogador::apostasPremiadas(const tabHInt & sorteio) const
{
	tabHAposta money;

	for (auto &aposta : apostas) {
	    int aux = 0;
	    for (auto &key : sorteio)
	        if (aposta.contem(key)) {
	            aux++;
	        }
	    if (aux > 3)
	        money.insert(aposta);
	}
	return money;
}
