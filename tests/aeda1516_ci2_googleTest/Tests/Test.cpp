#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include <string>
#include "pizzeria.h"

TEST(test_1, a){
	vector<string> m1;
	m1.push_back("pepperoni");
	m1.push_back("mozzarella");
	m1.push_back("tomato");
	m1.push_back("olive");
	m1.push_back("pepper");

	vector<string> m2;
	m2.push_back("tuna");
	m2.push_back("mozzarella");
	m2.push_back("tomato");
	m2.push_back("olive");
	m2.push_back("pineapple");

	vector<string> m3;
	m3.push_back("meat");
	m3.push_back("mozzarella");
	m3.push_back("tomato");
	m3.push_back("mushroom");
	m3.push_back("onion");

	Menu pepperoni("pepperoni", m1);
	Menu tuna("tuna", m2);
	Menu meat("meat", m3);

    EXPECT_EQ(1, pepperoni.getId());
    EXPECT_EQ(2, tuna.getId());
    EXPECT_EQ(3, meat.getId());
}

TEST(test_1, b){
	vector<string> v1;
	v1.push_back("pepperoni");
	v1.push_back("onion");
	v1.push_back("oregano");
	v1.push_back("mushroom");

	vector<string> v2;
	v2.push_back("pepperoni");
	v2.push_back("onion");
	v2.push_back("oregano");
	v2.push_back("mushroom");
	v2.push_back("onion");

	vector<string> v3;
	v3.push_back("pepperoni");

	vector<int> v4;

    EXPECT_EQ(true, isSet(v1));
    EXPECT_EQ(false, isSet(v2));
    EXPECT_EQ(true, isSet(v3));
    EXPECT_EQ(true, isSet(v4));
}

TEST(test_1, c){
	Menu m1;
	vector<string> is1;
	is1.push_back("chorizo");
	is1.push_back("pepperoni");
	is1.push_back("onion");
	is1.push_back("chorizo");

	EXPECT_THROW(m1.setIngredients(is1), Menu::ExceptionIngredientsRepeated);

	is1 = m1.getIngredients();
	EXPECT_EQ(0, is1.size());

	vector<string> is2;
	is2.push_back("pepperoni");
	is2.push_back("mozzarella");
	is2.push_back("onion");
	is2.push_back("pineapple");
	is2.push_back("tomato");

	m1.setIngredients(is2);
	is1 = m1.getIngredients();
	EXPECT_EQ(5, is1.size());
}

TEST(test_1, d){
	vector<string> m1;
	m1.push_back("pepperoni");
	m1.push_back("mozzarella");
	m1.push_back("tomato");
	m1.push_back("olive");
	m1.push_back("pepper");

	vector<string> m2;
	m2.push_back("tuna");
	m2.push_back("mozzarella");
	m2.push_back("pineapple");

	vector<string> m3;
	m3.push_back("meat");
	m3.push_back("mozzarella");
	m3.push_back("tomato");
	m3.push_back("mushroom");
	m3.push_back("onion");
	m3.push_back("extra mozzarella");
	m3.push_back("red onion");

	vector<Menu> menus;
	menus.push_back(Menu(1, "pepperoni", m1, 10));
	menus.push_back(Menu(2, "tuna", m2, 5));
	menus.push_back(Menu(3, "meat", m3, 25));

	Pizzeria marios(menus);

	vector<Menu> options;
	EXPECT_THROW(marios.optionsWithinIngredientLimits(3, 2), Pizzeria::ExceptionInvalidIngredientLimits);
	EXPECT_THROW(marios.optionsWithinIngredientLimits(0, 2), Pizzeria::ExceptionInvalidIngredientLimits);
	EXPECT_THROW(marios.optionsWithinIngredientLimits(2, -1), Pizzeria::ExceptionInvalidIngredientLimits);
	try {
		EXPECT_EQ(2, marios.optionsWithinIngredientLimits(3, 5).size());
		EXPECT_EQ(0, marios.optionsWithinIngredientLimits(1, 2).size());
		EXPECT_EQ(0, marios.optionsWithinIngredientLimits(10, 15).size());
		EXPECT_EQ(1, marios.optionsWithinIngredientLimits(7, 7).size());
	}
	catch(Pizzeria::ExceptionInvalidIngredientLimits& e) {

	}
}

TEST(test_1, e){
	vector<string> m1;
	m1.push_back("pepperoni");
	m1.push_back("mozzarella");
	m1.push_back("tomato");
	m1.push_back("olive");
	m1.push_back("pepper");

	vector<string> m2;
	m2.push_back("tuna");
	m2.push_back("mozzarella");
	m2.push_back("tomato");
	m2.push_back("olive");
	m2.push_back("pineapple");

	vector<string> m3;
	m3.push_back("meat");
	m3.push_back("mozzarella");
	m3.push_back("tomato");
	m3.push_back("mushroom");
	m3.push_back("onion");

	vector<string> m4;
	m4.push_back("chicken");
	m4.push_back("mozzarella");
	m4.push_back("tomato");
	m4.push_back("mushroom");
	m4.push_back("onion");

	vector<string> m5;
	m5.push_back("chicken");
	m5.push_back("mozzarella");
	m5.push_back("tomato");
	m5.push_back("mushroom");
	m5.push_back("onion");

	vector<Menu> menus;
	menus.push_back(Menu(1, "pepperoni", m1, 10));
	menus.push_back(Menu(2, "tuna", m2, 5));
	menus.push_back(Menu(3, "meat", m3, 25));
	menus.push_back(Menu(4, "chicken", m4, 25));

	Pizzeria marios(menus);
	vector<Menu> rank = marios.popularityRank();
	EXPECT_EQ(25, rank[0].getLikes());
	EXPECT_EQ(25, rank[1].getLikes());
	EXPECT_EQ(10, rank[2].getLikes());

	EXPECT_EQ("chicken", rank[0].getName());
	EXPECT_EQ("tuna", rank[3].getName());
}

