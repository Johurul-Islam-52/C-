#include <iostream>
#include "Bank.h"
#include "Customer.h"
#include "CurrentAccount.h"
#include "SavingsAccount.h"

int main() {
    Bank bank(343, "Banco Brigantino");

   
    Customer* customer1 = bank.addCustomer("Bruno Maga", "939514343");
    CurrentAccount* account1 = bank.createCurrentAccount(customer1, 17.93, -1200.00);
    account1->setNib(343, customer1->getId(), 1001);

    CurrentAccount* account2 = bank.createCurrentAccount(customer1, 303.02, 0.00);
    account2->setNib(343, customer1->getId(), 1002);

    Customer* customer2 = bank.addCustomer("Ana Borges", "929345411");
    CurrentAccount* account3 = bank.createCurrentAccount(customer2, 0.00, 900.00);
    account3->setNib(343, customer2->getId(), 1003);

    SavingsAccount* account4 = bank.createSavingsAccount(customer2, 6000.00, 0.05);
    account4->setNib(343, customer2->getId(), 1004);

   
    bank.printBankDetails();

    return 0;
}
