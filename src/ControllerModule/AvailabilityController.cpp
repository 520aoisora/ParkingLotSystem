/*
 * AvailabilityController.cpp
 *
 *  Created on: 24 Sep 2017
 *      Author: Yi
 */

#include <iostream>
#include "ControllerModule/AvailabilityController.hpp"

namespace controller_module
{
	bool AvailabilityController::hasAvailability() const
	{
		std::cout << "Checking availability: " << (_availableSpaceCount>0) << "\n";
		return _availableSpaceCount > 0;
	}

	bool AvailabilityController::increaseCountBy1()
	{
		if(_availableSpaceCount == CAPACITY)
			return false;

		std::cout << "Increasing ASC by 1.\n";
		++_availableSpaceCount;
		return true;
	}

	bool AvailabilityController::decreaseCountBy1()
	{
		if(_availableSpaceCount == 0)
			return false;

		std::cout << "Decreasing ASC by 1.\n";
		--_availableSpaceCount;
		return true;
	}

	unsigned int AvailabilityController::getAvailableSpaceCount() const
	{
		return _availableSpaceCount;
	}
}
