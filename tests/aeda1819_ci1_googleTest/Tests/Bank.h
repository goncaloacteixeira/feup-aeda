/*
 * Bank.h
 */

#ifndef SRC_BANK_H_
#define SRC_BANK_H_

#include "Account.h"
#include <vector>

#include "BankOfficer.h"


#include <set>
template<class T>
unsigned int numberDifferent(const vector<T> & v1)
{
    set<T> unique;
    if (v1.size() != 0)
        for (int i = 0; i < v1.size(); i++)
            unique.insert(v1[i]);
    return unique.size();
}

class Bank {
	vector<Account *> accounts;
	vector<BankOfficer> bankOfficers;
public:
	Bank();
	void addAccount(Account *a);
	void addBankOfficer(BankOfficer b);
	vector<BankOfficer> getBankOfficers() const;
	vector<Account *> getAccounts() const;

	//-------
	double getWithdraw(string cod1) const;
	vector<Account *> removeBankOfficer(string name);
	const BankOfficer& addAccountToBankOfficer(Account *ac, string name);
	void sortAccounts();
};

class NoBankOfficerException {
    string name;
public:
    NoBankOfficerException(string name) {this->name = name; };
    string getName() {return name;};
};


#endif /* SRC_BANK_H_ */
