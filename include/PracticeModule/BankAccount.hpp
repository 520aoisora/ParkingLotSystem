/*
 * BankAccount.hpp
 *
 *  Created on: 23 Sep 2017
 *      Author: Yi
 */

#ifndef INCLUDE_PRACTICEMODULE_BANKACCOUNT_HPP_
#define INCLUDE_PRACTICEMODULE_BANKACCOUNT_HPP_

class BankAccount
{
public:
	BankAccount() {}
	BankAccount(int initial_balance) : _balance(initial_balance) {}
public:
	int getBalance() const;
	void deposit(int amount);
	bool withdraw(int amount);

private:
	int _balance = 0;
};

#endif /* INCLUDE_PRACTICEMODULE_BANKACCOUNT_HPP_ */
