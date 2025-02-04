#include "Customer.h"
#include <sstream>

int Customer::idCounter = 0;

Customer::Customer(const std::string& name, const std::string& phone) : name(name), phone(phone) {
    id = ++idCounter;
}

Customer::~Customer() {
    for (Account* account : accounts)
        delete account;
}

int Customer::getId() const {
    return id;
}

std::string Customer::getName() const {
    return name;
}

std::string Customer::getPhone() const {
    return phone;
}

void Customer::addAccount(Account* account) {
    accounts.insert(account);
}

std::string Customer::getCustomerDetails() const {
    std::ostringstream oss;
    oss << "clientId: " << id << "\n"
        << "Name: " << name << "\n"
        << "Mobile: " << phone << "\n"
        << "Accounts:\n";
    for (const Account* account : accounts) {
        oss << account->getAccountDetails() << "\n";
    }
    return oss.str();
}

const Colecao<Account*>& Customer::getAccounts() const {
    return accounts;
}
