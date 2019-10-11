#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Versao da classe generica Grafo usando a classe vector
 */

template <class N, class A> class Aresta;

template <class N, class A>
class No {
public:
	N info;
	vector< Aresta<N,A> > arestas;
	No(N inf) {
		info = inf;
	}
};

template <class N, class A>
class Aresta {
public:
	A valor;
	No<N,A> *destino;
	Aresta(No<N,A> *dest, A val) {
		valor = val;
		destino = dest;
	}
};

template <class N, class A> 
class Grafo { 
	vector< No<N,A> *> nos;
  public: 
    Grafo();
    ~Grafo();
    Grafo & inserirNo(const N &dados);
    Grafo & inserirAresta(const N &inicio, const N &fim, const A &val);
    Grafo & eliminarAresta(const N &inicio, const N &fim);
    A & valorAresta(const N &inicio, const N &fim);
    int numArestas(void) const;
    int numNos(void) const;
    void imprimir(std::ostream &os) const; 
};

template<class N, class A>
Grafo<N, A>::Grafo() {
    this->nos = {};
}

template<class N, class A>
Grafo<N, A>::~Grafo() {
}


template <class N, class A>
std::ostream & operator<<(std::ostream &out, const Grafo<N,A> &g);


// excecao NoRepetido
template <class N>
class NoRepetido
{
public:
   N info;
   NoRepetido(N inf) { info=inf; }
};
template <class N> 
std::ostream & operator<<(std::ostream &out, const NoRepetido<N> &no)
{ out << "No repetido: " << no.info; return out; }


// excecao NoInexistente
template <class N>
class NoInexistente {
public:
	N info;
	NoInexistente(N inf) {
		info = inf;
	}
};

template <class N>
std::ostream & operator<<(std::ostream &out, const NoInexistente<N> &ni)
{ out << "No inexistente: " << ni.info; return out; }


// excecao ArestaRepetida
template <class N>
class ArestaRepetida {
public:
    N inicio;
    N destino;
    ArestaRepetida(N inicio, N destino) {
        this->inicio = inicio;
        this->destino = destino;
    }
};
template <class N>
std::ostream & operator<<(std::ostream &out, const ArestaRepetida<N> &ni)
{ out << "Aresta repetida: " << ni.inicio << " , " << ni.destino; return out; }

// excecao ArestaInexistente
template <class N>
class ArestaInexistente {
public:
    N inicio;
    N destino;
    ArestaInexistente(N inicio, N destino) {
        this->inicio = inicio;
        this->destino = destino;
    }
};
template <class N>
std::ostream & operator<<(std::ostream &out, const ArestaInexistente<N> &ni)
{ out << "Aresta inexistente: " << ni.inicio << " , " << ni.destino; return out; }

template<class N, class A>
int Grafo<N, A>::numNos(void) const {
    return nos.size();
}

template<class N, class A>
int Grafo<N, A>::numArestas(void) const {
    int count = 0;
    if (this->numNos() == 0)
        return count;
    for (int i = 0; i < numNos(); i++)
    {
        count += nos[i]->arestas.size();
    }
    return count;
}

template<class N, class A>
Grafo<N, A> &Grafo<N, A>::inserirNo(const N &dados) {
    if (this->numNos() != 0) {
        for (int i = 0; i < this->numNos(); i++) {
            if (nos[i]->info == dados) {
                throw NoRepetido<N>(dados);
            }
        }
    }
    nos.push_back(new No<N, A>(dados));
    return *this;
}

template<class N, class A>
Grafo<N, A> &Grafo<N, A>::inserirAresta(const N &inicio, const N &fim, const A &val) {
    if (this->numNos() == 0)
        throw NoInexistente<N>(inicio);
    bool inicioExiste = false;
    for (int i = 0; i < this->numNos(); i++){
        if (nos[i]->info == inicio)
            inicioExiste = true;
    }
    for (int i = 0; i < this->numNos(); i++)
    {
        if (nos[i]->info == inicio){
            if (nos[i]->arestas.size() != 0) {
                for (int j = 0; j < nos[i]->arestas.size(); j++)
                {
                    if (nos[i]->arestas[j].destino->info == fim)
                    {
                        throw ArestaRepetida<N>(inicio, fim);
                    }
                }
            }
            nos[i]->arestas.push_back(Aresta<N,A>(new No<N,A>(fim), val));
            return *this;
        }
    }
    if (inicioExiste)
        throw NoInexistente<N>(fim);
    throw NoInexistente<N>(inicio);
}

template<class N, class A>
A &Grafo<N, A>::valorAresta(const N &inicio, const N &fim) {
    if (this->numArestas() == 0)
        throw ArestaInexistente<N>(inicio, fim);
    bool flag = false;
    bool inicioExiste = false;
    for (int i = 0; i < this->numNos(); i++){
        if (nos[i]->info == inicio)
            inicioExiste = true;
    }
    for (int i = 0; i < this->numNos(); i++)
    {
        if (nos[i]->info == inicio)
        {
            flag = true;
            if (nos[i]->arestas.size() != 0)
            {
                for (int j = 0; j < nos[i]->arestas.size(); j++)
                {
                    if (nos[i]->arestas[j].destino->info == fim)
                        return nos[i]->arestas[j].valor;
                }
            }
        }
    }
    if (flag)
        throw ArestaInexistente<N>(inicio, fim);
    if (inicioExiste)
        throw NoInexistente<N>(fim);
    throw NoInexistente<N>(inicio);
}

template<class N, class A>
Grafo<N,A> &Grafo<N, A>::eliminarAresta(const N &inicio, const N &fim) {
    if (this->numArestas() == 0)
        throw ArestaInexistente<N>(inicio, fim);
    bool inicioExiste = false;
    bool fimExiste = false;
    int i = 0;
    for (i; i < this->numNos(); i++){
        if (nos[i]->info == inicio) {
            inicioExiste = true;
            break;
        }
    }
    for (int k = 0; k < this->numNos(); k++){
        if (nos[k]->info == fim) {
            fimExiste = true;
            break;
        }
    }
    if (inicioExiste && fimExiste)
    {
        if (nos[i]->arestas.size() == 0)
            throw ArestaInexistente<N>(inicio, fim);
        for (int j = 0; j < nos[i]->arestas.size(); j++)
        {
            if (nos[i]->arestas[j].destino->info == fim)
            {
                nos[i]->arestas.erase(nos[i]->arestas.begin() + j);
                return *this;
            }
        }
        throw ArestaInexistente<N>(inicio, fim);
    }
    if (!inicioExiste)
        throw NoInexistente<N>(inicio);
    throw NoInexistente<N>(fim);
}





