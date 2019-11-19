#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Table.h"
#include "Dish.h"
#include "Restaurant.h"

using testing::Eq;
using namespace std;

// Restaurant::addDishes()
TEST(test_1, a) {

	stack<Dish*> st1;
	st1.push(new Dish("Spring", Dessert));
	st1.push(new Dish("Spring", Dessert));
	st1.push(new Dish("Spring", Dessert));

	stack<Dish*> st2;
	st2.push(new Dish("Spring", Plate));
	st2.push(new Dish("Spring", Plate));

	stack<Dish*> st3;
	st3.push(new Dish("Asian", Plate));
	st3.push(new Dish("Asian", Plate));
	st3.push(new Dish("Asian", Plate));
	st3.push(new Dish("Asian", Plate));

	vector< stack<Dish*> > clean;
	clean.push_back(st1);
	clean.push_back(st2);
	clean.push_back(st3);

	Restaurant r(&clean, NULL, NULL);

	r.addDishes(10, "Spring", Plate);
    EXPECT_EQ(12, r.getCleanDishStack("Spring", Plate).size());

	r.addDishes(5, "Asian", Bowl);
    EXPECT_EQ(5, r.getCleanDishStack("Asian", Bowl).size());

    EXPECT_EQ(4, r.getCleanDishStack("Asian", Plate).size());
}

// Restaurant::washDish()
TEST(test_1, b) {

	Dish* d1 = new Dish("Asian", Plate);
	Dish* d2 = new Dish("White", Bowl);
	Dish* d3 = new Dish("Spring", Plate);
	Dish* d4 = new Dish("White", Dessert);

	queue<Dish*> dirty;
	dirty.push(d1);
	dirty.push(d2);
	dirty.push(d3);
	dirty.push(d4);

	Restaurant r(NULL, &dirty, NULL);

    EXPECT_EQ(true, r.washDish() == d1);
    EXPECT_EQ(true, r.getDirty().front() == d2);
    EXPECT_EQ(1, r.getDrying().size());
	list<Dish*> drying = r.getDrying();
    EXPECT_EQ(true, (find(drying.begin(), drying.end(), d1) != drying.end()));

    EXPECT_EQ(true, r.washDish() == d2);
    EXPECT_EQ(true, r.getDirty().front() == d3);
    EXPECT_EQ(2, r.getDrying().size());
	drying = r.getDrying();
    EXPECT_EQ(true, (find(drying.begin(), drying.end(), d2) != drying.end()));

    EXPECT_EQ(true, r.washDish() == d3);
    EXPECT_EQ(true, r.getDirty().front() == d4);
    EXPECT_EQ(3, r.getDrying().size());
	drying = r.getDrying();
	EXPECT_EQ(true, (find(drying.begin(), drying.end(), d3) != drying.end()));

}

// Restaurant::clearTable()
TEST(test_1, c) {
	Restaurant r;

	int table0_size = 5;
	r.addTable(table0_size);

	Table t1(4);
	vector<Dish*> dishes11;
	dishes11.push_back(new Dish("Spring", Plate));
	dishes11.push_back(new Dish("Spring", Plate));
	dishes11.push_back(new Dish("Spring", Plate));
	dishes11.push_back(new Dish("Spring", Plate));
	t1.putOn(dishes11);
	vector<Dish*> dishes12;
	dishes12.push_back(new Dish("Spring", Dessert));
	dishes12.push_back(new Dish("Spring", Dessert));
	dishes12.push_back(new Dish("Spring", Dessert));
	dishes12.push_back(new Dish("Spring", Dessert));
	t1.putOn(dishes12);
	r.addTable(t1);

	Table t2(3);
	vector<Dish*> dishes2;
	dishes2.push_back(new Dish("White", Dessert));
	dishes2.push_back(new Dish("White", Dessert));
	dishes2.push_back(new Dish("White", Dessert));
	t2.putOn(dishes2);
	r.addTable(t2);

	int n_dirty = r.getDirty().size();
	r.clearTable(0);
	Table t0_changed = r.getTable(0);
	EXPECT_EQ(true, t0_changed.empty());
	EXPECT_EQ(0, r.getDirty().size()-n_dirty);

	n_dirty = r.getDirty().size();
	r.clearTable(1);
	Table t1_changed = r.getTable(1);
	EXPECT_EQ(true, t1_changed.empty());
	EXPECT_EQ(8, r.getDirty().size()-n_dirty);

	n_dirty = r.getDirty().size();
	r.clearTable(2);
	Table t2_changed = r.getTable(2);
	EXPECT_EQ(true, t2_changed.empty());
	EXPECT_EQ(3, r.getDirty().size()-n_dirty);

	r.clearTable(3);

}

