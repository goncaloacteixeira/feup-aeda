#include "veiculo.h"
#include <iostream>

using namespace std;

Veiculo::Veiculo(string mc, int m, int a)
{
    marca = mc;
    mes = m;
    ano = a;
}

string Veiculo::getMarca() const {
    return marca;
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



