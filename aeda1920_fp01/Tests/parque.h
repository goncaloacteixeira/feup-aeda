#include <iostream>
#include <string>
#include <vector>

using namespace std;

class InfoCartao {
public:
	string nome;
	bool presente;
};

class ParqueEstacionamento {
private:
	unsigned int vagas;
	const unsigned int lotacao;
	vector<InfoCartao> clientes;
	const unsigned int numMaximoClientes;
public:
	ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli);
	bool adicionaCliente(const string & nome);
	bool retiraCliente(const string & nome);
	bool entrar(const string & nome);
	bool sair(const string & nome);
	int posicaoCliente(const string & nome) const;

    unsigned int getNumLugares() const;
	unsigned int getNumMaximoClientes() const;
	unsigned int getNumLugaresOcupados() const;
	unsigned int getNumClientesAtuais() const;
	const ParqueEstacionamento & operator += (const ParqueEstacionamento & p2);
};
