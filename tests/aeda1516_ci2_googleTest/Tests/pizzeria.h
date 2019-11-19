/*
 * pizzaria.h
 *
 *  Created on: Oct 21, 2015
 *      Author: RRossetti
 */

#ifndef PIZZERIA_H_
#define PIZZERIA_H_

#include <string>
#include <vector>
#include <iostream>

#include "sequentialSearch.h"
#include "insertionSort.h"

using namespace std;

class Menu {
    static int current_id;
	int id;
	string name;
	int likes;
	vector<string> ingredients;
public:
	Menu();
	Menu(string n1, vector<string> is1);
	Menu(int id1, string n1, vector<string> is1, int lks1);
	int getId() const;
	void setId(int id1);
	string getName() const;
	void setName(string n1);
	vector<string> getIngredients() const;
	void addLike() { ++likes; }
	int getLikes() const { return likes; }

	class ExceptionIngredientsRepeated {
    public:
	    ExceptionIngredientsRepeated() {}
	};

	class ExceptionIngredientNotPresent {
	    string name;
    public:
	    ExceptionIngredientNotPresent(string name) { this->name = name; }
	    string getIngredient() { return this->name; }
	};

	void setIngredients(const vector<string> &is1);
};

class Customer {
	int nif;
	string name;
public:
	Customer(int nif1, string n1);
	int getNIF() const;
	string getName() const;
};

class Pizzeria {
	vector<Menu> menus;
	vector<Customer*> customers;
public:
	Pizzeria();
	Pizzeria(vector<Menu> ms1);
	vector<Menu> getMenus() const;
	vector<Customer*> getCustomers() const;
	int addCustomer(Customer* c1);

	vector<Menu> optionsWithinIngredientLimits(int i1, int i2) const;
	vector<Menu> popularityRank() const;
	Customer* chefCustomer();
	Menu& removeIngredient(vector<string> is1, string i1);

	class ExceptionInexistentMenu {
	public:
	    ExceptionInexistentMenu() { }
	};

    class ExceptionInvalidIngredientLimits {
    public:
        ExceptionInvalidIngredientLimits() {}
    };
};

#include <set>
template <class T>
bool isSet(const vector<T>& v1) {
    set<T> uniques = {v1.begin(), v1.end()};
    return (v1.size() == uniques.size());
}

#endif /* PIZZERIA_H_ */
