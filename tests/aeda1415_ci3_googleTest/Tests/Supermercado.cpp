/*
 * Supermercado.cpp
 *
 * Created on: Dec 3, 2014
 *
 */

#include "Supermercado.h"

//A ser implementado pelo estudante!

int Cliente::numeroItens() const {
    int count = 0;
    for (auto &cesto : this->cestos)
        count += cesto.getItens().size();
    return count;
}

int Cliente::valorItens() const {
    int price = 0;
    for (auto &cesto : this->cestos) {
        stack<Item> temp = cesto.getItens();
        while (!temp.empty()) {
            price += temp.top().preco;
            temp.pop();
        }
    }
    return price;
}

int Cliente::trocarItem(Item &novoItem) {
    int count = 1;
    for (auto &cesto : cestos) {
        stack<Item> toStay;
        while (!cesto.getItens().empty()) {
            if (cesto.getItens().top().produto == novoItem.produto && cesto.getItens().top().preco > novoItem.preco)
                count++;
            else
                toStay.push(cesto.getItens().top());
            cesto.popItem();
        }
        while (!toStay.empty()) {
            cesto.pushItem(toStay.top());
            toStay.pop();
        }
    }
    return count;
}

bool foo(Item i1, Item i2) {
    return i1.peso > i2.peso;
}

void Cliente::organizarCestos() {
    for (auto& cesto : cestos) {
        vector<Item> items;
        while (!cesto.getItens().empty()) {
            items.push_back(cesto.topItem());
            cesto.popItem();
        }
        sort(items.begin(), items.end(), foo);
        for (auto& item : items)
            cesto.pushItem(item);
    }
}

vector<string> Cliente::contarItensPorTipo() {
    vector<string> ret;
    vector<pair<string,int>> info;
    for (auto& cesto : cestos) {
        stack<Item> items = cesto.getItens();
        while (!items.empty()) {
            bool flag = false;
            int i;
            for (i = 0; i < info.size(); i++) {
                if (info[i].first == items.top().tipo) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                info[i].second++;
            else
                info.push_back(pair<string,int>(items.top().tipo, 1));
            items.pop();
        }
    }
    for (auto &pair : info)
        ret.push_back(pair.first + " " + to_string(pair.second));
    return ret;
}

int Cliente::novoItem(const Item &umItem) {
    for (auto &cesto : cestos)
        if (cesto.novoItem(umItem) != 0)
            return cestos.size();
    cestos.push_back(Cesto({umItem}));
    return cestos.size();
}

int Cesto::novoItem(const Item &umItem) {
    stack<Item> items = getItens();
    int volume = 0;
    int peso = 0;
    int count = 0;
    while(!items.empty()) {
        volume += items.top().volume;
        peso += items.top().peso;
        count++;
        items.pop();
    }
    if ((volume + umItem.volume) > max_volume || (peso + umItem.peso) > max_peso)
        return 0;
    itens.push(umItem);
    return ++count;
}

int Supermercado::novoCliente(Cliente &umCliente) {
    if (umCliente.getIdade() >= 65) {
        (filaNormal.size() >= filaPrioritaria.size()) ? filaPrioritaria.push(umCliente) : filaNormal.push(umCliente);
    }
    else
        filaNormal.push(umCliente);
    return filaNormal.size() + filaPrioritaria.size();
}

Cliente Supermercado::sairDaFila(string umNomeDeCliente) {
    queue<Cliente> aux;
    Cliente *c = new Cliente("",0);
    bool found = false;
    while (!filaNormal.empty()) {
        if (filaNormal.front().getNome() == umNomeDeCliente) {
            *c = filaNormal.front();
            found = true;
        }
        else {
            aux.push(filaNormal.front());
        }
        filaNormal.pop();
    }
    while (!aux.empty()) {
        filaNormal.push(aux.front());
        aux.pop();
    }

    if (found) return *c;

    while (!filaPrioritaria.empty()) {
        if (filaPrioritaria.front().getNome() == umNomeDeCliente) {
            *c = filaPrioritaria.front();
            found = true;
        }
        else {
            aux.push(filaPrioritaria.front());
        }
        filaPrioritaria.pop();
    }
    while (!aux.empty()) {
        filaPrioritaria.push(aux.front());
        aux.pop();
    }

    if (found) return *c;
    throw ClienteInexistente(umNomeDeCliente);
}