// Restaurant::storeDryDishes()
TEST(test_1, d) {

	stack<Dish*> st1;
	st1.push(new Dish("Spring", Dessert));
	st1.push(new Dish("Spring", Dessert));
	st1.push(new Dish("Spring", Dessert));

	stack<Dish*> st2;
	st2.push(new Dish("Spring", Plate));
	st2.push(new Dish("Spring", Plate));

	stack<Dish*> st3;
	st3.push(new Dish("Asian", Plate));
	st3.push(new Dish("Asian", Plate));
	st3.push(new Dish("Asian", Plate));

	vector< stack<Dish*> > clean;
	clean.push_back(st1);
	clean.push_back(st2);
	clean.push_back(st3);

	list<Dish*> drying;
	drying.push_back(new Dish("Asian", Plate));
	drying.push_back(new Dish("White", Bowl));
	drying.push_back(new Dish("Asian", Plate));
	drying.push_back(new Dish("Asian", Bowl));
	drying.push_back(new Dish("Spring", Plate));
	drying.push_back(new Dish("White", Dessert));

	Restaurant r(&clean, NULL, &drying);

	r.storeDryDishes("Asian", Plate);
	EXPECT_EQ(5, r.getCleanDishStack("Asian", Plate).size());

	r.storeDryDishes("White", Bowl);
	EXPECT_EQ(1, r.getCleanDishStack("White", Bowl).size());

	r.storeDryDishes("Asian", Plate);
	EXPECT_EQ(5, r.getCleanDishStack("Asian", Plate).size());

	r.storeDryDishes("White", Plate);
	EXPECT_EQ(0, r.getCleanDishStack("White", Plate).size());

	EXPECT_EQ(3, r.getCleanDishStack("Spring", Dessert).size());

}

// Restaurant::setupTable()
TEST(test_1, e) {

	stack<Dish*> st1;
	st1.push(new Dish("Asian", Plate));
	st1.push(new Dish("Asian", Plate));
	st1.push(new Dish("Asian", Plate));
	stack<Dish*> st2;
	st2.push(new Dish("Asian", Bowl));
	st2.push(new Dish("Asian", Bowl));
	st2.push(new Dish("Asian", Bowl));
	st2.push(new Dish("Asian", Bowl));
	st2.push(new Dish("Asian", Bowl));
	stack<Dish*> st3;
	st3.push(new Dish("White", Plate));
	st3.push(new Dish("White", Plate));
	st3.push(new Dish("White", Plate));
	st3.push(new Dish("White", Plate));
	st3.push(new Dish("White", Plate));
	st3.push(new Dish("White", Plate));
	st3.push(new Dish("White", Plate));
	vector< stack<Dish*> > clean;
	clean.push_back(st1);
	clean.push_back(st2);
	clean.push_back(st3);

	Restaurant r(&clean, NULL, NULL);

	int table0_size = 5;
	r.addTable(table0_size);

	vector<Dish*> dishes;
	dishes.push_back(new Dish("Spring", Dessert));
	dishes.push_back(new Dish("Spring", Dessert));
	dishes.push_back(new Dish("Spring", Dessert));
	dishes.push_back(new Dish("Spring", Dessert));
	Table t1(4);
	t1.putOn(dishes);
	r.addTable(t1);

    EXPECT_THROW(r.setupTable(0, "Asian"), Restaurant::NotEnoughDishesException);
	EXPECT_EQ(3, r.getCleanDishStack("Asian", Plate).size());

	int n = r.getCleanDishStack("White", Plate).size();
	r.setupTable(0, "White");
	n -= r.getCleanDishStack("White", Plate).size();
	EXPECT_EQ(table0_size, n);
	Table t0_changed = r.getTable(0);
	EXPECT_EQ("White", t0_changed.getCollection());
	vector< stack<Dish*> > places = t0_changed.getPlaces();
	for(vector< stack<Dish*> >::const_iterator it = places.begin(); it != places.end(); ++it) {
		EXPECT_EQ(1, (*it).size());
		EXPECT_EQ("White", (*it).top()->getCollection());
		EXPECT_EQ(Plate, (*it).top()->getType());
	}
	EXPECT_EQ(3, r.getCleanDishStack("Asian", Plate).size());

	EXPECT_THROW(r.setupTable(1, "Asian"), Restaurant::TableNotReadyException);
	EXPECT_EQ(3, r.getCleanDishStack("Asian", Plate).size());

	r.setupTable(2, "White");

}


