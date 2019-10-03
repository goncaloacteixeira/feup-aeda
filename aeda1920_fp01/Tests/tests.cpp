#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "parque.h"
#include <string>


using testing::Eq;


TEST(test_1, a_AbrirParque){
    ParqueEstacionamento p1(4, 6);
    // Testa se o parque foi aberto com a lota��o indicada
    ASSERT_EQ(4, p1.getNumLugares());
    // Testa se o parque foi aberto com o n�mero m�ximo de clientes indicado
    ASSERT_EQ(6, p1.getNumMaximoClientes());
}

TEST(test_1, b_AdicionarCliente){
    ParqueEstacionamento p1(3, 5);
    // Testa se deixa adicionar um novo cliente
    ASSERT_EQ(true, p1.adicionaCliente("Joao"));
    p1.adicionaCliente("Antonio");
    p1.adicionaCliente("Rui");
    p1.adicionaCliente("Maria");
    p1.adicionaCliente("Clara");
    // Testa se recusa novo cliente quando numero m�ximo de clientes foi atingido
    ASSERT_EQ(false, p1.adicionaCliente("Paula"));
    // Testa se retorna a posi��o correcta do cliente
    ASSERT_EQ(1, p1.posicaoCliente("Antonio"));
    // Testa se retorna -1 caso o cliente n�o exista
    ASSERT_EQ(-1, p1.posicaoCliente("Joana"));
}


TEST(test_1, c_EntrarParque){
    ParqueEstacionamento p1(3, 5);
    p1.adicionaCliente("Joao");
    p1.adicionaCliente("Maria");
    p1.adicionaCliente("Antonio");
    p1.adicionaCliente("Rui");
    // Testa se deixa entrar no parque um cliente existente
    ASSERT_EQ(true, p1.entrar("Maria"));
    // Testa se n�o deixa entrar no parque um cliente que n�o existe
    ASSERT_EQ(false, p1.entrar("Paula"));
    // Testa se n�o dexia entrar em cliente que j� l� est�
    ASSERT_EQ(false, p1.entrar("Maria"));
    p1.entrar("Joao");
    p1.entrar("Antonio");
    // Testa se n�o deixa entrar quando a lota��o est� completa
    ASSERT_EQ(false, p1.entrar("Rui"));
}


TEST(test_1, d_RetirarCliente){
    ParqueEstacionamento p1(3, 5);
    p1.adicionaCliente("Joao");
    p1.adicionaCliente("Maria");
    p1.adicionaCliente("Antonio");
    p1.entrar("Maria");
    // Testa se n�o deixa remover cliente que est� dentro do parque
    ASSERT_EQ(false, p1.retiraCliente("Maria"));
    // Testa se deixa remover cliente que est� fora do parque
    ASSERT_EQ(true, p1.retiraCliente("Antonio"));
    // Testa se nao deixa remover cliente que nao existe
    ASSERT_EQ(false, p1.retiraCliente("Ana"));
}

TEST(test_1, e_SairParque){
    ParqueEstacionamento p1(3, 5);
    p1.adicionaCliente("Joao");
    p1.adicionaCliente("Maria");
    p1.adicionaCliente("Rui");
    p1.entrar("Maria");
    p1.entrar("Joao");
    p1.entrar("Rui");
    // Testa se um cliente estacionado no parque, sai.
    ASSERT_EQ(true, p1.sair("Maria"));
    // Testa se n�o deixa sair um cliente que n�o est� estacionado.
    ASSERT_EQ(false, p1.sair("Maria"));
    // Testa se n�o deixa sair um cliente que n�o existe.
    ASSERT_EQ(false, p1.sair("Antonio"));
}

TEST(test_1, f_LugaresLotacaoParque){
    ParqueEstacionamento p1(3, 5);
    p1.adicionaCliente("Joao");
    p1.adicionaCliente("Maria");
    p1.adicionaCliente("Antonio");
    p1.entrar("Maria");
    p1.entrar("Antonio");
    // Testa se Lotacao do parque est� correcta
    ASSERT_EQ(3, p1.getNumLugares());
    // Testa se o numero de viaturas presentes no parque est� correcto
    ASSERT_EQ(2, p1.getNumLugaresOcupados());
    // Testa se o o n�mero de clientes registados no parque est� correcto
    ASSERT_EQ(3, p1.getNumClientesAtuais());
}

TEST(test_1, g_operador){
    ParqueEstacionamento p1(5, 5);
    p1.adicionaCliente("Joao");
    p1.adicionaCliente("Maria");
    p1.adicionaCliente("Antonio");

    ParqueEstacionamento p2(5, 5);
    p2.adicionaCliente("Zé");
    p2.adicionaCliente("Luis");
    p1+=p2;
    // Testa se consegue adicionar os 2 clientes do parque 2
    ASSERT_EQ(5,p1.getNumClientesAtuais());

    ParqueEstacionamento p3(5, 5);
    p3.adicionaCliente("André");
    p1+=p3;
    // Testa se consegue adicionar 1 cliente a um parque cheio
    ASSERT_EQ(5,p1.getNumClientesAtuais());
}