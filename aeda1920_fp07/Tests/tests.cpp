#include <gtest/gtest.h>
#include "jogo.h"
#include "dicionario.h"
#include <fstream>


using testing::Eq;


TEST(test_1, a_CriaDicionario){
    ifstream fich;
    fich.open("dic.txt");
    Dicionario d1;
    d1.lerDicionario(fich);
    fich.close();
    BST<PalavraSignificado> arvPals = d1.getPalavras();
    bool isEmp = arvPals.isEmpty();
    EXPECT_EQ(false, isEmp);
    if (isEmp==false) {
        BSTItrIn<PalavraSignificado> it(arvPals);
        it.advance();
        it.advance();
        EXPECT_EQ("gato", it.retrieve().getPalavra());
    }
}

TEST(test_1, b_ImprimeDicionario){
    cout << "Este teste nao falha. Verifique na consola os valores" << endl;
    EXPECT_TRUE(true);
    ifstream fich;
    fich.open("dic.txt");

    Dicionario d1;
    d1.lerDicionario(fich);
    fich.close();
    d1.imprime();
}

TEST(test_1, c_ConsultaDicionario){
    ifstream fich;
    fich.open("dic.txt");

    Dicionario d1;
    d1.lerDicionario(fich);
    fich.close();
    EXPECT_EQ("mamifero felino", d1.consulta("gato"));
    EXPECT_THROW(d1.consulta("rio"), PalavraNaoExiste);
    try {
        string signf=d1.consulta("janela");
    }
    catch (PalavraNaoExiste &e) {
        cout << "Apanhou excepcao: PalavraNaoExiste" << endl;
        EXPECT_EQ("ilha", e.getPalavraAntes());
        EXPECT_EQ("porto de terra emersa rodeada de agua", e.getSignificadoAntes());
        EXPECT_EQ("macaco", e.getPalavraApos());
        EXPECT_EQ("mamifero da ordem dos primatas", e.getSignificadoApos());
    }
}

TEST(test_1, d_CorrigeDicionario){
    ifstream fich;
    fich.open("dic.txt");

    Dicionario d1;
    d1.lerDicionario(fich);
    fich.close();
    EXPECT_EQ(true,d1.corrige("morango","fruto vermelho"));
    EXPECT_EQ("fruto vermelho", d1.consulta("morango"));
    EXPECT_EQ(false,d1.corrige("esquilo","pequeno mamifero roedor de cauda longa"));
    BST<PalavraSignificado> arvPals = d1.getPalavras();
    bool isEmp = arvPals.isEmpty();
    EXPECT_EQ(false, isEmp);
    if (isEmp==false) {
        BSTItrIn<PalavraSignificado> it(arvPals);
        it.advance();
        it.advance();
        EXPECT_EQ("esquilo", it.retrieve().getPalavra());
        EXPECT_EQ("pequeno mamifero roedor de cauda longa", d1.consulta("esquilo"));
    }
}

TEST(test_2, a_InicioJogo){
    vector<int> pontos;
    vector<bool> estados;
    pontos.push_back(1); pontos.push_back(2); pontos.push_back(3);
    pontos.push_back(4); pontos.push_back(5); pontos.push_back(6); pontos.push_back(7);
    estados.push_back(true); estados.push_back(false); estados.push_back(false);
    estados.push_back(false); estados.push_back(false); estados.push_back(true); estados.push_back(false);
    Jogo jogo1(2, pontos, estados);
    EXPECT_EQ(1, jogo1.getJogo().getRoot().getPontuacao());
}

TEST(test_2, b_EscreveJogo){
    vector<int> pontos;
    vector<bool> estados;
    pontos.push_back(1); pontos.push_back(2); pontos.push_back(3);
    pontos.push_back(4); pontos.push_back(5); pontos.push_back(6);
    pontos.push_back(7); pontos.push_back(8); pontos.push_back(9);
    pontos.push_back(10); pontos.push_back(11); pontos.push_back(12);
    pontos.push_back(13); pontos.push_back(14); pontos.push_back(15);
    estados.push_back(true); estados.push_back(false); estados.push_back(false);
    estados.push_back(false); estados.push_back(false); estados.push_back(true);
    estados.push_back(false); estados.push_back(true); estados.push_back(true);
    estados.push_back(true); estados.push_back(true); estados.push_back(true);
    estados.push_back(true); estados.push_back(true); estados.push_back(true);
    Jogo jogo1(3, pontos, estados);
    string jogoStr="1-true-0\n2-false-0\n3-false-0\n4-false-0\n5-false-0\n6-true-0\n7-false-0\n8-true-0\n9-true-0\n10-true-0\n11-true-0\n12-true-0\n13-true-0\n14-true-0\n15-true-0\n";
    EXPECT_EQ(jogoStr, jogo1.escreveJogo());
}

TEST(test_2, c_FazJogada){
    vector<int> pontos;
    vector<bool> estados;
    pontos.push_back(1); pontos.push_back(2); pontos.push_back(3);
    pontos.push_back(4); pontos.push_back(5); pontos.push_back(6);
    pontos.push_back(7); pontos.push_back(8); pontos.push_back(9);
    pontos.push_back(10); pontos.push_back(11); pontos.push_back(12);
    pontos.push_back(13); pontos.push_back(14); pontos.push_back(15);
    estados.push_back(true); estados.push_back(false); estados.push_back(false);
    estados.push_back(false); estados.push_back(false); estados.push_back(true);
    estados.push_back(false); estados.push_back(true); estados.push_back(true);
    estados.push_back(true); estados.push_back(true); estados.push_back(true);
    estados.push_back(true); estados.push_back(true); estados.push_back(true);
    Jogo jogo1(3, pontos, estados);
    EXPECT_EQ(13, jogo1.jogada());
    EXPECT_EQ(8,jogo1.jogada());
}

TEST(test_2, d_MaisVisitado){
    vector<int> pontos;
    vector<bool> estados;
    pontos.push_back(1); pontos.push_back(2); pontos.push_back(3);
    pontos.push_back(4); pontos.push_back(5); pontos.push_back(6);
    pontos.push_back(7); pontos.push_back(8); pontos.push_back(9);
    pontos.push_back(10); pontos.push_back(11); pontos.push_back(12);
    pontos.push_back(13); pontos.push_back(14); pontos.push_back(15);
    estados.push_back(true); estados.push_back(false); estados.push_back(false);
    estados.push_back(false); estados.push_back(false); estados.push_back(true);
    estados.push_back(false); estados.push_back(true); estados.push_back(true);
    estados.push_back(true); estados.push_back(true); estados.push_back(true);
    estados.push_back(true); estados.push_back(true); estados.push_back(true);
    Jogo jogo1(3, pontos, estados);
    jogo1.jogada(); jogo1.jogada(); jogo1.jogada();
    EXPECT_EQ(2, jogo1.maisVisitado());
    jogo1.jogada(); jogo1.jogada(); jogo1.jogada();jogo1.jogada();
    EXPECT_EQ(4, jogo1.maisVisitado());
}
