#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "stackExt.h"
#include "balcao.h"
#include "exceptions.h"
#include <iostream>
#include <stack>
#include <queue>
#include <cstdlib>
#include "performance.h"


using testing::Eq;


TEST(test_1, StackExt_FindMin){
    StackExt<int> s1;
    // Teste ao empty()
    EXPECT_EQ(true, s1.empty());
    // Teste ao push() e top()
    s1.push(6);
    s1.push(4);
    s1.push(7);
    s1.push(2);
    s1.push(5);
    EXPECT_EQ(5, s1.top());
    // Teste ao pop() e top()
    s1.pop();
    s1.pop();
    EXPECT_EQ(7, s1.top());

    // Testar findMin()
    EXPECT_EQ(4, s1.findMin());
    s1.push(3);
    s1.push(2);
    EXPECT_EQ(2, s1.findMin());

    // Agora testar findMin() para saber se executa em tempo constante
    // preparar Stack removendo todos os elementos
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    EXPECT_EQ(true, s1.empty());

    // preparar dados para teste TEMPO EXECUCAO
    int size = 9;
    unsigned int elapsedTime[size];
    int x_el[] = {5000000,6000000,7000000,8000000,9000000,10000000,11000000,12000000,13000000};
    int random_int;
    ticks tstart;
    ticks tend;

    for (int i = 0; i < size; i++) {
        // encher stack com numero de elementos indicados pelo x_el
        for (int z = 1; z <= x_el[i]; z++) {
            random_int = rand() % 1000 + 1;
            s1.push(random_int);
        }
        // agora contar tempo invocando o metodo
        tstart = getticks(); // inicio contagem ticks
        s1.findMin(); // este ee constante
        tend = getticks(); // fim da contagem ticks
        // colocar valor no array de elapsedTime
        elapsedTime[i] = getElapsed(tend,tstart);
        // retirar da stack os numeros la colocados
        for (int z = 1; z <= x_el[i]; z++) {
            s1.pop();
        }
    }
    // Verifica se executa em TEMPO CONSTANTE
    // NOTA: o parametro com valor 10 significa que sao considerados constantes valores no intervalo [-10, 10]
    EXPECT_EQ(true, isConstant(elapsedTime, size, 10));
}

TEST(test_2, a_ConstructorCliente){
    srand(time(NULL));
    Cliente c;
    EXPECT_TRUE((c.getNumPresentes()>0 && c.getNumPresentes()<=5));
}

TEST(test_2, b_ConstructorBalcao){
    srand(time(NULL));
    Balcao b;
    EXPECT_EQ(0, b.getClientesAtendidos());
    EXPECT_EQ(2, b.getTempoEmbrulho());
    EXPECT_EQ(0, b.getTempoAtual());
    EXPECT_TRUE((b.getProxChegada()>0 && b.getProxChegada() <= 20));
    EXPECT_EQ(0, b.getProxSaida());
    EXPECT_THROW(b.getProxCliente(), FilaVazia);
    try {
        b.getProxCliente();
    }
    catch (FilaVazia &e) {
        cout << "Apanhou excecao. FilaVazia: " << e.getMsg() << endl;
        EXPECT_EQ("Fila Vazia", e.getMsg());
    }
}

TEST(test_2, c_ChegadaBalcao){
    Balcao b;
    cout << "Este teste nao falha. Verifique se na consola aparece (x varia entre 1 e 5): tempo= 0\nchegou novo cliente com x presentes" << endl;

    b.chegada();
    // Agora que se invocou o metodo chegada, verifica se fez corretamente alguns dos requisitos
    EXPECT_EQ(0, b.getTempoAtual());
    EXPECT_TRUE((b.getProxCliente().getNumPresentes()>0 && b.getProxCliente().getNumPresentes()<=5));
    EXPECT_TRUE((b.getProxChegada()>0 && b.getProxChegada() <= 20));
    EXPECT_TRUE((b.getProxSaida()>=2 && b.getProxSaida() <= 10)); // entre [0+1*2, 0+5*2]
}

TEST(test_2, d_SaidaBalcao){
    Balcao b;
    // Simula a chegada de um cliente
    b.chegada();
    b.chegada();

    b.saida();
    // Agora que se invocou o metodo saida, verifica se fez corretamente alguns dos requisitos
    EXPECT_EQ(0, b.getTempoAtual());
    EXPECT_TRUE((b.getProxSaida()>=2 && b.getProxSaida() <= 10)); // entre [0+1*2, 0+5*2]
    b.saida();
    try {
        b.getProxCliente();
    }
    catch (FilaVazia &e) {
        cout << "Apanhou excecao. FilaVazia: " << e.getMsg() << endl;
        EXPECT_EQ("Fila Vazia", e.getMsg());
    }
}

TEST(test_2, e_ProximoEvento){
    cout << "Este teste nao falha. Verifique na consola os valores." << endl;
    EXPECT_TRUE(true);
    Balcao b;
    b.proximoEvento();
    cout << "01: " << "Clientes atendidos: " << b.getClientesAtendidos() << " Tempo actual: " << b.getTempoAtual() << " Prox chegada: " << b.getProxChegada() << " Prox Saida: " << b.getProxSaida() << endl;
    b.proximoEvento();
    cout << "02: " << "Clientes atendidos: " << b.getClientesAtendidos() << " Tempo actual: " << b.getTempoAtual() << " Prox chegada: " << b.getProxChegada() << " Prox Saida: " << b.getProxSaida() << endl;
    b.proximoEvento();
    cout << "03: " << "Clientes atendidos: " << b.getClientesAtendidos() << " Tempo actual: " << b.getTempoAtual() << " Prox chegada: " << b.getProxChegada() << " Prox Saida: " << b.getProxSaida() << endl;
    b.proximoEvento();
    cout << "04: " << "Clientes atendidos: " << b.getClientesAtendidos() << " Tempo actual: " << b.getTempoAtual() << " Prox chegada: " << b.getProxChegada() << " Prox Saida: " << b.getProxSaida() << endl;
}

TEST(test_2, f_Operador){
    cout << "Este teste nao falha. Verifique na consola os valores." << endl;
    EXPECT_TRUE(true);
    Balcao b;
    b.proximoEvento();
    b.proximoEvento();
    b.proximoEvento();
    b.proximoEvento();
    cout << b << endl;
}