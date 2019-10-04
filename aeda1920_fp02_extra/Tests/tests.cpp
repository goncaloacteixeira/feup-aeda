#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "zoo.h"
#include <string>
#include <fstream>

using testing::Eq;


TEST(test, a_criarAnimais){
   /* Animal *a1=new Cao("kurika",10,"estrela");  //nome, idade, ra�a
    Animal *a2=new Morcego("bobo",2,70,2);  //nome, idade, velocidade_maxima, altura_maxima
    Animal *a3=new Cao("bobby",3,"rafeiro");
    Animal *a4=new Cao("fly",7,"dalmata");
    Animal *a5=new Morcego("timao",7,80,4);
    ASSERT_EQ("kurika", a1->getNome());
    ASSERT_EQ("bobo", a2->getNome());
    ASSERT_EQ("bobby", a3->getNome());
    ASSERT_EQ("fly", a4->getNome());
    ASSERT_EQ("timao", a5->getNome());
    ASSERT_EQ(true, a3->eJovem());
    ASSERT_EQ(false, a4->eJovem());
    ASSERT_EQ(true, a2->eJovem());
    ASSERT_EQ(false, a5->eJovem());
    ASSERT_EQ(2, Animal::getMaisJovem());*/
}

TEST(test, b_adicionarAnimais){
    /*Zoo z1;

    Animal *a1=new Cao("kurika",10,"estrela");  //nome, idade, ra�a
    Animal *a2=new Morcego("bobo",2,70,2);  //nome, idade, velocidade_maxima, altura_maxima
    Animal *a3=new Cao("bobby",3,"rafeiro");
    Animal *a4=new Cao("fly",7,"dalmata");
    Animal *a5=new Morcego("timao",7,80,4);

    z1.adicionaAnimal(a1);
    z1.adicionaAnimal(a2);
    z1.adicionaAnimal(a3);
    z1.adicionaAnimal(a4);
    z1.adicionaAnimal(a5);

    ASSERT_EQ(5, z1.numAnimais());*/
}

TEST(test, c_imprimirAnimais){
    /*Zoo z1;

    Animal *a1=new Cao("kurika",10,"estrela");  //nome, idade, ra�a
    ASSERT_EQ("kurika, 10, estrela", a1->getInformacao());

    Animal *a2=new Morcego("bobo",2,70,2);  //nome, idade, velocidade_maxima, altura_maxima
    ASSERT_EQ("bobo, 2, 70, 2", a2->getInformacao());

    z1.adicionaAnimal(a1);
    z1.adicionaAnimal(a2);

    cout << z1.getInformacao();*/
}

TEST(test, d_verificarAnimalJovem){
   /* Zoo z1;

    Animal *a1=new Cao("kurika",10,"estrela");  //nome, idade, ra�a
    Animal *a2=new Morcego("bobo",2,70,2);  //nome, idade, velocidade_maxima, altura_maxima

    z1.adicionaAnimal(a1);
    z1.adicionaAnimal(a2);

    ASSERT_EQ(false, z1.animalJovem("kurika"));
    ASSERT_EQ(true, z1.animalJovem("bobo"));*/
}

TEST(test, e_alocarVeterinarios){
  /*  Zoo z1;

    Animal *a1=new Cao("kurika",10,"estrela");  //nome, idade, ra�a
    Animal *a2=new Morcego("bobo",2,70,2);  //nome, idade, velocidade_maxima, altura_maxima
    Animal *a3=new Cao("bobby",3,"rafeiro");
    Animal *a4=new Cao("fly",7,"dalmata");
    Animal *a5=new Morcego("timao",7,80,4);

    z1.adicionaAnimal(a1);
    z1.adicionaAnimal(a2);
    z1.adicionaAnimal(a3);
    z1.adicionaAnimal(a4);
    z1.adicionaAnimal(a5);

    //TODO trocar o caminho do ficheiro para o caminho correcto; caminho relativo n�o funciona!
    ifstream fVet("vets.txt");
    if (!fVet) cerr << "Ficheiro de veterinarios inexistente!\n";
    else z1.alocaVeterinarios(fVet);
    fVet.close();

    ASSERT_EQ(5, z1.numAnimais());
    ASSERT_EQ(3, z1.numVeterinarios());
    ASSERT_EQ("kurika, 10, Rui Silva, 1234, estrela", a1->getInformacao());*/
}

TEST(test, f_removerVeterinario){
    /*Zoo z1;

    Animal *a1=new Cao("kurika",10,"estrela");  //nome, idade, ra�a
    Animal *a2=new Morcego("bobo",2,70,2);  //nome, idade, velocidade_maxima, altura_maxima
    Animal *a3=new Cao("bobby",3,"rafeiro");
    Animal *a4=new Cao("fly",7,"dalmata");
    Animal *a5=new Morcego("timao",7,80,4);

    z1.adicionaAnimal(a1);
    z1.adicionaAnimal(a2);
    z1.adicionaAnimal(a3);
    z1.adicionaAnimal(a4);
    z1.adicionaAnimal(a5);

    //TODO trocar o caminho do ficheiro para o caminho correcto; caminho relativo n�o funciona!
    ifstream fVet("vets.txt");
    if (!fVet) cerr << "Ficheiro de veterinarios inexistente!\n";
    else z1.alocaVeterinarios(fVet);
    fVet.close();

    ASSERT_EQ(5, z1.numAnimais());
    ASSERT_EQ(3, z1.numVeterinarios());
    ASSERT_EQ("kurika, 10, Rui Silva, 1234, estrela", a1->getInformacao());

    z1.removeVeterinario("Rui Silva");

    ASSERT_EQ("kurika, 10, Artur Costa, 3542, estrela", a1->getInformacao());*/
}

TEST(test, h_compararZoos){
   /* Zoo z1;

    Animal *a1=new Cao("kurika",10,"estrela");  //nome, idade, ra�a
    Animal *a2=new Morcego("bobo",2,70,2);  //nome, idade, velocidade_maxima, altura_maxima
    Animal *a3=new Cao("bobby",3,"rafeiro");
    Animal *a4=new Cao("fly",7,"dalmata");
    Animal *a5=new Morcego("timao",7,80,4);

    z1.adicionaAnimal(a1);
    z1.adicionaAnimal(a2);
    z1.adicionaAnimal(a3);
    z1.adicionaAnimal(a4);
    z1.adicionaAnimal(a5);

    Zoo z2;

    Animal *b1=new Cao("kurika",10,"estrela");  //nome, idade, ra�a
    Animal *b2=new Morcego("bobo",2,70,2);  //nome, idade, velocidade_maxima, altura_maxima
    Animal *b3=new Cao("bobby",3,"rafeiro");
    Animal *b4=new Cao("fly",7,"dalmata");

    z2.adicionaAnimal(b1);
    z2.adicionaAnimal(b2);
    z2.adicionaAnimal(b3);
    z2.adicionaAnimal(b4);

    ASSERT_EQ(true, z2 < z1);*/
}