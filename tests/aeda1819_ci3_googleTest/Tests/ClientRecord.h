#ifndef SRC_CLIENTRECORD_H_
#define SRC_CLIENTRECORD_H_

#include <string>
#include "Client.h"
using namespace std;

class ClientRecord {
	Client* clientPtr;
public:
	ClientRecord(Client* client);
	Client* getClientPointer() const;
	string getName() const;
	string getEMail() const;
	void setEMail(string eMail);
};

#endif /* SRC_CLIENTRECORD_H_ */
