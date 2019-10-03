#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "frota.h"
#include <string>



using testing::Eq;

TEST(test_1, a_CriarVeiculos) {
    /*Automovel a1("Fiat",5,2017,"gasolina",1200);
    Camiao c1("Ford",3,2016,"gasolina",1400,1000);
    Automovel a2("Renault",9,2017,"gasoleo",1300);
    Bicicleta b1("XX",4,2018,"TodoTerreno");
    ASSERT_EQ("gasolina", c1.getCombustivel());
    ASSERT_EQ("Fiat", a1.getMarca());
    ASSERT_EQ("Ford", c1.getMarca());*/
}

TEST(test_1, b_CriarFrota){
   /* Frota f;
    ASSERT_EQ(0, f.numVeiculos());
    ASSERT_EQ(0, f.menorAno());
    Veiculo *v1 =new Automovel("Fiat",5,1997,"gasolina",1200);
    Veiculo *v2= new Camiao("Ford",3,1999,"gasolina",1400,1000);
    Veiculo *v3=new Automovel("Renault",9,1997,"gasoleo",1300);
    Veiculo *v4=new Bicicleta("XX",4,2002,"TodoTerreno");
    f.adicionaVeiculo(v1);
    f.adicionaVeiculo(v2);
    f.adicionaVeiculo(v3);
    f.adicionaVeiculo(v4);
    ASSERT_EQ(4, f.numVeiculos());
    ASSERT_EQ(1997, f.menorAno());*/
}

TEST(test_1, c_InfoVeiculo){
   /* Automovel a1("Fiat",5,1997,"gasolina",1200);
    Camiao c1("Ford",3,1999,"gasolina",1400,1000);
    Bicicleta b1("XX",4,2002,"TodoTerreno");
    ASSERT_EQ(5, a1.info());
    ASSERT_EQ(6,c1.info());
    ASSERT_EQ(4,b1.info());*/
}

TEST(test_1, d_InfoFrota){
    /*Veiculo *v1 =new Automovel("Fiat",5,2016,"gasolina",1200);
    Veiculo *v2= new Camiao("Ford",3,2017,"gasolina",1400,1000);
    Veiculo *v3=new Bicicleta("XX",4,2018,"TodoTerreno");
    Frota f;
    f.adicionaVeiculo(v1);
    f.adicionaVeiculo(v2);
    f.adicionaVeiculo(v3);
    ASSERT_TRUE(true);
    cout << "Este teste nunca falha! VERIFICAR informação escrita no monitor" << endl;
    cout << f;*/
}

TEST(test_1, e_OperadorMenor) {
   /* Automovel a1("Fiat",3,2017,"gasolina",1200);
    Camiao c1("Ford",5,2017,"gasolina",1400,1000);
    Bicicleta b1("XX",4,2018,"TodoTerreno");
    ASSERT_EQ(true, a1<c1);
    ASSERT_EQ(false,b1<c1);
    ASSERT_EQ(true,a1<b1);*/
}

TEST(test_1, f_OperadorFuncao) {
   /* Frota f;
    Veiculo *v1 =new Automovel("Fiat",5,2016,"gasolina",1200);
    Veiculo *v2= new Camiao("Ford",3,2017,"gasolina",1400,1000);
    Veiculo *v3=new Automovel("Renault",9,2016,"gasoleo",1300);
    Veiculo *v4=new Automovel("Renault",9,2010,"gasoleo",1300);
    Veiculo *v5=new Bicicleta("XX",4,2018,"TodoTerreno");
    f.adicionaVeiculo(v1);
    f.adicionaVeiculo(v2);
    f.adicionaVeiculo(v3);
    f.adicionaVeiculo(v4);
    f.adicionaVeiculo(v5);
    ASSERT_EQ(5, f.numVeiculos());
    vector<Veiculo*> v;
    v = f(2016);
    ASSERT_EQ(2, v.size());
    v = f(2015);
    ASSERT_EQ(0, v.size());
    v = f(2010);
    ASSERT_EQ(1, v.size());
    ASSERT_EQ("Renault", v[0]->getMarca());*/
}

TEST(test_1, g_ImpostoVeiculo) {
    /*Automovel a1("Fiat",5,1997,"gasolina",1200);
    Camiao c1("Ford",3,1999,"gasolina",1400,1000);
    Bicicleta b1("XX",4,2002,"TodoTerreno");
    ASSERT_NEAR(29.06, a1.calcImposto(),0.001);
    ASSERT_NEAR(45.15,c1.calcImposto(),0.001);
    ASSERT_NEAR(0,b1.calcImposto(),0.001);*/
}

TEST(test_1, h_ImpostoFrota) {
    /*Veiculo *v1 =new Automovel("Fiat",5,1997,"gasolina",1200);
    Veiculo *v2= new Camiao("Ford",3,1999,"gasolina",1400,1000);
    Veiculo *v3=new Bicicleta("XX",4,2002,"TodoTerreno");
    Frota f;
    f.adicionaVeiculo(v1);
    f.adicionaVeiculo(v2);
    f.adicionaVeiculo(v3);
    ASSERT_NEAR(74.21, f.totalImposto(),0.001);*/
}
