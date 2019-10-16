#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "parque.h"
#include <string>

using testing::Eq;

TEST(test, a_Pesquisa){
    ParqueEstacionamento p1(10,20);
    p1.adicionaCliente("Joao Santos");
    p1.adicionaCliente("Pedro Morais");
    p1.adicionaCliente("Rui Silva");
    p1.adicionaCliente("Susana Costa");
    p1.adicionaCliente("Maria Tavares");
    EXPECT_EQ(0, p1.posicaoCliente("Joao Santos"));
    EXPECT_EQ(4, p1.posicaoCliente("Maria Tavares"));
    EXPECT_EQ(1, p1.posicaoCliente("Pedro Morais"));
    EXPECT_EQ(-1, p1.posicaoCliente("Tiago Tavares"));
}

TEST(test, b_UtilizacaoParque){
    /*ParqueEstacionamento p1(10,20);
    p1.adicionaCliente("Joao Santos");
    p1.adicionaCliente("Pedro Morais");
    p1.adicionaCliente("Rui Silva");
    p1.adicionaCliente("Susana Costa");
    p1.adicionaCliente("Maria Tavares");
    p1.entrar("Maria Tavares");
    p1.entrar("Susana Costa");
    p1.sair("Susana Costa");
    p1.sair("Maria Tavares");
    p1.entrar("Maria Tavares");
    p1.sair("Maria Tavares");
    p1.entrar("Rui Silva");
    p1.sair("Rui Silva");
    p1.entrar("Susana Costa");
    p1.entrar("Rui Silva");
    p1.sair("Rui Silva");
    p1.entrar("Rui Silva");
    p1.entrar("Pedro Morais");
    EXPECT_EQ(3, p1.getFrequencia("Rui Silva"));
    EXPECT_EQ(1, p1.getFrequencia("Pedro Morais"));
    EXPECT_EQ(0, p1.getFrequencia("Joao Santos"));
    EXPECT_THROW(p1.getFrequencia("Tiago Silva"), ClienteNaoExistente);
    try {
        p1.getFrequencia("Tiago Silva");
    }
    catch (ClienteNaoExistente &e) {
        cout << "Apanhou excecao. Cliente nao existente: " << e.getNome() << endl;
        EXPECT_EQ("Tiago Silva", e.getNome());
    }*/
}

TEST(test, c_OrdenaFrequencia){
    ParqueEstacionamento p1(10,20);
    p1.adicionaCliente("Joao Santos");
    p1.adicionaCliente("Pedro Morais");
    p1.adicionaCliente("Rui Silva");
    p1.adicionaCliente("Susana Costa");
    p1.adicionaCliente("Maria Tavares");
    p1.entrar("Maria Tavares");
    p1.entrar("Susana Costa");
    p1.sair("Susana Costa");
    p1.sair("Maria Tavares");
    p1.entrar("Maria Tavares");
    p1.sair("Maria Tavares");
    p1.entrar("Rui Silva");
    p1.sair("Rui Silva");
    p1.entrar("Susana Costa");
    p1.entrar("Rui Silva");
    p1.sair("Rui Silva");
    p1.entrar("Rui Silva");
    p1.entrar("Pedro Morais");

    p1.ordenaClientesPorFrequencia();
    InfoCartao ic1=p1.getClientes()[2];
    EXPECT_EQ("Susana Costa", ic1.nome);
    EXPECT_EQ(2, ic1.frequencia);
    InfoCartao ic2=p1.getClientes()[0];
    EXPECT_EQ("Rui Silva", ic2.nome);
    EXPECT_EQ(3, ic2.frequencia);
}

TEST(test, d_GamasUso){
    ParqueEstacionamento p1(10,20);
    p1.adicionaCliente("Joao Santos");
    p1.adicionaCliente("Pedro Morais");
    p1.adicionaCliente("Rui Silva");
    p1.adicionaCliente("Susana Costa");
    p1.adicionaCliente("Maria Tavares");
    p1.entrar("Maria Tavares");
    p1.entrar("Susana Costa");
    p1.sair("Susana Costa");
    p1.sair("Maria Tavares");
    p1.entrar("Maria Tavares");
    p1.sair("Maria Tavares");
    p1.entrar("Rui Silva");
    p1.sair("Rui Silva");
    p1.entrar("Susana Costa");
    p1.entrar("Rui Silva");
    p1.sair("Rui Silva");
    p1.entrar("Rui Silva");
    p1.entrar("Pedro Morais");
    vector<string> clientes = p1.clientesGamaUso(2,3);
    EXPECT_EQ(3,clientes.size());
    if (clientes.size()==3) {
        EXPECT_EQ("Rui Silva", clientes[0]);
        EXPECT_EQ("Maria Tavares", clientes[1]);
        EXPECT_EQ("Susana Costa", clientes[2]);
    }
}

TEST(test, e_OrdenaNome){
    ParqueEstacionamento p1(10,20);
    p1.adicionaCliente("Joao Santos");
    p1.adicionaCliente("Pedro Morais");
    p1.adicionaCliente("Rui Silva");
    p1.adicionaCliente("Susana Costa");
    p1.adicionaCliente("Maria Tavares");
    p1.entrar("Maria Tavares");
    p1.entrar("Susana Costa");
    p1.sair("Susana Costa");
    p1.sair("Maria Tavares");
    p1.entrar("Maria Tavares");
    p1.sair("Maria Tavares");
    p1.entrar("Rui Silva");
    p1.sair("Rui Silva");
    p1.entrar("Susana Costa");
    p1.entrar("Rui Silva");
    p1.sair("Rui Silva");
    p1.entrar("Rui Silva");
    p1.entrar("Pedro Morais");
    p1.ordenaClientesPorNome();
    InfoCartao ic1=p1.getClientes()[2];
    EXPECT_EQ("Pedro Morais", ic1.nome);
    InfoCartao ic2=p1.getClientes()[0];
    EXPECT_EQ("Joao Santos", ic2.nome);
}

TEST(test, f_InfoClientes){
   /* ParqueEstacionamento p1(10,20);
    p1.adicionaCliente("Joao Santos");
    p1.adicionaCliente("Pedro Morais");
    p1.adicionaCliente("Rui Silva");
    p1.adicionaCliente("Susana Costa");
    p1.adicionaCliente("Maria Tavares");
    p1.entrar("Maria Tavares");
    p1.entrar("Susana Costa");
    p1.sair("Susana Costa");
    p1.entrar("Rui Silva");
    p1.entrar("Susana Costa");
    cout << "Este teste nunca falha! VERIFICAR informa��o escrita no monitor" << endl;
    cout << p1;
    InfoCartao ic=p1.getClienteAtPos(2);
    EXPECT_EQ("Rui Silva", ic.nome);
    EXPECT_THROW(p1.getClienteAtPos(6), PosicaoNaoExistente);
    try {
        p1.getClienteAtPos(6);
    }
    catch (PosicaoNaoExistente &e) {
        cout << "Este teste nunca falha. Verifique no monitor a informacao" << endl;
        cout << "Apanhou excecao. Posicao nao existente:" << e.getValor() << endl;
        EXPECT_EQ(6, e.getValor());
    }*/
}
