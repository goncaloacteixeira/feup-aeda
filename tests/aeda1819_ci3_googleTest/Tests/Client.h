#ifndef SRC_CLIENT_H_
#define SRC_CLIENT_H_

#include <string>
#include <vector>
#include <tuple>
using namespace std;

class Client {
	string name;
	string eMail;
	tuple<string, string, string, string> propertyListing;
	vector<tuple<string, string, string, string> > visitedProperties;
public:
	friend class ClientRecord;
	Client(string name, string eMail);
	string getName() const;
	string getEMail() const;
	void setEmail(string email);
	tuple<string, string,string, string> getVisiting() const;
	vector<tuple<string, string, string, string> > getVisitedProperties() const;
	void addVisiting(string address, string postalCode, string typology, string price);
	bool operator<(const Client& c1) const;
};

#endif /* SRC_CLIENT_H_ */
