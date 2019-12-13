#ifndef SRC_PROPERTY_H_
#define SRC_PROPERTY_H_

#include <string>
#include "Client.h"
using namespace std;

class Property {
	const string address;
	const string ownerName;
	const string postalCode;
	const string typology;
	const int price;
	tuple<Client*, int> reservation;
public:
	Property(string a, string o, string pc, string t, int pr);
	string getAddress() const;
	string getOwnerName() const;
	string getPostalCode() const;
	string getTypology() const;
	int getPrice() const;
	tuple<Client*, int> getReservation() const;
	void setReservation(tuple<Client*, int>);

};

#endif /* SRC_PROPERTY_H_ */
