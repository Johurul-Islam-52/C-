#ifndef BANK_H
#define BANK_H

#include <string>
#include "Customer.h"
#include "CurrentAccount.h"
#include "SavingsAccount.h"
#include "Colecao.h"

class Bank {
private:
    int bankId;
    std::string name;
    Colecao<Customer*> customers;

public:
    Bank(int id, const std::string& name);
    ~Bank();
    Customer* addCustomer(const std::string& name, const std::string& phone);
    CurrentAccount* createCurrentAccount(Customer* customer, double initialBalance, double creditLimit);
    SavingsAccount* createSavingsAccount(Customer* customer, double initialBalance, double interestRate);
    void printBankDetails() const;
};

#endif