// Restaurant::pickupAndGroupDryDishes()
TEST(test_1, f) {

	list<Dish*> drying;
	drying.push_back(new Dish("Spring", Bowl));
	drying.push_back(new Dish("Asian", Plate));
	drying.push_back(new Dish("White", Bowl));
	drying.push_back(new Dish("Asian", Plate));
	drying.push_back(new Dish("Asian", Bowl));
	drying.push_back(new Dish("Spring", Plate));
	drying.push_back(new Dish("White", Bowl));
	drying.push_back(new Dish("White", Dessert));
	drying.push_back(new Dish("White", Bowl));

	Restaurant r(NULL, NULL, &drying);

	list<Dish*> dry_grouped = r.pickupAndGroupDryDishes();

	EXPECT_EQ(drying.size(), dry_grouped.size());
	EXPECT_EQ(0, r.getDrying().size());

//	for(list<Dish*>::iterator it = dry_grouped.begin(); it != dry_grouped.end(); ++it) {
//		cout << (*it)->getCollection() << " " << (*it)->getType() << endl;
//	}

	list<Dish*>::iterator it = dry_grouped.begin();
	while(it != dry_grouped.end()) {
		Dish* d = *it;
		// check existence in drying list
		list<Dish*>::iterator it2 = drying.begin();
		while(it2 != drying.end() && !(*(*it2) == *(*it))) {
			++it2;
		}
		EXPECT_EQ(false, it2 == drying.end());
		drying.erase(it2);

		// skip consecutive equal dishes
		it2 = it;
		while(it2 != dry_grouped.end() && *(*it2) == *d) {
			++it2;
		}
		it = it2;

		// check that no more equal dishes follow
		while(it2 != dry_grouped.end()) {
			EXPECT_EQ(false, *(*it2) == *d);
			++it2;
		}
	}

	Restaurant r2;
	r2.pickupAndGroupDryDishes();
	EXPECT_EQ(0, r2.getDrying().size());

}

// Restaurant::storeGroupedDishes()
TEST(test_1, g) {

	stack<Dish*> st1;
	st1.push(new Dish("Asian", Plate));
	st1.push(new Dish("Asian", Plate));
	st1.push(new Dish("Asian", Plate));
	stack<Dish*> st2;
	st2.push(new Dish("Asian", Bowl));
	st2.push(new Dish("Asian", Bowl));
	stack<Dish*> st3;
	st3.push(new Dish("White", Dessert));
	st3.push(new Dish("White", Dessert));
	st3.push(new Dish("White", Dessert));
	stack<Dish*> st4;
	st4.push(new Dish("Spring", Dessert));
	st4.push(new Dish("Spring", Dessert));
	vector< stack<Dish*> > clean;
	clean.push_back(st1);
	clean.push_back(st2);
	clean.push_back(st3);
	clean.push_back(st4);

	Restaurant r(&clean, NULL, NULL);

	list<Dish*> dry_grouped;
	dry_grouped.push_back(new Dish("Spring", Bowl));
	dry_grouped.push_back(new Dish("Asian", Plate));
	dry_grouped.push_back(new Dish("Asian", Plate));
	dry_grouped.push_back(new Dish("White", Bowl));
	dry_grouped.push_back(new Dish("White", Bowl));
	dry_grouped.push_back(new Dish("White", Bowl));
	dry_grouped.push_back(new Dish("Asian", Bowl));
	dry_grouped.push_back(new Dish("Spring", Plate));
	dry_grouped.push_back(new Dish("White", Dessert));

	EXPECT_EQ(6, r.storeGroupedDishes(dry_grouped));

	EXPECT_EQ(1, r.getCleanDishStack("Spring", Bowl).size());
	EXPECT_EQ(5, r.getCleanDishStack("Asian", Plate).size());
	EXPECT_EQ(3, r.getCleanDishStack("White", Bowl).size());
	EXPECT_EQ(3, r.getCleanDishStack("Asian", Bowl).size());
	EXPECT_EQ(1, r.getCleanDishStack("Spring", Plate).size());
	EXPECT_EQ(4, r.getCleanDishStack("White", Dessert).size());
	EXPECT_EQ(2, r.getCleanDishStack("Spring", Dessert).size());

}