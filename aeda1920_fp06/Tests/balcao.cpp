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
    if (prox_saida < prox_chegada) {
        saida();
    }
    else
        chegada();
}

void Balcao::chegada()
{
    Cliente c;

    tempo_atual += prox_chegada;

    if (clientes.empty())
        prox_saida = c.getNumPresentes()*tempo_embrulho;
    else
        prox_saida -= prox_chegada;
    prox_chegada = rand() % 20 + 1;

    clientes.push(c);

    // cout << "Tempo atual: " << tempo_atual << endl;
    cout << "chegou novo cliente com " << c.getNumPresentes() << " presentes\n";

}

void Balcao::saida()
{
    tempo_atual += prox_saida;
    prox_chegada -= prox_saida;
    try {
        Cliente c = getProxCliente();
        clientes.pop();
        prox_saida = clientes.front().getNumPresentes()*tempo_embrulho;


        clientes_atendidos += 1;
        // tempo_atual += tempo_atual + c.getNumPresentes()*tempo_embrulho;

//    cout << "Tempo atual: " << tempo_atual << endl;
        cout << "saiu cliente com " << c.getNumPresentes() << " presentes\n";
    }
    catch (FilaVazia)
    {
        chegada();
    }

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

      
