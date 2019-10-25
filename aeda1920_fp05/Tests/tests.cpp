#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Crianca.h"
#include "Jogo.h"
#include <vector>
#include <string>


using testing::Eq;


TEST(test, a_insereCrianca){
    Crianca c1("Rui",6);
    Crianca c2("Ana",4);
    Crianca c3("Rita",6);
    Crianca c4("Joao",5);
    Crianca c5("Marta",4);
    Crianca c6("Vasco",5);

    Jogo jogo1;
    list<Crianca> cc = jogo1.getCriancasJogo();
    EXPECT_EQ(0, cc.size());

    jogo1.insereCrianca(c1);
    jogo1.insereCrianca(c2);
    jogo1.insereCrianca(c3);
    jogo1.insereCrianca(c4);
    jogo1.insereCrianca(c5);
    jogo1.insereCrianca(c6);

    cc = jogo1.getCriancasJogo();
    EXPECT_EQ(6, cc.size());

    if (cc.size() == 6) {
        Crianca c = cc.front();
        EXPECT_EQ("Rui", c.getNome());
        c = cc.back();
        EXPECT_EQ("Vasco", c.getNome());
    }

    Jogo jogo2;
    cc.clear();
    cc.push_back(c1); cc.push_back(c2);
    cc.push_back(c3); cc.push_back(c4);
    jogo2.setCriancasJogo(cc);

    cc = jogo2.getCriancasJogo();
    EXPECT_EQ(4, cc.size());

    if (cc.size()==4) {
        Crianca c = cc.front();
        EXPECT_EQ("Rui", c.getNome());
        c = cc.back();
        EXPECT_EQ("Joao", c.getNome());
    }
}

TEST(test, b_imprimeJogo){
    Jogo jogo1;
    EXPECT_EQ("", jogo1.escreve());

    Crianca c1("Rui",6);
    Crianca c2("Ana",4);
    Crianca c3("Vasco",5);
    jogo1.insereCrianca(c1);
    jogo1.insereCrianca(c2);
    jogo1.insereCrianca(c3);
    cout << jogo1.escreve();
    EXPECT_EQ("Rui : 6\nAna : 4\nVasco : 5\n", jogo1.escreve());
}

TEST(test, c_perdeJogo){
    Crianca c1("Rui",6);
    Crianca c2("Ana",4);
    Crianca c3("Rita",6);
    Crianca c4("Joao",5);
    Crianca c5("Marta",4);
    Crianca c6("Vasco",5);

    Jogo jogo1;
    jogo1.insereCrianca(c1);
    jogo1.insereCrianca(c2);
    jogo1.insereCrianca(c3);
    jogo1.insereCrianca(c4);
    jogo1.insereCrianca(c5);
    jogo1.insereCrianca(c6);

    string s = "Pim Pam Pum cada bola mata um pra galinha e pro peru quem se livra es mesmo tu";
    Crianca cx = jogo1.perdeJogo(s);
    EXPECT_EQ("Rui", cx.getNome());

    Jogo jogo2;
    s = "Pim Pam Pum";
    jogo2.insereCrianca(c1);
    jogo2.insereCrianca(c2);
    jogo2.insereCrianca(c3);
    cx = jogo2.perdeJogo(s);
    EXPECT_EQ("Ana", cx.getNome());
}

TEST(test, d_inverteJogo){
    Crianca c1("Rui",6);
    Crianca c2("Vasco",5);
    Crianca c3("Ana",4);
    Crianca c4("Joao",5);
    Crianca c5("Marta",4);
    Crianca c6("Rita",6);

    Jogo jogo1;
    jogo1.insereCrianca(c1);
    jogo1.insereCrianca(c2);
    jogo1.insereCrianca(c3);
    jogo1.insereCrianca(c4);
    jogo1.insereCrianca(c5);
    jogo1.insereCrianca(c6);

    EXPECT_EQ("Rui", jogo1.getCriancasJogo().front().getNome());
    EXPECT_EQ("Rita", jogo1.getCriancasJogo().back().getNome());

    list<Crianca> invertida = jogo1.inverte();
    EXPECT_EQ("Rita", invertida.front().getNome());
    EXPECT_EQ("Rui", invertida.back().getNome());
}

TEST(test, e_divideJogo){
    Crianca c1("Rui",6);
    Crianca c2("Ana",4);
    Crianca c3("Rita",3);
    Crianca c4("Joao",5);
    Crianca c5("Marta",7);
    Crianca c6("Vasco",5);
    Jogo jogo1;
    jogo1.insereCrianca(c1);
    jogo1.insereCrianca(c2);
    jogo1.insereCrianca(c3);
    jogo1.insereCrianca(c4);
    jogo1.insereCrianca(c5);
    jogo1.insereCrianca(c6);

    list<Crianca> dividida = jogo1.divide(5);
    Jogo jogo2(dividida);
    EXPECT_EQ("Rui : 6\nMarta : 7\n", jogo2.escreve());
}

TEST(test, f_igualdadeJogo){
    list<Crianca> criancas1;
    criancas1.push_back( Crianca("Rui",6) );
    criancas1.push_back( Crianca("Ana",4) );
    criancas1.push_back( Crianca("Rita",3) );
    criancas1.push_back( Crianca("Joao",5) );
    criancas1.push_back( Crianca("Marta",7) );
    criancas1.push_back( Crianca("Vasco",5) );
    criancas1.push_back( Crianca("Ines",5) );

    Jogo jogo1(criancas1);
    Jogo jogo2(criancas1);
    EXPECT_EQ(true, jogo1 == jogo2);

    list<Crianca> criancas2;
    criancas2.push_back( Crianca("Rui",6) );
    criancas2.push_back( Crianca("Ana",4) );
    criancas2.push_back( Crianca("Rita",3) );
    criancas2.push_back( Crianca("Maria",5) );
    criancas2.push_back( Crianca("Marta",7) );
    criancas2.push_back( Crianca("Vasco",5) );
    criancas2.push_back( Crianca("Ines",5) );

    jogo2.setCriancasJogo(criancas2);
    EXPECT_EQ(false, jogo1 == jogo2);
}

TEST(test, g_baralhaCriancas){
    list<Crianca> criancas;
    criancas.push_back( Crianca("Rui",6) );
    criancas.push_back( Crianca("Ana",4) );
    criancas.push_back( Crianca("Rita",3) );
    criancas.push_back( Crianca("Joao",5) );
    criancas.push_back( Crianca("Marta",7) );
    criancas.push_back( Crianca("Vasco",5) );
    criancas.push_back( Crianca("Ines",5) );

    Jogo jogo1;
    jogo1.setCriancasJogo(criancas);

    list<Crianca> criancas2 = jogo1.baralha();
    EXPECT_EQ(7, criancas2.size());

    list<Crianca>::iterator it;
    it= find(criancas2.begin(), criancas2.end(),Crianca("Rui",6));
    EXPECT_EQ("Rui", it->getNome());

    it= find(criancas2.begin(), criancas2.end(),Crianca("Ines",5));
    EXPECT_EQ("Ines", it->getNome());

    Jogo jogo2(criancas2);
    EXPECT_EQ(false, jogo1 == jogo2);
}