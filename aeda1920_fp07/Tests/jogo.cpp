#include "jogo.h"
#include <sstream>


//a alterar
ostream &operator << (ostream &os, Circulo &c1)
{
	return os;
}


Jogo::Jogo(int niv, vector<int> &pontos, vector<bool> &estados)
{
    jogo = iniciaJogo(0,niv,pontos,estados);
}

string Jogo::escreveJogo()
{
    string s;
	BTItrLevel<Circulo> it(jogo);
	while (!it.isAtEnd()) {
	    s += to_string(it.retrieve().getPontuacao()) + "-";
        (it.retrieve().getEstado()) ? s += "true-" : s += "false-";
        s += to_string(it.retrieve().getNVisitas()) + "\n";
        it.advance();
	}
	return s;
}

//a alterar
int Jogo::jogada()
{
	return 0;
}


//a alterar
int Jogo::maisVisitado()
{
	return 0;
}

BinaryTree<Circulo> Jogo::iniciaJogo(int pos, int niv, vector<int> &pontos, vector<bool> &estados) {
    Circulo c1(pontos[pos],estados[pos]);
    if (niv==0) return BinaryTree<Circulo>(c1);
    BinaryTree<Circulo> filhoEsq=
            iniciaJogo(2*pos+1,niv-1,pontos, estados);
    BinaryTree<Circulo> filhoDir=
            iniciaJogo(2*pos+2,niv-1,pontos, estados);
    return BinaryTree<Circulo>(c1, filhoEsq, filhoDir);
}

