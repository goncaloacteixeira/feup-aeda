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
    return (this->palavra < ps1.palavra);
}

//a alterar
void Dicionario::lerDicionario(ifstream &fich) {

    PalavraSignificado palavra("", "");

    string line1, line2;
    while (getline(fich, line1)) {
        getline(fich, line2);
        palavra = PalavraSignificado(line1, line2);
        palavras.insert(palavra);
    }


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

