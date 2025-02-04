#include "Account.h"
#include <iomanip>
#include <sstream>
#include <cctype>
#include <cstdio>

int Account::nibCounter = 100014; 

int Account::generateNIB() {
    return ++nibCounter;
}

bool Account::validateNIB(const std::string& _nib) {
    return (sumDigits(_nib) - (_nib[11] - '0')) % 9 + 1 == _nib[11] - '0'; 
}

int Account::sumDigits(const std::string& str) {
    int sum = 0;
    for (char c : str) {
        if (isdigit(c)) {
            sum += c - '0';
        }
    }
    return sum;
}

Account::Account(double initialBalance) : balance(initialBalance) {}

std::string Account::getNIB() const {
    return nib;
}

double Account::getBalance() const {
    return balance;
}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}

void Account::setNib(int _bankId, int _clientId, int _accountId) {
    char _nib[13]; 
    snprintf(_nib, sizeof(_nib), "%04d%04d%04d", _bankId, _clientId, _accountId);
    _nib[11] = static_cast<char>((sumDigits(_nib) % 9 + 1) + '0');
    _nib[12] = '\0'; 
    nib = std::string(_nib); 
}


