#include <queue>
#include <cstdlib>
#include "balcao.h"
#include "exceptions.h"

using namespace std;

Cliente::Cliente() {
    numPresentes = rand() % 5 + 1;
}

int Cliente::getNumPresentes() const {
    return numPresentes;
}

Balcao::Balcao(int te): tempo_embrulho(te) {
    tempo_atual = 0;
    prox_chegada = rand() % 20 + 1;
    prox_saida = 0;
    clientes_atendidos = 0;
}

//a alterar
void Balcao:: proximoEvento()
{
}

//a alterar
void Balcao::chegada()
{
}

//a alterar
void Balcao::saida()
{
}


int Balcao::getTempoAtual() const { return tempo_atual; }

int Balcao::getProxChegada() const { return prox_chegada; }

//a alterar
ostream & operator << (ostream & out, const Balcao & b1)
{
     return out;
}

int Balcao::getTempoEmbrulho() const {
	return tempo_embrulho;
}

int Balcao::getProxSaida() const {
	return prox_saida;
}

int Balcao::getClientesAtendidos() const {
	return clientes_atendidos;
}

Cliente & Balcao::getProxCliente() {
    if (clientes.empty())
        throw FilaVazia();
    return clientes.front();
}

      
