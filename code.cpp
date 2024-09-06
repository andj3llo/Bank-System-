#include "code.hpp"
#include <cctype> //For isupper and isdigit
#include <iostream>

//Had assistance From ChatGPT 
//

//Account Class
Account::Account(int accNum, const std::string& accHolder, const std::string& pass): accountNumber(accNum), accountHolderName(accHolder), password(pass) {
	balance = 0.0; //sets the balance equal to zero
	
}

void Account::updateTransactions(double amount) {
	transactionHistory.push_back(amount);
}

StatusCode Account::deposit(double amount, const std::string& pass) {
	if (pass != password) {
		return StatusCode::invalidPassword; //if the password is not right it will tell the user the password is wrong
	}
	if (amount <= 0) {
		return StatusCode::invalidAmount; //If the amount is 0 or neative it says the amount is invalid
	}
	balance = balance + amount; 
	updateTransactions(amount); //adds the deposited amount to the transaction history
	return StatusCode::success;
}

StatusCode Account::withdraw(double amount, const std::string& pass) {
	if (pass != password) {
		return StatusCode::invalidPassword;
	}
	if (amount <= 0) {
		return StatusCode::invalidAmount; //If the amount is 0 or neative it says the amount is invalid
	}
	if (amount > balance) {
		return StatusCode::insufficientBalance;
	}

	balance = balance - amount;
	updateTransactions(-amount);
	return StatusCode::success;
}

StatusCode Account::printBalance(const std::string& pass) {
	if (pass != password) {
		return StatusCode::invalidPassword;
	}
	std::cout << "Balance for Account Number " << accountNumber << ": $" << balance << '\n';
	return StatusCode::success;
}
//BankSystem Class
StatusCode Account::printTransactionHistory(const std::string& pass) {
	if (pass != password) {
		return StatusCode::invalidPassword;
	}
	std::cout << "Transaction History for Account Number " << accountNumber << ":" << '\n';
	for (auto money = transactionHistory.rbegin(); money != transactionHistory.rend(); money++) {
		std::cout << *money << "\t";
	}
	std::cout << '\n';
	return StatusCode::success;
}

bool Bank::passwordStrength(const std::string& pass) {
	bool hasAUppercase = false; //sets each necessary requirement equal to false initially
	bool hasADigit = false;
	bool hasASpecialChar = false;

	for (char p : pass) {
		if (isupper(p)) {
			hasAUppercase = true;
		}
		else if (isdigit(p)) {
			hasADigit = true;
		}
		else if (p == '@' || p == '#' || p == '$' || p == '%') {
			hasASpecialChar = true;
		}
	}
	return (pass.length() >= 7 && hasAUppercase && hasADigit && hasASpecialChar); //checks if the password is longer than 7 and meets every other requirement
	//will return true or false
}

int Bank::getLastAccountNumber() {
	if (accounts.empty()) {
		return -1;
	}

	return accounts.back().accountNumber;
}

StatusCode Bank::addAccount(const std::string& accHolder, const std::string& pass) {
	if (!passwordStrength(pass)) {
		return StatusCode::weakPassword;
	}

	accounts.emplace_back(nextAccountNumber++, accHolder, pass);

	std::cout << "The Bank Account for " << accHolder << " created! Account Number: " << nextAccountNumber - 1 << '\n';
	return StatusCode::success;
}

StatusCode Bank::bankDeposit(int accNum, double amount, const std::string& pass) {
	for (int i = 0; i < accounts.size(); i++) { //goes through all of the accounts that the bank has and tries to find a match, when it matches it then it will print out their tractiontion history using their password
		if (accounts[i].accountNumber == accNum) {
			return accounts[i].deposit(amount, pass);
		}
	}

	return StatusCode::invalidAccount;
}

StatusCode Bank::bankWithdraw(int accNum, double amount, const std::string& pass) {
	for (int i = 0; i < accounts.size(); i++) { //goes through all of the accounts that the bank has and tries to find a match, when it matches it then it will print out their tractiontion history using their password
		if (accounts[i].accountNumber == accNum) {
			return accounts[i].withdraw(amount, pass);
		}
	}

	return StatusCode::invalidAccount;
}

StatusCode Bank::balanceEnquiry(int accNum, const std::string& pass) {
	for (int i = 0; i < accounts.size(); i++) { //goes through all of the accounts that the bank has and tries to find a match, when it matches it then it will print out their balance using their password
		if (accounts[i].accountNumber == accNum) {
			return accounts[i].printBalance(pass);
		}
	}

	return StatusCode::invalidAccount;

}

StatusCode Bank::TransactionHistory(int accNum, const std::string& pass) {
	for (int i = 0; i < accounts.size(); i++) { //goes through all of the accounts that the bank has and tries to find a match, when it matches it then it will print out their tractiontion history using their password
		if (accounts[i].accountNumber == accNum) {
			return accounts[i].printTransactionHistory(pass);
		}
	}
	return StatusCode::invalidAccount;
}













