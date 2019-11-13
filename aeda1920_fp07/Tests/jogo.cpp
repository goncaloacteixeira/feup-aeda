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

//a alterar
string Jogo::escreveJogo()
{
	return "";
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

