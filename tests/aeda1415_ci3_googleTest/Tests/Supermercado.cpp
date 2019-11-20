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
