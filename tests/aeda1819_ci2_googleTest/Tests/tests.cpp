#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
#include <time.h>
#include "Kart.h"
#include "CStack.h"
#include "CSimpleList.h"

using testing::Eq;
using namespace std;

TEST(test_1, test_a){
    CGrupo grupo1;
    grupo1.criaGrupo();
    vector<CKart> kartsOrdenados = grupo1.ordenaKarts();
    EXPECT_EQ(kartsOrdenados.size(), 2500);
    if (kartsOrdenados.size()>0)
        for (unsigned int i=0;i<kartsOrdenados.size()-1;i++)
            EXPECT_LE(kartsOrdenados[i].getNumero(), kartsOrdenados[i + 1].getNumero());
}

TEST(test_1, test_b){
    CGrupo grupo1;
    grupo1.criaGrupo();
    EXPECT_EQ(grupo1.numAvariados(134), 210);
    EXPECT_EQ(grupo1.numAvariados(250), 219);
    EXPECT_EQ(grupo1.numAvariados(450), 212);
    EXPECT_EQ(grupo1.numAvariados(600), 206);
}


TEST(test_1, test_c){
    CGrupo grupo1;
    grupo1.criaGrupo();
	vector <CPista> vecP = grupo1.getPistas();

	vecP[0].prepararCorrida(10, 134);

	queue<CKart> q1= vecP[0].getKartsLinhaPartida();
	EXPECT_EQ(false, q1.empty());
	if (!q1.empty()) {
        EXPECT_EQ(13, q1.front().getNumero());
        q1.pop();
        if (!q1.empty()) {
            EXPECT_EQ(31, q1.front().getNumero());
            q1.pop();
            if (!q1.empty())
                EXPECT_EQ(33, q1.front().getNumero());
        }
    }
}


TEST(test_1, test_d){
    CGrupo grupo1;
    grupo1.criaGrupo();
	vector <CPista> vecP = grupo1.getPistas();
	vecP[0].prepararCorrida(10, 134);

	EXPECT_EQ(7,vecP[0].inicioCorrida());

	vector<CKart> v1= vecP[0].getKartsEmProva();
	EXPECT_EQ(false, v1.empty());
	if (v1.size()>=1)
        EXPECT_EQ(13, v1[0].getNumero());
    if (v1.size()>=2)
        EXPECT_EQ(31, v1[1].getNumero());
    if (v1.size()>=3)
        EXPECT_EQ(33, v1[2].getNumero());
}



TEST(test_2, test_a){
	CStack s1(20);
	s1.push(1); s1.push(2); s1.push(3);
	s1.adicionaN(4); //s1.print();
	EXPECT_EQ("7 6 5 4 3 2 1 ",s1.toStr());
	s1.adicionaN(2); //s1.print();
	EXPECT_EQ("9 8 7 6 5 4 3 2 1 ",s1.toStr());
}


TEST(test_2, test_b){
	CStack s2(20);
	s2.push(1); s2.push(2); s2.push(3);
	EXPECT_EQ(false,s2.inverte4());
	s2.push(4); s2.push(5);
	s2.inverte4(); //s2.print();
	EXPECT_EQ("2 3 4 5 1 ",s2.toStr());
	s2.push(6); s2.push(7);
	s2.inverte4(); //s2.print();
	EXPECT_EQ("3 2 6 7 4 5 1 ",s2.toStr());
}

TEST(test_2, test_c){
	CSimpleList l1, l2, l3;
	l1.insert_end(1); l1.insert_end(2); l1.insert_end(3);
	l1.insert_end(4); l1.insert_end(5);
	l2.insert_end(6); l2.insert_end(7); l2.insert_end(8);
	//l1.print(); l2.print();
	l1.intercalar(l2); //l1.print();
	EXPECT_EQ("1 6 2 7 3 8 4 5 ",l1.toStr());
	l1.intercalar(l2); //l1.print();
	EXPECT_EQ("1 6 6 7 2 8 7 3 8 4 5 ",l1.toStr());
}

TEST(test_2, test_d){
	CSimpleList l3;
	int elem[14]  = {1,1,2,2,2,3,3,3,3,4,4,7,8,8};
	for(int i=0; i<14; i++) l3.insert_end(elem[i]);
	l3.print();
	//cout << "Zipados: " << l3.zipar() << endl;
	EXPECT_EQ(8,l3.zipar());
	EXPECT_EQ("1 2 3 4 7 8 ",l3.toStr());
	l3.print();
	CSimpleList l4;
	int elem2[10]  = {1,1,1,2,4,6,6,6,6,7};
	for(int i=0; i<10; i++) l4.insert_end(elem2[i]);
	l4.print();
	//cout << "Zipados: " << l3.zipar() << endl;
	EXPECT_EQ(5,l4.zipar());
	EXPECT_EQ("1 2 4 6 7 ",l4.toStr());
	l4.print();
}
