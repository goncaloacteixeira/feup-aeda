#include <iostream>
#include <string>
#include <fstream>
#include "dicionario.h"
#include "bst.h"

using namespace std;

BST<PalavraSignificado> Dicionario::getPalavras() const {
	return palavras;
}

bool PalavraSignificado::operator < (const PalavraSignificado &ps1) const {
    return (this->palavra < ps1.palavra);
}

void Dicionario::lerDicionario(ifstream &fich) {

    PalavraSignificado palavra("", "");

    string line1, line2;
    while (getline(fich, line1)) {
        getline(fich, line2);
        palavra = PalavraSignificado(line1, line2);
        palavras.insert(palavra);
    }
}

string Dicionario::consulta(string palavra) const
{
    BSTItrIn<PalavraSignificado> it(palavras);
    PalavraSignificado last("", "");
    while(!it.isAtEnd()) {
        if (it.retrieve().getPalavra() == palavra)
            return it.retrieve().getSignificado();
        if (it.retrieve().getPalavra() > palavra) {
            throw PalavraNaoExiste(last, it.retrieve());
        }
        last = it.retrieve();
        it.advance();
    }
    throw PalavraNaoExiste(last, PalavraSignificado("",""));
}

//a alterar
bool Dicionario::corrige(string palavra, string significado)
{
    try {
        consulta(palavra);
        BSTItrIn<PalavraSignificado> it(palavras);
        while(!it.isAtEnd()) {
            if (it.retrieve().getPalavra() == palavra) {
                PalavraSignificado find = palavras.find(PalavraSignificado(it.retrieve().getPalavra(), it.retrieve().getSignificado()));
                palavras.remove(find);
                palavras.insert(PalavraSignificado(palavra, significado));
                return true;
            }
            it.advance();
        }
    }
    catch (PalavraNaoExiste &c){
        palavras.insert(PalavraSignificado(palavra, significado));
        return false;
    }
}

void Dicionario::imprime() const
{
    BSTItrIn<PalavraSignificado> it(palavras);
    while(!it.isAtEnd()) {
        cout << it.retrieve().getPalavra() << endl;
        cout << it.retrieve().getSignificado() << endl;
        it.advance();
    }
}

