#include "maquinaEmpacotar.h"
#include <sstream>


MaquinaEmpacotar::MaquinaEmpacotar(int capCaixas): capacidadeCaixas(capCaixas)
{}

unsigned MaquinaEmpacotar::numCaixasUsadas() {
	return caixas.size();
}

unsigned MaquinaEmpacotar::addCaixa(Caixa& cx) {
	caixas.push(cx);
	return caixas.size();
}

HEAP_OBJS MaquinaEmpacotar::getObjetos() const {
	return this->objetos;
}

HEAP_CAIXAS MaquinaEmpacotar::getCaixas() const {
	return this->caixas;
}


unsigned MaquinaEmpacotar::carregaPaletaObjetos(vector<Objeto> &objs) {
	unsigned count = 0;
    for (auto it = objs.begin(); it != objs.end(); it++) {
        if ((*it).getPeso() <= this->capacidadeCaixas) {
            objetos.push(*it);
            objs.erase(it);
            count++;
            it--;
        }
    }
    return count;
}

Caixa MaquinaEmpacotar::procuraCaixa(Objeto& obj) {
	Caixa cx;
	vector<Caixa> toStay;
	while (!caixas.empty()) {
	    if (caixas.top().getCargaLivre() >= obj.getPeso()) {
	        cx = caixas.top();
	        caixas.pop();
	        break;
	    }
	    else {
	        toStay.emplace_back(caixas.top());
	        caixas.pop();
	    }
	}

	for (const auto& box : toStay)
	    caixas.push(box);

	return cx;
}

// a alterar
unsigned MaquinaEmpacotar::empacotaObjetos() {
	return 0;
}

// a alterar
string MaquinaEmpacotar::imprimeObjetosPorEmpacotar() const {
	return "";
}

// a alterar
Caixa MaquinaEmpacotar::caixaMaisObjetos() const {
	Caixa cx;
	return cx;
}



