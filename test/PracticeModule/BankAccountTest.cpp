/*
 * BankAccountTest.cpp
 *
 *  Created on: 23 Sep 2017
 *      Author: Yi
 */

#include "gtest/gtest.h"
#include "PracticeModule/BankAccount.hpp"

struct BankAccountState
{
	int initial_balance;
	int deposit_amount;
	int withdraw_amount;
	int final_balance;
	bool is_successful;

	friend std::ostream& operator<<(std::ostream& os, const BankAccountState& obj)
	{
		return os
				<< "initial_balance: " << obj.initial_balance
				<< ", deposit_amount: " << obj.deposit_amount
				<< ", withdraw_amount: " << obj.withdraw_amount
				<< ", final_balance: " << obj.final_balance
				<< ", is_successful: " << obj.is_successful;
	}
};

struct BankAccountTest : public testing::Test
{
	BankAccountTest() {}
	BankAccountTest(int initial_balance) : _ba(initial_balance) {};
	BankAccount _ba;
};

struct DepositWithdrawTest : public BankAccountTest,
									testing::WithParamInterface<BankAccountState>
{
	DepositWithdrawTest() : BankAccountTest(GetParam().initial_balance) {}
};

TEST_F(BankAccountTest, defaultValue)
{
	EXPECT_EQ(0, _ba.getBalance());
}

TEST_F(BankAccountTest, depositeMoney)
{
	_ba.deposit(100);
	EXPECT_EQ(100, _ba.getBalance());
}

TEST_P(DepositWithdrawTest, finalBalance)
{
	auto param = GetParam();

	_ba.deposit(param.deposit_amount);
	auto isSuccessful = _ba.withdraw(param.withdraw_amount);
	EXPECT_EQ(_ba.getBalance(), param.final_balance);
	EXPECT_EQ(isSuccessful, param.is_successful);
}

INSTANTIATE_TEST_CASE_P(Default, DepositWithdrawTest,
	testing::Values(
		BankAccountState{0,100,0,100,true},
		BankAccountState{100,100,0,200,true},
		BankAccountState{0,100,200,100,false}
	)
);
