/*
 * GateManagerTest.cpp
 *
 *  Created on: 20 Sep 2017
 *      Author: Yi
 */

#include "gtest/gtest.h"
#include "GateModule/GateManager.hpp"

class GateManagerTest : public ::testing::Test
{
protected:
	gate_module::GateManager	_gm;
};

TEST_F(GateManagerTest, defaultStatus)
{
	EXPECT_EQ(false, _gm.isGateOpen());
}

TEST_F(GateManagerTest, openGate)
{
	_gm.openGate();
	EXPECT_EQ(true, _gm.isGateOpen());
}

TEST_F(GateManagerTest, closeGate)
{
	_gm.closeGate();
	EXPECT_EQ(false, _gm.isGateOpen());
}

TEST_F(GateManagerTest, openAndCloseGate)
{
	_gm.openGate();
	EXPECT_EQ(true, _gm.isGateOpen());
	_gm.closeGate();
	EXPECT_EQ(false, _gm.isGateOpen());
}

TEST_F(GateManagerTest, closeAndOpenGate)
{
	_gm.closeGate();
	EXPECT_EQ(false, _gm.isGateOpen());
	_gm.openGate();
	EXPECT_EQ(true, _gm.isGateOpen());
}

TEST_F(GateManagerTest, doubleOpenGate)
{
	_gm.openGate();
	EXPECT_EQ(true, _gm.isGateOpen());
	_gm.openGate();
	EXPECT_EQ(true, _gm.isGateOpen());
}

TEST_F(GateManagerTest, doubleCloseGate)
{
	_gm.closeGate();
	EXPECT_EQ(false, _gm.isGateOpen());
	_gm.closeGate();
	EXPECT_EQ(false, _gm.isGateOpen());
}
