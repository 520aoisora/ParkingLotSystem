/*
 * GateManager.cpp
 *
 *  Created on: 20 Sep 2017
 *      Author: Yi
 */

#include <iostream>
#include "GateModule/GateManager.hpp"

namespace gate_module
{
	void GateManager::openGate()
	{
		std::cout << "Gate is opening.\n";
		_isGateOpen = true;
	}

	void GateManager::closeGate()
	{
		std::cout << "Gate is closing.\n";
		_isGateOpen = false;
	}

	bool GateManager::isGateOpen() const
	{
		std::cout << "Gate is open now: " << _isGateOpen << std::endl;
		return _isGateOpen;
	}
}
