#include <cstdlib>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
#include <time.h>
#include <string>
#include "Kart.h"

using namespace std;

//To help build better array
string itos(int i){
    stringstream s;
    s << i;
    return s.str();
}

void CGrupo::criaGrupo()
{
    float cilindradas[4]  = {134,250,450,600};
    bool avariados[3]  = {true,false,false};

    srand (1);   //Criar Pistas e Karts de Teste
    for(int i=1;i<=50;i++){
        vector<CKart> frota;
        for(int j=1;j<=50;j++){
            frota.push_back(CKart(avariados[rand()% 3],
                                  ("KART - "+itos(i))+itos(j),(i-1)*50+j,cilindradas[(rand() % 4)]));
        }
        adicionaPista(CPista("Pista - "+itos(i),frota));
    }
}


vector <CKart> CPista::getKartsAvariados()
{
    vector<CKart> aux;
    for (vector<CKart>::iterator it = frotaKartsPista.begin() ; it != frotaKartsPista.end(); ++it) {
        if ((it)->getAvariado()) aux.push_back((*it));
    }
    return aux;
}
 
//Exercicio 1 a)     
vector<CKart> CGrupo::ordenaKarts()
{
    vector<CKart> kar;
    // por cada kart em cada pista (range-based for loop)
    for (auto pista : this->pistasG)
        for (auto kart : pista.getFrotaActual())
            kar.push_back(kart);

    if (kar.empty())
        return kar;

    // BubbleSort
    for (unsigned int j = kar.size() - 1; j > 0; j--) {
        bool troca = false;
        for (unsigned int i = 0; i < j; i++)
            if (kar[i + 1].getNumero() < kar[i].getNumero()) {
                swap(kar[i], kar[i + 1]);
                troca = true;
            }
        if (!troca) return kar;
    }
}

//Exercicio 1 b)  
int CGrupo::numAvariados(int cilind)
{
    int count = 0;
    for (CPista pista : this->pistasG)
        for (CKart kart : pista.getKartsAvariados())
            if (kart.getCilindrada() == cilind)
                count++;
    return count;
}

//Exercicio 1 c)   
bool CPista::prepararCorrida(int numeroKarts, int cilind) {
    int count = 0;
    for (CKart kart : getFrotaActual())
        if (kart.getCilindrada() == cilind && !kart.getAvariado())
            count++;
    if (count < numeroKarts) {
        for (CKart kart : getFrotaActual())
            if (kart.getCilindrada() == cilind && !kart.getAvariado())
                this->kartsLinhaPartida.push(kart);
        return false;
    }
    else {
        for (CKart kart : getFrotaActual())
            if (kart.getCilindrada() == cilind && !kart.getAvariado())
                this->kartsLinhaPartida.push(kart);
        return true;
    }
}

//Exercicio 1 d) 
int CPista::inicioCorrida()
{
    int count = 0;
    while (!kartsLinhaPartida.empty()) {
        this->kartsEmProva.push_back(kartsLinhaPartida.front());
        kartsLinhaPartida.pop();
        count++;
    }
    return count;
}

