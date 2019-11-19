/*
 * pizzeria.cpp
 *
 *  Created on: 25 Oct 2015
 *      Author: RRossetti
 */

#include "pizzeria.h"

/*
 * CLASS MENU
 */


Menu::Menu() {
	id = 0;
	name = "";
	likes = 0;
}

int Menu::current_id = 1;

Menu::Menu(string n1, vector<string> is1) {
    this->likes = 0;
    this->name = n1;
    this->ingredients = is1;
    this->id = current_id;
    current_id++;
}

Menu::Menu(int id1, string n1, vector<string> is1, int lks1) {
	id = id1;
	name = n1;
	ingredients = is1;
	likes = lks1;
}

int Menu::getId() const { return id; }
void Menu::setId(int id1) { id = id1; }
string Menu::getName() const { return name; }
void Menu::setName(string n1) { name = n1; }
vector<string> Menu::getIngredients() const { return ingredients; }

void Menu::setIngredients(const vector<string> &is1) {
    if (!isSet(is1))
        throw ExceptionIngredientsRepeated();
    this->ingredients = is1;
}


/*
 * CLASS CUSTOMER
 */

Customer::Customer(int nif1, string n1) {
	nif = nif1;
	name = n1;
}

int Customer::getNIF() const {
	return nif;
}

string Customer::getName() const {
	return name;
}


/*
 * CLASS PIZZERIA
 */

Pizzeria::Pizzeria() { }

Pizzeria::Pizzeria(vector<Menu> ms1) {
	menus = ms1;
}

vector<Menu> Pizzeria::getMenus() const { return menus; }

vector<Customer*> Pizzeria::getCustomers() const { return customers; }

int Pizzeria::addCustomer(Customer* c1) {
	customers.push_back(c1);
	return customers.size();
}

vector<Menu> Pizzeria::optionsWithinIngredientLimits(int i1, int i2) const {
    if (i1<1 or i2<1 or i1>i2)
        throw ExceptionInvalidIngredientLimits();
    vector<Menu> res;
    for (auto menu : menus) {
        if (menu.getIngredients().size() <= i2 and menu.getIngredients().size() >= i1)
            res.emplace_back(menu);
    }
    return res;
}

bool foo(Menu& m1, Menu& m2) {
    if (m2.getLikes() < m1.getLikes())
        return true;
    else if (m2.getLikes() > m1.getLikes())
        return false;
    else if (m2.getIngredients().size() < m1.getIngredients().size())
        return true;
    else if (m2.getIngredients().size() > m1.getIngredients().size())
        return false;
    return (m1.getName() < m2.getName());
}

#include <algorithm>
vector<Menu> Pizzeria::popularityRank() const {
    vector<Menu> menusRank = this->getMenus();
    sort(menusRank.begin(), menusRank.end(), foo);
    return menusRank;
}

Customer *Pizzeria::chefCustomer() {
    if (menus.empty()) return nullptr;
    Customer* c;
    int auxMenus = 1;
    int auxLikes = 0;
    for (auto customer : this->getCustomers()) {
        int custMenus = 0;
        int custLikes = 0;
        for (const auto& menu : menus) {
            if (menu.getName() == customer->getName()) {
                custMenus++;
                custLikes += menu.getLikes();
            }
        }
        if (custLikes / custMenus > auxLikes / auxMenus) {
            auxLikes = custLikes;
            auxMenus = custMenus;
            c = customer;
        }
    }
    return c;
}

Menu &Pizzeria::removeIngredient(vector<string> is1, string i1) {
    for (auto &menu : menus) {
        if (menu.getIngredients() == is1) {
            vector<string> toUpdate = menu.getIngredients();
            for (int i = 0; i < menu.getIngredients().size(); i++) {
                if (toUpdate[i] == i1) {
                    toUpdate.erase(toUpdate.begin() + i);
                    menu.setIngredients(toUpdate);
                    return menu;
                }
            }
            throw Menu::ExceptionIngredientNotPresent(i1);
        }
    }
    throw ExceptionInexistentMenu();
}


