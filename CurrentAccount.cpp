#include "CurrentAccount.h"
#include <sstream>
#include <iomanip>

CurrentAccount::CurrentAccount(double initialBalance, double creditLimit)
    : Account(initialBalance), creditLimit(creditLimit) {}

bool CurrentAccount::withdraw(double amount) {
    if (balance - amount >= -creditLimit) {
        balance -= amount;
        return true;
    }
    return false;
}

std::string CurrentAccount::getAccountDetails() const {
    std::ostringstream oss;
    oss << "\tCurrent:\n"
        << "\t\t-NIB: " << getNIB() << "\n"
        << "\t\t Balance: " << std::fixed << std::setprecision(2) << balance << " EUR (min.: " << creditLimit << " EUR)";
    return oss.str();
}
