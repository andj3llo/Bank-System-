#include "code.hpp"
#include <iostream>

int main()
{
    //DO NOT MODIFY ANYTHING HERE

    Bank bank;
    StatusCode status;

    // Adding accounts
    std::vector<std::string> names = { "Alice", "Bob", "Charlie", "Adam" };
    std::vector<std::string> password = { "Strong@123", "Password#123", "Secure#123", "Weak" };

    for (size_t i = 0; i < names.size(); ++i) {

        status = bank.addAccount(names[i], password[i]);

        if (status == StatusCode::success) {

            std::cout << "Bank Account for " << names[i] << " created! Account Number: " << bank.getLastAccountNumber() << std::endl;
        }

        else if (status == StatusCode::weakPassword) {

            std::cout << "Bank Account for " << names[i] << " can not be created- Weak Password" << std::endl;
        }

    }

    std::cout << std::endl;

    // Depositing
    bank.bankDeposit(1000, 1000, "Strong@123");
    bank.bankDeposit(1001, 100, "Password#123");
    bank.bankDeposit(1002, 500, "Secure#123");


    // Withdrawal
    bank.bankWithdraw(1000, 500, "Strong@123");
    bank.bankWithdraw(1002, 100, "Secure#123");

    // Balance enquiry
    bank.balanceEnquiry(1000, "Strong@123");
    bank.balanceEnquiry(1002, "Secure#123");
    std::cout << std::endl;

    // Printing transaction history
    bank.TransactionHistory(1000, "Strong@123");
    bank.TransactionHistory(1002, "Secure#123");

    return 0;
}
