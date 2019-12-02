#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include <string>

#include "maquinaEmpacotar.h"

using testing::Eq;


TEST(test, a_CarregaObjetos){
    vector<Objeto> objetos;
    objetos.push_back(Objeto(1, 2)); objetos.push_back(Objeto(2, 11));
    objetos.push_back(Objeto(3, 17)); objetos.push_back(Objeto(4, 3));
    objetos.push_back(Objeto(5, 9)); objetos.push_back(Objeto(6, 4));
    objetos.push_back(Objeto(7, 2)); objetos.push_back(Objeto(8, 12));
    objetos.push_back(Objeto(9, 7)); objetos.push_back(Objeto(10, 1));

    for(unsigned i = 0; i < objetos.size(); i++) cout << objetos[i] << endl;

    MaquinaEmpacotar maquina;
    int objsCarregados = maquina.carregaPaletaObjetos(objetos);
    int objsIgnorados  = objetos.size();
    EXPECT_EQ(7, objsCarregados);
    EXPECT_EQ(3, objsIgnorados);
    HEAP_OBJS objetosH= maquina.getObjetos();
    bool isEmp = objetosH.empty();
    EXPECT_EQ(false, isEmp);
    if (isEmp==false)
        EXPECT_EQ(5,objetosH.top().getID());
}


TEST(test, b_ProcuraCaixa){
    vector<Objeto> objetos;
    objetos.push_back(Objeto(1, 2)); objetos.push_back(Objeto(2, 5));
    objetos.push_back(Objeto(3, 8)); objetos.push_back(Objeto(4, 1));
    objetos.push_back(Objeto(5, 4)); objetos.push_back(Objeto(6, 6));
    objetos.push_back(Objeto(7, 1)); objetos.push_back(Objeto(8, 4));

    Caixa::resetID();

    Caixa c1(10); //7
    c1.addObjeto( objetos[0] );
    c1.addObjeto( objetos[1] );
    Caixa c2(10); //8
    c2.addObjeto( objetos[2] );

    MaquinaEmpacotar maquina;
    maquina.addCaixa( c1 );
    maquina.addCaixa( c2 );

    cout << "Carga livre em C" << c1.getID() << ": " << c1.getCargaLivre() << endl; //3
    cout << "Carga livre em C" << c2.getID() << ": " << c2.getCargaLivre() << endl; //2

    EXPECT_EQ(2, maquina.numCaixasUsadas()); // 8 7
    HEAP_CAIXAS caixasH= maquina.getCaixas();
    bool isEmp = caixasH.empty();
    EXPECT_EQ(false, isEmp);
    if (isEmp==false)
        EXPECT_EQ(2,caixasH.top().getCargaLivre());

    Caixa cx = maquina.procuraCaixa( objetos[3] );
    cx.addObjeto( objetos[3] );
    maquina.addCaixa( cx );
    //cout << "Carga livre em C" << cx.getID() << ": " << cx.getCargaLivre() << endl;
    EXPECT_EQ(2, maquina.numCaixasUsadas()); // 9 7
    caixasH= maquina.getCaixas();
    isEmp = caixasH.empty();
    EXPECT_EQ(false, isEmp);
    if (isEmp==false)
        EXPECT_EQ(1,caixasH.top().getCargaLivre());

    cx = maquina.procuraCaixa( objetos[4] );
    cx.addObjeto( objetos[4] );
    maquina.addCaixa( cx );
    cout << "Carga livre em C" << cx.getID() << ": " << cx.getCargaLivre() << endl;
    EXPECT_EQ(3, maquina.numCaixasUsadas()); // 9 7 4
    caixasH= maquina.getCaixas();
    isEmp = caixasH.empty();
    EXPECT_EQ(false, isEmp);
    if (isEmp==false)
        EXPECT_EQ(1,caixasH.top().getCargaLivre());

    cx = maquina.procuraCaixa( objetos[5] );
    cx.addObjeto( objetos[5] );
    maquina.addCaixa( cx );
    cout << "Carga livre em C" << cx.getID() << ": " << cx.getCargaLivre() << endl;
    EXPECT_EQ(3, maquina.numCaixasUsadas()); // 10 9 7
    caixasH= maquina.getCaixas();
    isEmp = caixasH.empty();
    EXPECT_EQ(false, isEmp);
    if (isEmp==false)
        EXPECT_EQ(0,caixasH.top().getCargaLivre());

    cx = maquina.procuraCaixa( objetos[6] );
    cx.addObjeto( objetos[6] );
    maquina.addCaixa( cx );
    cout << "Carga livre em C" << cx.getID() << ": " << cx.getCargaLivre() << endl;
    EXPECT_EQ(3, maquina.numCaixasUsadas()); // 10 10 7
    caixasH = maquina.getCaixas();
    EXPECT_EQ(3,caixasH.size());
    if (caixasH.size()==3) {
        caixasH.pop();
        EXPECT_EQ(0, caixasH.top().getCargaLivre());
    }

    cx = maquina.procuraCaixa( objetos[7] );
    cx.addObjeto( objetos[7] );
    maquina.addCaixa( cx );
    cout << "Carga livre em C" << cx.getID() << ": " << cx.getCargaLivre() << endl;
    EXPECT_EQ(4, maquina.numCaixasUsadas()); // 10 10 7 6
    caixasH = maquina.getCaixas();
    EXPECT_EQ(4,caixasH.size());
    if (caixasH.size()==4) {
        caixasH.pop();
        caixasH.pop();
        EXPECT_EQ(3, caixasH.top().getCargaLivre());
    }
}


