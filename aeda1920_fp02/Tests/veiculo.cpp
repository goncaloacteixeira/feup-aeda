#include "veiculo.h"
#include <iostream>

using namespace std;

string MesString(int mes)
{
    switch (mes)
    {
        case 1:
            return "Janeiro";
        case 2:
            return "Fevereiro";
        case 3:
            return "Março";
        case 4:
            return "Abril";
        case 5:
            return "Maio";
        case 6:
            return "Junho";
        case 7:
            return "Julho";
        case 8:
            return "Agosto";
        case 9:
            return "Setembro";
        case 10:
            return "Outubro";
        case 11:
            return "Novembro";
        case 12:
            return "Dezembro";
        default:
            return "mês não identificado";
    }
}

Veiculo::Veiculo(string mc, int m, int a)
{
    marca = mc;
    mes = m;
    ano = a;
}

string Veiculo::getMarca() const {
    return marca;
}

int Veiculo::getMes() const {
    return mes;
}

int Veiculo::getAno() const {
    return ano;
}

Motorizado::Motorizado(string mc, int m, int a, string c, int cil) : Veiculo (mc, m, a)
{
    combustivel = c;
    cilindrada = cil;
}

string Motorizado::getCombustivel() const
{
    return combustivel;
}

int Motorizado::getCilindrada() const{
    return cilindrada;
}

Automovel::Automovel(string mc, int m, int a, string c, int cil) : Motorizado(mc, m, a, c, cil)
{
    // nothing to be done
}

Camiao::Camiao(string mc, int m, int a, string c, int cil, int cm) : Motorizado(mc, m, a, c, cil)
{
    carga_maxima = cm;
}

Bicicleta::Bicicleta(string mc, int m, int a, string t) : Veiculo(mc, m, a)
{
    tipo = t;
}


int Veiculo::info() const {
    return 3;
}

int Motorizado::info() const {
    cout << "Marca: " << marca << endl;
    cout << "Mes: " << MesString(mes) << endl;
    cout << "Ano: " << ano << endl;
    cout << "Combustivel: " << combustivel << endl;
    cout << "Cilidrado: " << cilindrada << endl;

    return 5;
}

int Camiao::info() const {
    cout << "Marca: " << marca << endl;
    cout << "Mes: " << MesString(mes) << endl;
    cout << "Ano: " << ano << endl;
    cout << "Combustivel: " << this->getCombustivel() << endl;
    cout << "Cilindrada: " << this->getCilindrada() << endl;
    cout << "Carga maxima: " << carga_maxima << endl;

    return 6;
}

int Automovel::info() const {
    cout << "Marca: " << marca << endl;
    cout << "Mes: " << MesString(mes) << endl;
    cout << "Ano: " << ano << endl;
    cout << "Combustivel: " << this->getCombustivel() << endl;
    cout << "Cilindrada: " << this->getCilindrada() << endl;

    return 5;
}

int Bicicleta::info() const {
    cout << "Marca: " << marca << endl;
    cout << "Mes: " << MesString(mes) << endl;
    cout << "Ano: " << ano << endl;
    cout << "Tipo: " << tipo << endl;

    return 4;
}

bool Veiculo::operator<(const Veiculo &v) const {
    if (this->getAno() == v.getAno())
    {
        if (this->getMes() == v.getMes())
        {
            return false;
        }
        else if (this->getMes() > v.getMes())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else if (this->getAno() > v.getAno())
    {
        return false;
    }
    else
    {
        return true;
    }
}

float Motorizado::calcImposto() const {
    float imposto;
    if (combustivel == "gasolina")
    {
        if (ano > 1995)
        {
            if (cilindrada <= 1000)
                imposto = 14.56;
            if (cilindrada > 1000 && cilindrada <= 1300)
                imposto = 29.06;
            if (cilindrada > 1300 && cilindrada <= 1750)
                imposto = 45.15;
            if (cilindrada > 1750 && cilindrada <= 2600)
                imposto = 113.98;
            if (cilindrada > 2600 && cilindrada <= 3500)
                imposto = 181.17;
            if (cilindrada > 3500)
                imposto = 320.89;
        }
        if (ano <= 1995)
        {
            if (cilindrada <= 1000)
                imposto = 8.10;
            if (cilindrada > 1000 && cilindrada <= 1300)
                imposto = 14.56;
            if (cilindrada > 1300 && cilindrada <= 1750)
                imposto = 22.65;
            if (cilindrada > 1750 && cilindrada <= 2600)
                imposto = 54.89;
            if (cilindrada > 2600 && cilindrada <= 3500)
                imposto = 87.13;
            if (cilindrada > 3500)
                imposto = 148.37;
        }
    }
    else
    {
        if (ano > 1995) {
            if (cilindrada <= 1500)
                imposto = 14.56;
            if (cilindrada > 1500 && cilindrada <= 2000)
                imposto = 29.06;
            if (cilindrada > 2000 && cilindrada <= 3000)
                imposto = 45.15;
            if (cilindrada > 3000)
                imposto = 113.98;
        }
        if (ano <= 1995) {
            if (cilindrada <= 1500)
                imposto = 8.10;
            if (cilindrada > 1500 && cilindrada <= 2000)
                imposto = 14.56;
            if (cilindrada > 2000 && cilindrada <= 3000)
                imposto = 22.65;
            if (cilindrada > 3000)
                imposto = 54.89;
        }
    }
    return imposto;
}

float Bicicleta::calcImposto() const {
    return 0;
}
