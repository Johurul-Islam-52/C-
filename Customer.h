#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Account.h"
#include "Colecao.h"

class Customer {
private:
    static int idCounter;
    int id;
    std::string name;
    std::string phone;
    Colecao<Account*> accounts; 

public:
    Customer(const std::string& name, const std::string& phone);
    ~Customer();
    int getId() const;
    std::string getName() const;
    std::string getPhone() const;
    void addAccount(Account* account);
    std::string getCustomerDetails() const;
    const Colecao<Account*>& getAccounts() const;
};

#endif
