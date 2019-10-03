#include "parque.h"
#include <vector>

using namespace std;

// Aliena a)

ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli):
    vagas(lot), numMaximoClientes(nMaxCli), lotacao(lot){
}

unsigned int ParqueEstacionamento::getNumLugares() const {
    return lotacao;
}

unsigned int ParqueEstacionamento::getNumMaximoClientes() const {
    return numMaximoClientes;
}

// Aliena b)

int ParqueEstacionamento::posicaoCliente(const string &nome) const {
    for (int i = 0; i < clientes.size(); i++) {
        if (clientes[i].nome == nome) {
            return i;
        }
    }
    return -1;
}

bool ParqueEstacionamento::adicionaCliente(const string &nome) {
    if (numMaximoClientes == clientes.size() )
        return false;

    else
    {
        InfoCartao newClient;
        newClient.nome = nome;
        newClient.presente = 0;
        clientes.push_back(newClient);
        return true;
    }
}


// aliena c)

bool ParqueEstacionamento::entrar(const string &nome) {
    if (vagas == 0)
        return false;
    else if (posicaoCliente(nome) == -1)
        return false;
    else if (clientes[posicaoCliente(nome)].presente == true)
        return false;

    else {
        clientes[posicaoCliente(nome)].presente = 1;
        vagas -= 1;
        return true;
    }
}


// alinea d)

bool ParqueEstacionamento::retiraCliente(const string &nome) {
    if (posicaoCliente(nome) == -1)         // cliente não existe logo não da para remover o cliente
        return false;
    if (!clientes[posicaoCliente(nome)].presente)   // cliente existe e está fora do parque logo podemos retirar o cliente
    {
        clientes.erase(clientes.begin() + posicaoCliente(nome));
        return true;
    }
    return false;
}

// alinea e)

bool ParqueEstacionamento::sair(const string &nome) {
    if (posicaoCliente(nome) == -1)
        return false;
    if (clientes[posicaoCliente(nome)].presente == false)
        return false;
    vagas += 1;
    clientes[posicaoCliente(nome)].presente = false;
    return true;
}

// alinea f)

unsigned int ParqueEstacionamento::getNumLugaresOcupados() const {
    return lotacao - vagas;
}

unsigned int ParqueEstacionamento::getNumClientesAtuais() const {
    return clientes.size();
}

// construção do operador

const ParqueEstacionamento &ParqueEstacionamento::operator+=(const ParqueEstacionamento &p2) {
    if (numMaximoClientes - clientes.size() >= p2.clientes.size())
    {
        for (int i = 0; i < p2.clientes.size(); ++i) {
            clientes.push_back(p2.clientes[i]);
        }
    }
    return *this;
}
