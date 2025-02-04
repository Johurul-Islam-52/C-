#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include "Account.h"

class CurrentAccount : public Account {
private:
    double creditLimit;

public:
    CurrentAccount(double initialBalance, double creditLimit);
    bool withdraw(double amount) override;
    std::string getAccountDetails() const override;
};

#endif
