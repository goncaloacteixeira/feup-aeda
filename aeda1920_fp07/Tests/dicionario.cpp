#include <iostream>
#include <string>
#include <fstream>
#include "dicionario.h"
#include "bst.h"

using namespace std;

BST<PalavraSignificado> Dicionario::getPalavras() const {
	return palavras;
}

//a alterar
bool PalavraSignificado::operator < (const PalavraSignificado &ps1) const {
     return true;
}

//a alterar
void Dicionario::lerDicionario(ifstream &fich)
{
     return;
}

//a alterar
string Dicionario::consulta(string palavra) const
{
    return "";
}

//a alterar
bool Dicionario::corrige(string palavra, string significado)
{
    return true;
}

//a alterar
void Dicionario::imprime() const
{
    return;
}

