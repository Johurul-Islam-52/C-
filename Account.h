#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
protected:
    std::string nib;
    double balance;
    static int nibCounter; 

    static int sumDigits(const std::string& str);
    static int generateNIB(); 

public:
    Account(double initialBalance);
    virtual ~Account() {}
    std::string getNIB() const;
    double getBalance() const;
    void deposit(double amount);
    virtual bool withdraw(double amount) = 0; 
    virtual std::string getAccountDetails() const = 0;
    void setNib(int _bankId, int _clientId, int _accountId);
    bool validateNIB(const std::string& _nib);
};

#endif

