/*
 * AvailabilityControllerTest.cpp
 *
 *  Created on: 24 Sep 2017
 *      Author: Yi
 */

#include "gtest/gtest.h"
#include "ControllerModule/AvailabilityController.hpp"

class ControllerModuleTest : public ::testing::Test
{
public:
	ControllerModuleTest() {}
	explicit ControllerModuleTest(const unsigned int& initialASC) : _ac(initialASC) {}
protected:
	controller_module::AvailabilityController	_ac;
};

TEST_F(ControllerModuleTest, defaultASC)
{
	EXPECT_EQ(100U, _ac.getAvailableSpaceCount());
}

struct TestOperation
{
	unsigned int initialASC;
	unsigned int increaseTimes;
	bool isIncreaseSuccessful;
	unsigned int decreaseTimes;
	bool isDecreaseSuccessful;
	unsigned int finalASC;

	friend std::ostream& operator<<(std::ostream& os, const TestOperation& obj)
	{
		return os
			<< "initialASC: " << obj.initialASC
			<< ", increaseTimes: " << obj.increaseTimes
			<< ", isIncreaseSuccessful: " << obj.isIncreaseSuccessful
			<< ", decreaseTimes: " << obj.decreaseTimes
			<< ", isDecreaseSuccessful: " << obj.isDecreaseSuccessful
			<< ", finalASC: " << obj.finalASC;
	}
};

class ControllerModuleTestSet : public ControllerModuleTest,
		 						public ::testing::WithParamInterface<TestOperation>
{
public:
	ControllerModuleTestSet() : ControllerModuleTest(GetParam().initialASC) {}
};

TEST_P(ControllerModuleTestSet, testSet)
{
	auto param = GetParam();
	EXPECT_EQ(param.initialASC, _ac.getAvailableSpaceCount());

	const auto& increaseTimes = param.increaseTimes;
	bool isIncreaseSuccessful = true;
	for(auto i=0U; isIncreaseSuccessful && i<increaseTimes; ++i)
		isIncreaseSuccessful = _ac.increaseCountBy1();
	EXPECT_EQ(param.isIncreaseSuccessful, isIncreaseSuccessful);

	const auto& decreaseTimes = param.decreaseTimes;
	bool isDecreaseSuccessful = true;
	for(auto i=0U; isDecreaseSuccessful && i<decreaseTimes; ++i)
		isDecreaseSuccessful = _ac.decreaseCountBy1();
	EXPECT_EQ(param.isDecreaseSuccessful, isDecreaseSuccessful);

	EXPECT_EQ(param.finalASC, _ac.getAvailableSpaceCount());
}

INSTANTIATE_TEST_CASE_P(Default, ControllerModuleTestSet,
	testing::Values(
		TestOperation{0,10,true,0,true,10},
		TestOperation{100,1,false,0,true,100},
		TestOperation{0,0,true,1,false,0},
		TestOperation{50,10,true,25,true,35}
	)
);
