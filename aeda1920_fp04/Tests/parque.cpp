#include "parque.h"
#include <algorithm>
#include <vector>

using namespace std;

ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli):
	lotacao(lot), numMaximoClientes(nMaxCli) {
    numClientes = 0;
    vagas=lot; 
}

ParqueEstacionamento::~ParqueEstacionamento() {}

vector<InfoCartao> ParqueEstacionamento::getClientes() const { return clientes; }

unsigned int ParqueEstacionamento::getNumLugares() const { return lotacao; }

unsigned int ParqueEstacionamento::getNumLugaresOcupados() const { return lotacao-vagas; }


int ParqueEstacionamento::posicaoCliente(const string &nome) const
{
    for (int i = 0; i < this->clientes.size(); i++) {
        if (clientes[i].nome == nome)
            return i;
    }
    return -1;
}

int ParqueEstacionamento::getFrequencia(const string &nome) const
{
    int pos = posicaoCliente(nome);
    if (pos != -1) {
        return clientes[pos].frequencia;
    }
    throw ClienteNaoExistente(nome);
}

bool ParqueEstacionamento::adicionaCliente(const string & nome)
{
 	if ( numClientes == numMaximoClientes ) return false;
	if ( posicaoCliente(nome) != -1 ) return false;
	InfoCartao info;
	info.nome = nome;
    info.presente = false;
    info.frequencia = 0;
	clientes.push_back(info);
	numClientes++;
	return true;
}

bool ParqueEstacionamento::retiraCliente(const string & nome)
{
	for (vector<InfoCartao>::iterator it = clientes.begin(); it != clientes.end(); it++)
		if ( it->nome == nome ) {
			if ( it->presente == false ) {
				clientes.erase(it);
				numClientes--;
				return true;
			}
			else return false;
		}
	return false;
}

bool ParqueEstacionamento::entrar(const string & nome)
{
	if ( vagas == 0 ) return false;
	int pos = posicaoCliente(nome);
	if ( pos == -1 ) return false;
	if ( clientes[pos].presente == true ) return false;

	clientes[pos].frequencia += 1;
	clientes[pos].presente = true;
	vagas--;
	return true;
}


bool ParqueEstacionamento::sair(const string & nome)
{
	int pos = posicaoCliente(nome);
	if ( pos == -1 ) return false;
	if ( clientes[pos].presente == false ) return false;
	clientes[pos].presente = false;
	vagas++;
	return true;
}


void ParqueEstacionamento::ordenaClientesPorFrequencia()
{
    InfoCartao temp;
    int i, j;
    for(j = 1; j < clientes.size(); j++)    // Start with 1 (not 0)
    {
        temp = clientes[j];
        for(i = j - 1; (i >= 0) && (clientes[i].frequencia <= temp.frequencia); i--)   // Smaller values move up
        {
            if (clientes[i].frequencia == temp.frequencia && clientes[i].nome > temp.nome)    // test if name comes after, if true, then put it right to the previous value
                clientes[i+1] = clientes[i];
            if (clientes[i].frequencia != temp.frequencia)
                clientes[i+1] = clientes[i];
        }
        clientes[i+1] = temp;    //Put key into its proper location
    }
}


void ParqueEstacionamento::ordenaClientesPorNome()
{
    sort(clientes.begin(),
            clientes.end(),
            [](const InfoCartao& lhs, const InfoCartao& rhs)
            {
                return lhs.nome < rhs.nome;
            });
}


vector<string> ParqueEstacionamento::clientesGamaUso(int n1, int n2) {
    vector<string> nomes = {};
    if (this->numClientes != 0) {
        this->ordenaClientesPorFrequencia();
        for (int i = 0; i < clientes.size(); i++) {
            if (clientes[i].frequencia >= n1 && clientes[i].frequencia <= n2) {
                nomes.push_back(clientes[i].nome);
            }
        }
    }
    return nomes;
}


ostream & operator<<(ostream & os, const ParqueEstacionamento & pe) {
    if (pe.numClientes != -1) {
        for (int i = 0; i < pe.numClientes; i++) {
            os << "Nome: " << pe.clientes[i].nome << "\nFrequencia: " << pe.clientes[i].frequencia << "\nPresente? ";
            (pe.clientes[i].presente) ? os << "Sim\n" : os << "Nao\n";
            if (i != pe.numClientes - 1)
                os << "::::::::::\n";
        }
    }
    return os;
}


InfoCartao ParqueEstacionamento::getClienteAtPos(vector<InfoCartao>::size_type p) const
{
    if (this->numClientes == 0)
        throw PosicaoNaoExistente(p);
    if (p >= clientes.size())
        throw PosicaoNaoExistente(p);
    return clientes[p];
}
