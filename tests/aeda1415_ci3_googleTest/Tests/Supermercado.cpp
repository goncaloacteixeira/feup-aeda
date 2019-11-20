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
