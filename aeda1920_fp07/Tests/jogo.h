#ifndef JOGO_H_
#define JOGO_H_

#include "binaryTree.h"
#include <iostream>
#include <stdlib.h>
using namespace std;


class Circulo {
 int pontuacao;
 bool estado;
 int nVisitas;
public:
 Circulo(int p=0, bool e=false): pontuacao(p), estado(e), nVisitas(0) {}
 int getPontuacao() const { return pontuacao; }
 bool getEstado() const { return estado; }
 void mudaEstado() { if (estado==false) estado=true; else estado=false; }
 int getNVisitas() const { return nVisitas; }
 friend ostream &operator << (ostream &os, Circulo &c1);
};



class Jogo {
	BinaryTree<Circulo> jogo;
public:
	Jogo(int niv, vector<int> &pontos, vector<bool> &estados);
	string escreveJogo();
	int jogada();
	int maisVisitado();
	BinaryTree<Circulo> &getJogo() { return jogo; }
};


#endif