TEST(test_1, f){
	vector<string> m1;
	m1.push_back("pepperoni");
	m1.push_back("mozzarella");
	m1.push_back("tomato");
	m1.push_back("olive");
	m1.push_back("pepper");

	vector<string> m2;
	m2.push_back("tuna");
	m2.push_back("mozzarella");
	m2.push_back("pineapple");

	vector<string> m3;
	m3.push_back("meat");
	m3.push_back("mozzarella");
	m3.push_back("tomato");
	m3.push_back("mushroom");
	m3.push_back("onion");
	m3.push_back("extra mozzarella");
	m3.push_back("red onion");
	m3.push_back("pepper");

	vector<string> m4;
	m4.push_back("pepperoni");
	m4.push_back("mozzarella");
	m4.push_back("tomato");
	m4.push_back("olive");

	vector<string> m5;
	m5.push_back("tuna");
	m5.push_back("mozzarella");
	m5.push_back("pineapple");
	m5.push_back("red onion");

	vector<string> m6;
	m6.push_back("meat");
	m6.push_back("mozzarella");
	m6.push_back("tomato");
	m6.push_back("mushroom");
	m6.push_back("onion");
	m6.push_back("extra mozzarella");

	vector<Menu> menus;
	menus.push_back(Menu(1, "Joao",  m1, 10));
	menus.push_back(Menu(2, "tuna",  m2, 5));
	menus.push_back(Menu(3, "Ana",   m3, 25));
	menus.push_back(Menu(4, "Maria", m4, 10));
	menus.push_back(Menu(5, "Ana",   m5, 5));
	menus.push_back(Menu(6, "Pedro", m6, 25));

	Pizzeria marios(menus);

	Customer c1(222333555, "Joao");
	marios.addCustomer(&c1);
	Customer c2(222333444, "Ana");
	marios.addCustomer(&c2);
	Customer c3(111222333, "Maria");
	marios.addCustomer(&c3);
	Customer c4(111333222, "Pedro");
	marios.addCustomer(&c4);

	EXPECT_EQ(111333222, marios.chefCustomer()->getNIF());

	vector<Menu> menus2;
	menus2.push_back(Menu(1, "Joao",  m1, 10));
	menus2.push_back(Menu(2, "tuna",  m2, 5));
	menus2.push_back(Menu(3, "Ana",   m3, 25));
	menus2.push_back(Menu(4, "Maria", m4, 10));
	menus2.push_back(Menu(5, "Ana",   m5, 5));
	menus2.push_back(Menu(6, "Joao",  m6, 25));

	Pizzeria marios2(menus2);

	marios2.addCustomer(&c1);
	marios2.addCustomer(&c2);

	EXPECT_EQ(222333555, marios2.chefCustomer()->getNIF());
}

TEST(test_1, g){
	vector<string> is1;
	is1.push_back("pepperoni");
	is1.push_back("mozzarella");
	is1.push_back("tomato");
	is1.push_back("olive");
	is1.push_back("pepper");

	vector<string> is2;
	is2.push_back("tuna");
	is2.push_back("mozzarella");
	is2.push_back("pineapple");

	vector<Menu> menus;
	menus.push_back(Menu(1, "pepperoni",  is1, 0));
	menus.push_back(Menu(2, "tuna",  is2, 0));

	Pizzeria marios(menus);

	Menu m1 = marios.removeIngredient(is2, "pineapple");
	EXPECT_EQ(2, m1.getIngredients().size());

	m1 = marios.removeIngredient(is1, "olive");
	EXPECT_EQ(4, m1.getIngredients().size());

	m1 = marios.removeIngredient(m1.getIngredients(), "mozzarella");
	EXPECT_EQ(3, m1.getIngredients().size());


	EXPECT_THROW(marios.removeIngredient(menus[0].getIngredients(), "pepper"), Pizzeria::ExceptionInexistentMenu);
	EXPECT_THROW(marios.removeIngredient(menus[1].getIngredients(), "tuna"), Pizzeria::ExceptionInexistentMenu);

	Pizzeria marios2(menus);

	try {
		m1 = marios2.removeIngredient(menus[0].getIngredients(), "tuna");
	}
	catch(Menu::ExceptionIngredientNotPresent& e) {
		EXPECT_EQ("tuna", e.getIngredient());
	}

	try {
		m1 = marios2.removeIngredient(menus[1].getIngredients(), "pepperoni");
	}
	catch(Menu::ExceptionIngredientNotPresent&e) {
		EXPECT_EQ("pepperoni", e.getIngredient());
	}
}



