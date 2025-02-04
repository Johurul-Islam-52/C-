#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(double initialBalance, double interestRate);
    bool withdraw(double amount) override; 
    std::string getAccountDetails() const override;
};

#endif
