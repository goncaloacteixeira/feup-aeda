/*
 * Bank.cpp
 */

#include "Bank.h"
#include <algorithm>
#include <string>

Bank::Bank() {}

void Bank::addAccount(Account *a) {
	accounts.push_back(a);
}

void Bank::addBankOfficer(BankOfficer b){
	bankOfficers.push_back(b);
}

vector<BankOfficer> Bank::getBankOfficers() const {
	return bankOfficers;
}

vector<Account *> Bank::getAccounts() const {
	return accounts;
}


// ----------------------------------------------------------------------------------------------

// a alterar
double Bank::getWithdraw(string cod1) const{
	double res = 0;
    for (auto acc : accounts)
	    if (acc->getCodH() == cod1)
	        res += acc->getWithdraw();
	return res;
}


// a alterar
vector<Account *> Bank::removeBankOfficer(string name){
    vector<Account *> ret = {};
    for (int i = 0; i < bankOfficers.size(); i++)
    {
        if (bankOfficers[i].getName() == name)
        {
            ret = bankOfficers[i].getAccounts();
            bankOfficers.erase(bankOfficers.begin() + i);
        }
    }

/*    for (vector<BankOfficer>::iterator it = bankOfficers.begin(); it != bankOfficers.end(); ++it)
    {
        if (it->getName() == name)
        {
            ret = it->getAccounts();
            bankOfficers.erase(it);
        }
    }*/
    return ret;
}


// a alterar
const BankOfficer & Bank::addAccountToBankOfficer(Account *ac, string name) {
    for (BankOfficer &bo : bankOfficers)
    {
        if (bo.getName() == name)
        {
            bo.addAccount(ac);
            return bo;
        }
    }
    throw NoBankOfficerException(name);
}


// a alterar
void Bank::sortAccounts() {
    for(unsigned int j=accounts.size()-1; j>0; j--) {
        bool troca = false;
        for (unsigned int i = 0; i < j; i++) {
            if (accounts[i + 1]->getBalance() < accounts[i]->getBalance()) {
                swap(accounts[i], accounts[i + 1]);
                troca = true;
            }
            if (accounts[i+1]->getBalance() == accounts[i]->getBalance())
            {
                if (accounts[i + 1] ->getCodIBAN() < accounts[i]->getCodIBAN())
                {
                    swap(accounts[i], accounts[i + 1]);
                    troca = true;
                }
            }

        }
        if (!troca) return;
    }
}

