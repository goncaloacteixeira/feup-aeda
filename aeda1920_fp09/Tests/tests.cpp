#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include <string>
#include "aposta.h"
#include "jogador.h"


using testing::Eq;


TEST(test_1, a_GeraAposta){
    vector<unsigned> vals;
    vals.push_back(30); vals.push_back(45); vals.push_back(22);
    vals.push_back(17); vals.push_back(45); vals.push_back(8);
    vals.push_back(30); vals.push_back(15); vals.push_back(24);
    vals.push_back(22);
    Aposta ap1;
    ap1.geraAposta(vals,6);
    EXPECT_EQ(6, ap1.getNumeros().size());
}

TEST(test_1, b_VerificaAposta){
    vector<unsigned> vals;
    vals.push_back(30); vals.push_back(45); vals.push_back(22);
    vals.push_back(17); vals.push_back(45); vals.push_back(8);
    vals.push_back(30); vals.push_back(15); vals.push_back(24);
    vals.push_back(22);
    Aposta ap1;
    ap1.geraAposta(vals,6);
    EXPECT_EQ(true, ap1.contem(30));
    EXPECT_EQ(true, ap1.contem(45));
    EXPECT_EQ(true, ap1.contem(15));
    EXPECT_EQ(false, ap1.contem(21));
}

TEST(test_1, c_ContaAposta){
    vector<unsigned> vals;
    vals.push_back(30); vals.push_back(45); vals.push_back(22);
    vals.push_back(17); vals.push_back(45); vals.push_back(8);
    vals.push_back(30); vals.push_back(15); vals.push_back(24);
    vals.push_back(22);
    Aposta ap1;
    ap1.geraAposta(vals,6);
    vector<unsigned> valsF;
    valsF.push_back(44); valsF.push_back(18); valsF.push_back(22);
    valsF.push_back(33); valsF.push_back(45); valsF.push_back(8);
    Aposta chave;
    chave.geraAposta(valsF,6);
    EXPECT_EQ(3,ap1.calculaCertos(chave.getNumeros()));
}

TEST(test_2, a_JogadorAdicionaAposta){
    Jogador jogador1("Rui");
    vector<unsigned> vals;
    vals.push_back(30); vals.push_back(45); vals.push_back(22);
    vals.push_back(17); vals.push_back(45); vals.push_back(8);
    vals.push_back(30); vals.push_back(15); vals.push_back(24);
    vals.push_back(22);
    Aposta ap1;
    ap1.geraAposta(vals,6);
    jogador1.adicionaAposta(ap1);
    vals.clear();
    vals.push_back(3); vals.push_back(44); vals.push_back(22);
    vals.push_back(15); vals.push_back(44); vals.push_back(3);
    vals.push_back(34); vals.push_back(20); vals.push_back(17);
    Aposta ap2;
    ap2.geraAposta(vals,6);
    jogador1.adicionaAposta(ap2);
    vals.clear();
    vals.push_back(41); vals.push_back(32); vals.push_back(12);
    vals.push_back(15); vals.push_back(28); vals.push_back(32);
    vals.push_back(12); vals.push_back(41); vals.push_back(4);
    Aposta ap3;
    ap3.geraAposta(vals,6);
    jogador1.adicionaAposta(ap3);
    EXPECT_EQ(3,jogador1.getNumApostas());
}

TEST(test_2, b_JogadorApostasEmNumero){
    Jogador jogador1("Rui");
    vector<unsigned> vals;
    vals.push_back(30); vals.push_back(45); vals.push_back(22);
    vals.push_back(17); vals.push_back(45); vals.push_back(8);
    vals.push_back(30); vals.push_back(15); vals.push_back(24);
    vals.push_back(22);
    Aposta ap1;
    ap1.geraAposta(vals,6);
    jogador1.adicionaAposta(ap1);
    vals.clear();
    vals.push_back(3); vals.push_back(44); vals.push_back(22);
    vals.push_back(15); vals.push_back(44); vals.push_back(3);
    vals.push_back(34); vals.push_back(20); vals.push_back(17);
    Aposta ap2;
    ap2.geraAposta(vals,6);
    jogador1.adicionaAposta(ap2);
    vals.clear();
    vals.push_back(41); vals.push_back(32); vals.push_back(12);
    vals.push_back(15); vals.push_back(28); vals.push_back(32);
    vals.push_back(12); vals.push_back(41); vals.push_back(4);
    Aposta ap3;
    ap3.geraAposta(vals,6);
    jogador1.adicionaAposta(ap3);
    EXPECT_EQ(2,jogador1.apostasNoNumero(22));
}

TEST(test_2, c_JogadorApostasPremiadas){
    Jogador jogador1("Rui");
    vector<unsigned> vals;
    vals.push_back(30); vals.push_back(45); vals.push_back(22);
    vals.push_back(17); vals.push_back(45); vals.push_back(8);
    vals.push_back(30); vals.push_back(18); vals.push_back(24);
    vals.push_back(22);
    Aposta ap1;
    ap1.geraAposta(vals,6);
    jogador1.adicionaAposta(ap1);
    vals.clear();
    vals.push_back(3); vals.push_back(4); vals.push_back(22);
    vals.push_back(15); vals.push_back(4); vals.push_back(3);
    vals.push_back(34); vals.push_back(20); vals.push_back(17);
    Aposta ap2;
    ap2.geraAposta(vals,6);
    jogador1.adicionaAposta(ap2);
    vals.clear();
    vals.push_back(45); vals.push_back(32); vals.push_back(18);
    vals.push_back(15); vals.push_back(8); vals.push_back(32);
    vals.push_back(18); vals.push_back(45); vals.push_back(33);
    Aposta ap3;
    ap3.geraAposta(vals,6);
    jogador1.adicionaAposta(ap3);

    vector<unsigned> valsF;
    valsF.push_back(44); valsF.push_back(18); valsF.push_back(22);
    valsF.push_back(33); valsF.push_back(45); valsF.push_back(8);
    Aposta chave;
    chave.geraAposta(valsF,6);

    EXPECT_EQ(4,ap1.calculaCertos(chave.getNumeros()));
    EXPECT_EQ(1,ap2.calculaCertos(chave.getNumeros()));
    EXPECT_EQ(4,ap3.calculaCertos(chave.getNumeros()));

    EXPECT_EQ(2,jogador1.apostasPremiadas(chave.getNumeros()).size());
}