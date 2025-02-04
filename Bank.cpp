#include "Bank.h"
#include <iostream>

Bank::Bank(int id, const std::string& name) : bankId(id), name(name) {}

Bank::~Bank() {
    for (Customer* customer : customers) {
        delete customer;
    }
}

Customer* Bank::addCustomer(const std::string& name, const std::string& phone) {
    Customer* customer = new Customer(name, phone);
    customers.insert(customer);
    return customer;
}

CurrentAccount* Bank::createCurrentAccount(Customer* customer, double initialBalance, double creditLimit) {
    CurrentAccount* account = new CurrentAccount(initialBalance, creditLimit);
    account->setNib(bankId, customer->getId(), customer->getAccounts().size() + 1);
    customer->addAccount(account);
    return account;
}

SavingsAccount* Bank::createSavingsAccount(Customer* customer, double initialBalance, double interestRate) {
    SavingsAccount* account = new SavingsAccount(initialBalance, interestRate);
    account->setNib(bankId, customer->getId(), customer->getAccounts().size() + 1);
    customer->addAccount(account);
    return account;
}

void Bank::printBankDetails() const {
    std::cout << "bankId: " << bankId << "\n"
        << "Name: " << name << "\n"
        << "--------\n";
    for (const Customer* customer : customers) {
        std::cout << customer->getCustomerDetails() << "\n";
    }
}
