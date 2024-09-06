#ifndef CODE_HPP
#define CODE_HPP

#include <string>
#include <iostream>
#include <vector>

//to define the status code of any operation
enum class StatusCode {
    success,
    insufficientBalance,
    invalidAccount,
    invalidAmount,
    invalidPassword,
    weakPassword

};

class Account {
private:
    int accountNumber {};
    std::string accountHolderName {};
    double balance {};
    std::vector<double> transactionHistory {};
    std::string password {};

public:
    Account(int accNum, const std::string& accHolder, const std::string& pass);
    void updateTransactions(double amount);
    StatusCode deposit(double amount, const std::string& pass);
    StatusCode withdraw(double amount, const std::string& pass);
    StatusCode printBalance(const std::string& pass);
    StatusCode printTransactionHistory(const std::string& pass);

    friend class Bank;
};

class Bank {
private:
    std::vector<Account> accounts{};
    int nextAccountNumber{ 1000 };

public:

    bool passwordStrength(const std::string& pass);
    int getLastAccountNumber();
    StatusCode addAccount(const std::string& accHolder, const std::string& pass);
    StatusCode bankDeposit(int accNum, double amount, const std::string& pass);
    StatusCode bankWithdraw(int accNum, double amount, const std::string& pass);
    StatusCode balanceEnquiry(int accNum, const std::string& pass);
    StatusCode TransactionHistory(int accNum, const std::string& pass);


};

#endif //CODE_HPP
