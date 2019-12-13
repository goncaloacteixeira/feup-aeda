#ifndef SRC_PROPERTYTYPE_H_
#define SRC_BOOK_H_

#include "Property.h"
#include "Client.h"
#include <string>
using namespace std;

class PropertyTypeItem {
	string address;
	string postalCode;
	string typology;
	int maxPrice;
	vector<Property*> items; //all properties with same postalCode typology and up to maxPrice
public:
	PropertyTypeItem(string address, string postalCode, string typology, int maxPrice);
	string getAddress() const;
	string getPostalCode() const;
	string getTypology() const;
	int getMaxPrice() const;
	vector<Property*> getItems() const;
	void setItems(vector<Property*> properties);
	void addItems(Property* property);
    bool operator<(const PropertyTypeItem &pti1) const;
    bool operator==(const PropertyTypeItem &pti1) const;
};


#endif /* SRC_PROPERTYTYPE_H_ */