TEST(test, c_EmpacotaObjetos){
    vector<Objeto> objetos;
    objetos.push_back(Objeto(1, 2)); objetos.push_back(Objeto(2, 11));
    objetos.push_back(Objeto(3, 17)); objetos.push_back(Objeto(4, 3));
    objetos.push_back(Objeto(5, 9)); objetos.push_back(Objeto(6, 4));
    objetos.push_back(Objeto(7, 2)); objetos.push_back(Objeto(8, 12));
    objetos.push_back(Objeto(9, 7)); objetos.push_back(Objeto(10, 10));
    objetos.push_back(Objeto(11, 10)); objetos.push_back(Objeto(12, 1));

    Caixa::resetID();

    MaquinaEmpacotar maquina;

    EXPECT_EQ(9, maquina.carregaPaletaObjetos(objetos));
    EXPECT_EQ(3, objetos.size());
    EXPECT_EQ(5, maquina.empacotaObjetos());

    HEAP_CAIXAS caixas = maquina.getCaixas();
    EXPECT_EQ(5, caixas.size());
    if (caixas.size()==5) {
        EXPECT_EQ(0, caixas.top().getCargaLivre());
        caixas.pop();
        EXPECT_EQ(0, caixas.top().getCargaLivre());
        caixas.pop();
        EXPECT_EQ(0, caixas.top().getCargaLivre());
        caixas.pop();
        EXPECT_EQ(0, caixas.top().getCargaLivre());
        caixas.pop();
        EXPECT_EQ(2, caixas.top().getCargaLivre());
    }
}

TEST(test, d_ObjetosPorEmpacotar){
    MaquinaEmpacotar maquina;

    EXPECT_EQ("Nao ha objetos!\n", maquina.imprimeObjetosPorEmpacotar());

    vector<Objeto> objetos;
    objetos.push_back(Objeto(1, 2)); objetos.push_back(Objeto(2, 12));
    objetos.push_back(Objeto(3, 8)); objetos.push_back(Objeto(4, 1));

    EXPECT_EQ(3, maquina.carregaPaletaObjetos(objetos));
    string objsPorEmpacotar = maquina.imprimeObjetosPorEmpacotar();
    cout << objsPorEmpacotar;
    EXPECT_EQ("O3: 8\nO1: 2\nO4: 1\n", maquina.imprimeObjetosPorEmpacotar());

    EXPECT_EQ(2, maquina.empacotaObjetos());

    EXPECT_EQ("Nao ha objetos!\n", maquina.imprimeObjetosPorEmpacotar());
}

TEST(test, e_ConteudoCaixa){
    vector<Objeto> objetos;
    objetos.push_back(Objeto(1, 2)); objetos.push_back(Objeto(2, 5));

    Caixa::resetID();

    Caixa c1(10);
    EXPECT_EQ("Caixa 1 vazia!\n", c1.imprimeConteudo());

    c1.addObjeto( objetos[0] );
    c1.addObjeto( objetos[1] );

    EXPECT_EQ("C1[ O2: 5 O1: 2 ]", c1.imprimeConteudo());
}

TEST(test, f_CaixaMaisObjetos){
    vector<Objeto> objetos;
    objetos.push_back(Objeto(1, 2)); objetos.push_back(Objeto(2, 11));
    objetos.push_back(Objeto(3, 17)); objetos.push_back(Objeto(4, 3));
    objetos.push_back(Objeto(5, 9)); objetos.push_back(Objeto(6, 4));
    objetos.push_back(Objeto(7, 2)); objetos.push_back(Objeto(8, 12));
    objetos.push_back(Objeto(9, 7)); objetos.push_back(Objeto(10, 10));
    objetos.push_back(Objeto(11, 10)); objetos.push_back(Objeto(12, 1));

    Caixa cx;
    Caixa::resetID();

    MaquinaEmpacotar maquina;

    EXPECT_THROW(maquina.caixaMaisObjetos(), MaquinaEmpacotar::MaquinaSemCaixas);
    try {
        cx = maquina.caixaMaisObjetos();
    }
    catch(MaquinaEmpacotar::MaquinaSemCaixas &msc) {
        cout << "Este teste nunca falha! VERIFICAR informacao escrita no monitor" << endl;
        EXPECT_TRUE(true);

    }

    EXPECT_EQ(9, maquina.carregaPaletaObjetos(objetos));
    EXPECT_EQ(3, objetos.size());
    EXPECT_EQ(5, maquina.empacotaObjetos());

    cx = maquina.caixaMaisObjetos();
    EXPECT_EQ(5, cx.getID());
    EXPECT_EQ("C5[ O1: 2 O7: 2 O6: 4 ]", cx.imprimeConteudo());
}

