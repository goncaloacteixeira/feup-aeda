#include <queue>
#include <cstdlib>
#include "balcao.h"
#include "exceptions.h"

using namespace std;

//a alterar
Cliente::Cliente() {
}

//a alterar
int Cliente::getNumPresentes() const {
    return 0;
}

//a alterar
Balcao::Balcao(int te): tempo_embrulho(te) {
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

//a alterar
int Balcao::getTempoEmbrulho() const {
	return 0;
}

//a alterar
int Balcao::getProxSaida() const {
	return 0;
}

//a alterar
int Balcao::getClientesAtendidos() const {
	return 0;
}

//a alterar
Cliente & Balcao::getProxCliente() {
    Cliente *c = new Cliente();
    return *c;
}

      
