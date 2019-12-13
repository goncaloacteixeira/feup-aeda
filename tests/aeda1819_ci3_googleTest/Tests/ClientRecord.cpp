#include "ClientRecord.h"

ClientRecord::ClientRecord(Client* client) {
	this->clientPtr = client;
}

string ClientRecord::getName() const {
	return this->clientPtr->name;
}

string ClientRecord::getEMail() const {
	return this->clientPtr->eMail;
}

void ClientRecord::setEMail(string eMail) {
	this->clientPtr->eMail = eMail;
}

Client* ClientRecord::getClientPointer() const {
	return this->clientPtr;
}
