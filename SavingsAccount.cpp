#include "SavingsAccount.h"
#include <sstream>
#include <iomanip>

SavingsAccount::SavingsAccount(double initialBalance, double interestRate)
    : Account(initialBalance), interestRate(interestRate) {}

bool SavingsAccount::withdraw(double amount) {
    
    return false;
}

std::string SavingsAccount::getAccountDetails() const {
    std::ostringstream oss;
    oss << "\tSaving:\n"
        << "\t\t-NIB: " << getNIB() << "\n"
        << "\t\t Balance: " << std::fixed << std::setprecision(2) << balance << " EUR (Interest rate: " << interestRate * 100 << "%)";
    return oss.str();
}
