/*
 * BankAccount.cpp
 *
 *  Created on: 23 Sep 2017
 *      Author: Yi
 */

#include "PracticeModule/BankAccount.hpp"

int BankAccount::getBalance() const {
	return _balance;
}

void BankAccount::deposit(int amount) {
	_balance += amount;
}

bool BankAccount::withdraw(int amount) {
	if(amount > _balance)
		return false;
	_balance -= amount;
	return true;
}
